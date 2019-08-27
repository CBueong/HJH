#include "pch.h"
#include "GameManager.h"

#include "Pointer.h"
#include "Mine.h"
#include "Block.h"

GameManager::~GameManager() {

	SAFE_DELETE(MyPointer);

	for (auto r : Blocks) { SAFE_DELETE(r); }
	for (auto r : Mines) { SAFE_DELETE(r); }

	Blocks.clear();
	Mines.clear();


	for (int y = 0; y < s; ++y) {
		SAFE_DELETE_ARR(Map[y]);

	}
	SAFE_DELETE_ARR(Map);

	for (int y = 0; y < s; ++y) {
		SAFE_DELETE_ARR(ObjState[y]);
	}
	SAFE_DELETE_ARR(ObjState);

}

void GameManager::Init() {
	srand(time(NULL));
	start = clock();

	Draw(CONSOLE_X / 2 - 6, dY - 5, "A : Sellect");
	Draw(CONSOLE_X / 2 - 6, dY - 4, "F : Flag");

	// 맵에 타입을 다 집어넣자 (Mine과 Block)
	Map = new eType*[s];
	for (int i = 0; i < s; ++i) {
		Map[i] = new eType[s];
	}
	// Mine과 Block의 상태도 다른 곳에 집어넣자
	ObjState = new eState*[s];
	for (int i = 0; i < s; ++i) {
		ObjState[i] = new eState[s];
	}


	for (int y = 0; y < s; ++y) {
		for (int x = 0; x < s; ++x) {
			// 랜덤으로 블록과 마인 생성해서 집어넣기
			float r = (float)rand() / (float)RAND_MAX;
			if (r > 0.15f) {
				Block* pTemp = new Block(x, y, eType::Block);
				Blocks.push_back(pTemp);
				pTemp = nullptr;
				// 타입과
				Map[y][x] = eType::Block;
				// 상태
				ObjState[y][x] = eState::None;
			}
			else {
				Mine* pTemp = new Mine(x, y, eType::Mine);
				Mines.push_back(pTemp);
				pTemp = nullptr;
				Map[y][x] = eType::Mine;
				ObjState[y][x] = eState::None;
			}
		}
	}

	// 내 포인터 중간에 생성
	MyPointer = new Pointer(s / 2 - 1, s / 2 - 1, eType::Pointer);


	// 시작할 때 한번 다 그려놓자
	Draw(dX + MyPointer->GetPos().X * 2, dY + MyPointer->GetPos().Y, "▲");

	for (int y = 0; y < s; ++y) {
		for (int x = 0; x < s; ++x) {
			if (x != MyPointer->GetPos().X || y != MyPointer->GetPos().Y) {
				RenderByType(x, y);
			}
		}
	}
}

