#pragma once

#define SAFE_DELETE(x) if((x) != nullptr) { delete (x); (x) = nullptr;}
#define SAFE_DELETE_ARR(x) if((x) != nullptr) { delete[] (x); (x) = nullptr;}

using namespace std;

enum class eUpdateState {
	Run,
	Final,
};

enum class eType {
	Pointer,

	Block,
	Mine,
};

enum eSize {
	CONSOLE_X = 100,
	CONSOLE_Y = 50,


};

enum class eState {
	None,
	Pushed,
	Flagged,
};

enum eMapSize {
	SMALL = 10,
	MIDDLE = 20,
	LARGE = 30,
};

enum class eKey {
	None = 0,

	Up = 72,
	Down = 80,
	Left = 75,
	Right = 77,
	Enter = 13,

	Select = 97,
	Flag = 102,

	Space = 32,
};

enum class eScene {
	IntroScene,
	ConfigScene,

	GameScene,

	FinishScene,
	OverScene,
};

void gotoxy(size_t x, size_t y);
char GetKeyInput();
void delay(clock_t t);