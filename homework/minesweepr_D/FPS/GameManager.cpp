#include "pch.h"
#include "GameManager.h"

#include "Cell.h"

GameManager::GameManager() {}
GameManager::~GameManager()
{
	Release();
}

void GameManager::GameInit(FieldInfo a_FieldInfo)
{
	m_FieldInfo.Field_X = a_FieldInfo.Field_X;
	m_FieldInfo.Field_Y = a_FieldInfo.Field_Y;
	m_FieldInfo.Mines = a_FieldInfo.Mines;
}

void GameManager::Init()
{
	Enable_MouseInput();

	MineNum = m_FieldInfo.Mines;
	FlagNum = m_FieldInfo.Mines;
	MaxCellCount = m_FieldInfo.Field_X * m_FieldInfo.Field_Y;
	CellMaker();
}

void GameManager::Update(float a_fDeltatime)
{
	//int event;        // 마우스 이벤트에 이용
	int x = 0;            // 마우스의 x좌표 저장소
	int y = 0;            // 마우스의 y좌표 저장소

	if (SceneMng()->GetKeyState(eKey::Fire) == eInputState::Press) {		
		Release();
		SceneMng()->ChangeScene(eScene::Intro);
	}
	else if (SceneMng()->GetKeyState(eKey::SPACE) == eInputState::Press) {		
		Release();
		Init();
	}


	if (GameOver == true || IsClear() == true) { 
		Disable_MoustInput();
		return; 
	}

	Timer += a_fDeltatime;	

	if (be_input())
	{
		if (get_input(&key, &pos) != 0)
		{
			MOUSE_EVENT;
			x = pos.X;    // 마우스 클릭이 된 좌표값을 저장
			y = pos.Y;

			for (auto* cell : m_vcCell) {
				if ((cell->GetCellCoord().x1 == x || cell->GetCellCoord().x2 == x) &&
					cell->GetCellCoord().y == y) {
					if (key == LEFT_CLICK && cell->SafetyFlag == false) {
						if (cell->m_CellType == CellType::Mine) {
							GameOver = true;
						}
						else if (cell->m_CellType == CellType::Normal && cell->NearbyMines == 0) {
							CheckNearbyCell(cell);
						}
						cell->OpenCell();
						SafetyCellCount++;
					}
					else if (key == RIGHT_CLICK && cell->m_CellState != CellState::eOpen) {
						cell->ToggleFlag() ? --FlagNum : ++FlagNum;
					}
				}
			}
		}
	}	
}

void GameManager::Render()
{
	SetCursor(m_FieldInfo.Field_X*2-3, 0);
	cout << (int)Timer << "  ";

	SetCursor(3, 0);
	cout << FlagNum << "  ";
	
	int index;
	for (size_t y = 0; y < m_FieldInfo.Field_Y; y++) {
		SetCursor(1, y+1);
		for (size_t x = 0; x < m_FieldInfo.Field_X; x++) {
			index = y * m_FieldInfo.Field_X + x;
			m_vcCell[index]->Render();
		}
	}
	
	if (GameOver == true) {
		for (auto* cell : m_vcCell) {
			if (cell->m_CellType == CellType::Mine) {
				cell->SafetyFlag = false;
				cell->OpenCell();
			}
		}

		SetCursor(m_FieldInfo.Field_X * 2 + 5, 2);
		cout << "당신은 지뢰를 밟았습니다.";

	}
	if (IsClear() == true) {
		SetCursor(m_FieldInfo.Field_X * 2 + 5, 2);
		cout << "축하합니다 모든 지뢰를 찾았습니다.";
		
	}

	SetCursor(m_FieldInfo.Field_X * 2 + 5,  3);
	cout << "다시 시작하시려면 SPACEBAR 를 누르세요.";
	SetCursor(m_FieldInfo.Field_X * 2 + 5, 5);
	cout << "메뉴로 돌아가시려면 F 를 누르세요.";
}

void GameManager::Release()
{
	system("cls");
	Timer = 0;
	MineNum = 0;
	FlagNum = 0;
	MakeMineCell = 0;
	MaxCellCount = 0;
	SafetyCellCount = 0;
	FlagCellCount = 0;
	GameOver = false;

	Disable_MoustInput();

	for (auto* val : m_vcCell) {
		SAFE_DELETE(val);
	}

	m_vcCell.clear();
}

