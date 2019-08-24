#include "pch.h"
#include "Define.h"




void SetConsoleSize(const std::string _width, const std::string _height) {

	std::string command("mode con cols=");

	command = command + _width + " lines=" + _height;

	system(command.c_str());
}

void SetCursour(char _visible, int _width) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = _visible;
	ConsoleCursor.dwSize = _width;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void dis(int _x, int _y) {

	COORD cur{ (short)_x, (short)_y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

void clr(Color _word, Color _back) {

	unsigned int color = (int)_word + (int)_back * 16;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SetDifficult(Difficult _difficulty) {

	switch (_difficulty)
	{
	case Difficult::easy:

		break;
	case Difficult::normal:


		break;
	case Difficult::hard:


		break;
	case Difficult::insane:


		break;
	}
}