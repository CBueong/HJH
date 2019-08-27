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

	// �ʿ� Ÿ���� �� ������� (Mine�� Block)
	Map = new eType*[s];
	for (int i = 0; i < s; ++i) {
		Map[i] = new eType[s];
	}
	// Mine�� Block�� ���µ� �ٸ� ���� �������
	ObjState = new eState*[s];
	for (int i = 0; i < s; ++i) {
		ObjState[i] = new eState[s];
	}


	for (int y = 0; y < s; ++y) {
		for (int x = 0; x < s; ++x) {
			// �������� ��ϰ� ���� �����ؼ� ����ֱ�
			float r = (float)rand() / (float)RAND_MAX;
			if (r > 0.15f) {
				Block* pTemp = new Block(x, y, eType::Block);
				Blocks.push_back(pTemp);
				pTemp = nullptr;
				// Ÿ�԰�
				Map[y][x] = eType::Block;
				// ����
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

	// �� ������ �߰��� ����
	MyPointer = new Pointer(s / 2 - 1, s / 2 - 1, eType::Pointer);


	// ������ �� �ѹ� �� �׷�����
	Draw(dX + MyPointer->GetPos().X * 2, dY + MyPointer->GetPos().Y, "��");

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

	// ������ �����̴� ��
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

			// A Ű�� �����µ�

			// Block�̸� Interact�ϰ� ���� ����
			for (auto r : Blocks) {
				if (r->IsCrossed(x, y) == true) {
					r->Interact(MyPointer);
					ObjState[r->GetPos().Y][r->GetPos().X] = r->state;
					break;
				}
			}

			// Mine�̸� Interact�ϰ� ���� ����
			for (auto r : Mines) {
				if (r->IsCrossed(x, y) == true) {
					r->Interact(MyPointer);
					ObjState[r->GetPos().Y][r->GetPos().X] = r->state;
					break;
				}
			}

			break;


		case eKey::Flag:

			// F Ű�� �����µ�

			// Block�̵� Mine�̵� ���� ��ȯ�ϴµ�, Flag ���¿��� �ٽ� �����ֱ⵵ �ؾ���
			// ���� �� �� ������ �ۼ��ؾ� �ϳ� �ͱ� ������... ������ �����ϱ�� ������...
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


		// �� �Ѿ�� ��
		if ((0 > x || s <= x) || (0 > y || s <= y)) { MyPointer->bMove = false; }

		// ������ �� ������ ��������
		if (MyPointer->bMove == true) {

			// �� �ڸ��� �� �׸���
			RenderByType(MyPointer->GetPos().X, MyPointer->GetPos().Y);

			// ������ ��
			MyPointer->MoveTo(x, y);

			// ������ �ڸ��� ������ �׷�
			Draw(dX + MyPointer->GetPos().X * 2, dY + MyPointer->GetPos().Y, "��");

		}


		MyPointer->bMove = true;
	}


	// Block �� ���ȴ��� üũ�ϱ� ���� count
	int cnt = 0;
	for (auto r : Blocks) {
		// Pushed�� �� üũ�ؼ�
		if (r->state == eState::Pushed) {
			++cnt;
		}
	}
	// �� Pushed�� �¸�
	if (cnt == Blocks.size()) {
		bFinish = true;
	}

	// ���� ��ų� �¸��ϸ�
	if (MyPointer->bAlive == false || bFinish == true) {

		// ���� ��ġ �� ������
		for (auto r : Mines) {
			r->state = eState::Pushed;
			ObjState[r->GetPos().Y][r->GetPos().X] = r->state;
			RenderByType(r->GetPos().X, r->GetPos().Y);
		}
		delay(2000);
		// �׸��� �� -> ������ bFinish�� true�̸� bOver üũ ����
		bOver = true;
	}


}

void GameManager::Render()
{

	// �׳� ��ġ üũ
	gotoxy(1, 1);
	cout << MyPointer->GetPos().X << " " << MyPointer->GetPos().Y;

	// ���� Block ���� �����ֱ�
	int cnt = 0;
	for (auto r : Blocks) {
		if (r->state == eState::Pushed) {
			++cnt;
		}
	}
	gotoxy(CONSOLE_X / 2 - 6, dY - 3);
	cout << "���� �� ���� : " << Blocks.size() - cnt << "      ";
	gotoxy(CONSOLE_X / 2 - 6, dY - 2);
	cout << "��� �ð� : " << (clock() - start) / 1000 << "��  ";
}

void GameManager::KeyInput() {
}

// �׸��� �Լ�
void GameManager::Draw(int x, int y, const char* c) {
	gotoxy(x, y);
	cout << c;
}

// �׸��� �Լ� Ȱ��
void GameManager::Clear(int x, int y) {
	Draw(x, y, " ");
}

bool GameManager::GetOverState() { return bOver; }


// Ÿ�� ���� �׸���
void GameManager::RenderByType(int x, int y) {
	gotoxy(dX + x * 2, dY + y);
	if (Map[y][x] == eType::Block) {
		switch (ObjState[y][x])
		{
		case eState::None:
			cout << "��";
			break;
		case eState::Pushed:
			for (auto r : Blocks) {
				if (r->IsCrossed(x, y) == true) {
					switch (r->MineCnt)
					{
					case 0: cout << "��"; break;
					case 1: cout << "��"; break;
					case 2: cout << "��"; break;
					case 3: cout << "��"; break;
					case 4: cout << "��"; break;
					case 5: cout << "��"; break;
					case 6: cout << "��"; break;
					case 7: cout << "��"; break;
					case 8: cout << "��"; break;
					default: cout << "  "; break;
					}
					break;
				}
			}
			break;
		case eState::Flagged:
			cout << "��";
			break;
		}

	}
	else if (Map[y][x] == eType::Mine) {
		switch (ObjState[y][x])
		{
		case eState::None:
			//cout << "��";
			cout << "��";
			break;
		case eState::Pushed:
			cout << "��";
			break;
		case eState::Flagged:
			cout << "��";
			break;
		}
	}
}