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
	case Difficult::easy:	static_Data = { 10,10,10 };		break;
	case Difficult::normal:	static_Data = { 16,16,40 };		break;
	case Difficult::hard:	static_Data = { 26,16,99 };		break;
	case Difficult::insane:	static_Data = { 30,30,200 };	break;
		//case Difficult::custom:break;
	default:				static_Data = { 10,10,10 };		break;
	}
}