void GameManager::Update(float a_fDeltaTime)
{
	MyPointer->NowTerm += a_fDeltaTime;

	// 포인터 움직이는 거
	if (MyPointer->NowTerm > MyPointer->TargetTerm) {

		MyPointer->NowTerm -= MyPointer->TargetTerm;

		int x = MyPointer->GetPos().X;
		int y = MyPointer->GetPos().Y;

		char c = GetKeyInput();

		switch ((eKey)c)
		{
		case eKey::Up:		--y;	break;
		case eKey::Down:	++y;	break;
		case eKey::Left:	--x;	break;
		case eKey::Right:	++x;	break;
		case eKey::Select:

			// A 키를 눌렀는데

			// Block이면 Interact하고 상태 갱신
			for (auto r : Blocks) {
				if (r->IsCrossed(x, y) == true) {
					r->Interact(MyPointer);
					ObjState[r->GetPos().Y][r->GetPos().X] = r->state;
					break;
				}
			}

			// Mine이면 Interact하고 상태 갱신
			for (auto r : Mines) {
				if (r->IsCrossed(x, y) == true) {
					r->Interact(MyPointer);
					ObjState[r->GetPos().Y][r->GetPos().X] = r->state;
					break;
				}
			}

			break;


		case eKey::Flag:

			// F 키를 눌렀는데

			// Block이든 Mine이든 상태 변환하는데, Flag 상태에서 다시 돌려주기도 해야함
			// 굳이 두 개 나눠서 작성해야 하나 싶긴 하지만... 나눠서 관리하기로 했으니...
			for (auto r : Blocks) {
				if (r->IsCrossed(x, y) == true) {
					if (r->state == eState::None) {
						r->state = eState::Flagged;
						ObjState[r->GetPos().Y][r->GetPos().X] = eState::Flagged;
						break;
					}
					else if (r->state == eState::Flagged) {
						r->state = eState::None;
						ObjState[r->GetPos().Y][r->GetPos().X] = eState::None;
						break;
					}
				}
			}
			for (auto r : Mines) {
				if (r->IsCrossed(x, y) == true) {
					if (r->state == eState::None) {
						r->state = eState::Flagged;
						ObjState[r->GetPos().Y][r->GetPos().X] = eState::Flagged;
						break;
					}
					else if (r->state == eState::Flagged) {
						r->state = eState::None;
						ObjState[r->GetPos().Y][r->GetPos().X] = eState::None;
						break;
					}
				}
			}
			break;
		}


		// 맵 넘어가지 마
		if ((0 > x || s <= x) || (0 > y || s <= y)) { MyPointer->bMove = false; }

		// 움직일 수 있으면 움직여라
		if (MyPointer->bMove == true) {

			// 전 자리에 맵 그리고
			RenderByType(MyPointer->GetPos().X, MyPointer->GetPos().Y);

			// 움직인 뒤
			MyPointer->MoveTo(x, y);

			// 움직인 자리에 포인터 그려
			Draw(dX + MyPointer->GetPos().X * 2, dY + MyPointer->GetPos().Y, "▲");

		}


		MyPointer->bMove = true;
	}


	// Block 다 눌렸는지 체크하기 위한 count
	int cnt = 0;
	for (auto r : Blocks) {
		// Pushed인 거 체크해서
		if (r->state == eState::Pushed) {
			++cnt;
		}
	}
	// 다 Pushed면 승리
	if (cnt == Blocks.size()) {
		bFinish = true;
	}

	// 마인 밟거나 승리하면
	if (MyPointer->bAlive == false || bFinish == true) {

		// 마인 위치 다 보여줘
		for (auto r : Mines) {
			r->state = eState::Pushed;
			ObjState[r->GetPos().Y][r->GetPos().X] = r->state;
			RenderByType(r->GetPos().X, r->GetPos().Y);
		}
		delay(2000);
		// 그리고 끝 -> 어차피 bFinish가 true이면 bOver 체크 안함
		bOver = true;
	}


}

void GameManager::Render()
{

	// 그냥 위치 체크
	gotoxy(1, 1);
	cout << MyPointer->GetPos().X << " " << MyPointer->GetPos().Y;

	// 남은 Block 개수 보여주기
	int cnt = 0;
	for (auto r : Blocks) {
		if (r->state == eState::Pushed) {
			++cnt;
		}
	}
	gotoxy(CONSOLE_X / 2 - 6, dY - 3);
	cout << "남은 블럭 숫자 : " << Blocks.size() - cnt << "      ";
	gotoxy(CONSOLE_X / 2 - 6, dY - 2);
	cout << "경과 시간 : " << (clock() - start) / 1000 << "초  ";
}

void GameManager::KeyInput() {
}

// 그리기 함수
void GameManager::Draw(int x, int y, const char* c) {
	gotoxy(x, y);
	cout << c;
}

// 그리기 함수 활용
void GameManager::Clear(int x, int y) {
	Draw(x, y, " ");
}

bool GameManager::GetOverState() { return bOver; }


// 타입 따라서 그리기
void GameManager::RenderByType(int x, int y) {
	gotoxy(dX + x * 2, dY + y);
	if (Map[y][x] == eType::Block) {
		switch (ObjState[y][x])
		{
		case eState::None:
			cout << "■";
			break;
		case eState::Pushed:
			for (auto r : Blocks) {
				if (r->IsCrossed(x, y) == true) {
					switch (r->MineCnt)
					{
					case 0: cout << "□"; break;
					case 1: cout << "①"; break;
					case 2: cout << "②"; break;
					case 3: cout << "③"; break;
					case 4: cout << "④"; break;
					case 5: cout << "⑤"; break;
					case 6: cout << "⑥"; break;
					case 7: cout << "⑦"; break;
					case 8: cout << "⑧"; break;
					default: cout << "  "; break;
					}
					break;
				}
			}
			break;
		case eState::Flagged:
			cout << "※";
			break;
		}

	}
	else if (Map[y][x] == eType::Mine) {
		switch (ObjState[y][x])
		{
		case eState::None:
			//cout << "★";
			cout << "■";
			break;
		case eState::Pushed:
			cout << "★";
			break;
		case eState::Flagged:
			cout << "※";
			break;
		}
	}
}