void GameManager::CellMaker()
{
	int Random;

	for (size_t y = 1; y <= m_FieldInfo.Field_Y; y++) {
		for (size_t x = 1; x <= m_FieldInfo.Field_X*2; x+=2) {
			m_vcCell.push_back(new Cell(x, y, CellType::Normal));
		}
	}

	while (MineNum > MakeMineCell) {
		Random = rand() % MaxCellCount;

		if (m_vcCell[Random]->m_CellType == CellType::Normal) {
			m_vcCell[Random]->m_CellType = CellType::Mine;
			MakeMineCell++;
		}		
	}

	for (int i = 0; i < m_vcCell.size(); i++) {
		if (m_vcCell[i]->m_CellType == CellType::Normal) {
			m_vcCell[i]->NearbyMines = CheckNearbyMines(m_vcCell[i]);
		}	
	}
}

int GameManager::CheckNearbyMines(class Cell* a_Cell)
{
	int mines = 0;	
	int tempX = a_Cell->GetCellCoord().x1;
	int tempY = a_Cell->GetCellCoord().y;

	int x[8] = { tempX + 2, tempX, tempX - 2, tempX + 2, tempX - 2, tempX + 2, tempX, tempX - 2 };
	int y[8] = { tempY + 1, tempY + 1, tempY + 1, tempY, tempY, tempY - 1, tempY - 1, tempY - 1 };

	for (int i = 0; i < m_vcCell.size(); i++) {
		for (int index = 0; index < 8; index++) {
			if (m_vcCell[i]->GetCellCoord().x1 == x[index] && m_vcCell[i]->GetCellCoord().y == y[index]) {
				if (m_vcCell[i]->m_CellType == CellType::Mine) { mines++; }
			}
		}
	}

	return mines;
}

void GameManager::CheckNearbyCell(class Cell* a_Cell)
{
	int tempX = a_Cell->GetCellCoord().x1;
	int tempY = a_Cell->GetCellCoord().y;

	int x[8] = { tempX + 2, tempX, tempX - 2, tempX + 2, tempX - 2, tempX + 2, tempX, tempX - 2 };
	int y[8] = { tempY + 1, tempY + 1, tempY + 1, tempY, tempY, tempY - 1, tempY - 1, tempY - 1 };

	for (int i = 0; i < m_vcCell.size(); i++) {
		for (int index = 0; index < 8; index++) {
			if (m_vcCell[i]->GetCellCoord().x1 == x[index] && m_vcCell[i]->GetCellCoord().y == y[index]) {
				if (m_vcCell[i]->m_CellType == CellType::Normal && m_vcCell[i]->m_CellState != CellState::eOpen) {

					m_vcCell[i]->OpenCell();
					SafetyCellCount++;

					if(m_vcCell[i]->NearbyMines == 0){ 
						CheckNearbyCell(m_vcCell[i]); 
					}
				}
			}
		}
	}
}

bool GameManager::IsClear()
{
	bool clear = true;
	for (auto* cell : m_vcCell) {
		if(cell->m_CellType == CellType::Normal) {
			if (cell->m_CellState != CellState::eOpen) {
				clear = false;
			}
		}
	}		
	if (FlagNum != FlagCellCount) { clear = false; }
	return clear;
}

int GameManager::be_input()
{
	if (GameOver == true || IsClear() == true) { return 0; }

	INPUT_RECORD input_record;
	DWORD input_count;

	PeekConsoleInput(CIN, &input_record, 1, &input_count);

	return input_count;
}

int GameManager::get_input(bool* vkey, COORD* pos)
{
	if (GameOver == true || IsClear() == true) { return 0; }

	INPUT_RECORD input_record;
	DWORD input_count;

	ReadConsoleInput(CIN, &input_record, 1, &input_count);
	switch (input_record.EventType) {
	case MOUSE_EVENT:
		if (pos && (input_record.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)) {
			CONSOLE_SCREEN_BUFFER_INFO csbi;

			GetConsoleScreenBufferInfo(COUT, &csbi);

			*pos = input_record.Event.MouseEvent.dwMousePosition;
			pos->X -= csbi.srWindow.Left;
			pos->Y -= csbi.srWindow.Top;
			*vkey = false;
			return MOUSE_EVENT;
		}
		else if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
			CONSOLE_SCREEN_BUFFER_INFO csbi;

			GetConsoleScreenBufferInfo(COUT, &csbi);

			*pos = input_record.Event.MouseEvent.dwMousePosition;
			pos->X -= csbi.srWindow.Left;
			pos->Y -= csbi.srWindow.Top;
			*vkey = true;
			return MOUSE_EVENT;
		}
		break;
	}

	//    FlushConsoleInputBuffer(CIN);
	return 0;
}

void GameManager::Enable_MouseInput()
{
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);
	// 빠른 편집 모드 비활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode & ~ENABLE_QUICK_EDIT_MODE);
	// 마우스 입력 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
}

void GameManager::Disable_MoustInput()
{
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_QUICK_EDIT_MODE);
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode & ~ENABLE_MOUSE_INPUT);

	CIN = 0;
	COUT = 0;
}
