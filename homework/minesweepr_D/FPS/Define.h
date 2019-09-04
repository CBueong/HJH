#pragma once

using std::cout;
using std::endl;

enum class eUpdateState
{
	Run,
	Final,
};

enum class eKey
{
	None = -1,

	A,
	Left,
	W,
	Up,
	S,
	Right,
	D,
	Down,
	SPACE,
	Fire,

	Max,
};

enum class eInputState : short
{
	None	= 0b00,
	Down	= 0b11,
	Press	= 0b01,
	Up		= 0b10,
};

enum class eScene
{
	Intro,
	Game,
	GameOver,

	// ���̶��� ��������� ���� ���ϰ� ������ define ����� ��
	Scene_First = Intro,
};

enum class CellType {
	Normal,
	Mine,
};

enum class CellState {
	eDefault,
	eOpen,
	eFlag,
};

enum class OnCursor {
	eFALSE,
	eTRUE,
};

struct FieldInfo{
	size_t Field_X;
	size_t Field_Y;
	size_t Mines;
};

struct CellCoord {
	int x1;
	int x2;
	int y;
};

// �� : ��  ���� : ��  ���ǥ�� : ��  ��ĭ : ���� 
#define LEFT_CLICK (true)
#define RIGHT_CLICK (false)
#define SAFE_DELETE(x)		{ if((x) != nullptr ) { delete (x); (x) = nullptr; } }
#define SAFE_DELETE_ARR(x)	{ if((x) != nullptr ) { delete[] (x); (x) = nullptr; } }

enum class CURSOR_TYPE { NOCURSOR, SOLIDCURSOR, NORMALCURSOR };
void SetCursorType(CURSOR_TYPE c);
void SetCursor(const COORD& a_stPos);
void SetCursor(int a_nPosX, int a_nPosY);
