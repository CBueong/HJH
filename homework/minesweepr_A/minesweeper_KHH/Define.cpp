#include "pch.h"
#include "Define.h"


void gotoxy(size_t x, size_t y) {
	COORD CurPos;
	CurPos.X = x;
	CurPos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CurPos);
}

char GetKeyInput() {
	if (_kbhit()) {
		return _getch();
	}
	return '\0';
}

void delay(clock_t t) {
	clock_t start = clock();
	while (clock() - start < t);
}