#pragma once

#include <Windows.h>
#include <cassert>
#include <string>

#define SAFE(x) { if(x != nullptr){ delete x; x= nullptr;} }
#define SAFE_ARR(x) { if(x != nullptr){ delete[] x; x= nullptr;} }

// void SetConsoleSize(const std::string _width = "40", const std::string _height = "20");
// void SetCursour(char _visible = 0, int _width = 1);
// void dis(int _x = 0, int _Y = 0);
// void clr(Color _word = Color::white, Color _back = Color::black);
// void SetDifficult(Difficult _difficulty);

enum class Color {
	black,
	d_blue,
	d_green,
	d_sky,
	d_red,
	d_violet,
	d_yellow,
	gray,
	d_gray,
	blue,
	green,
	sky,
	red,
	violet,
	yellow,
	white,
};

enum class Difficult {
	easy,
	normal,
	hard,
	insane,
	custom,
};

enum class scene_t {
	Null,
	Intro,
	Option,
	Field,
};

static unsigned int X = 10;
static unsigned int conX = X + (10 * 2);
static unsigned int Y = 10;
static unsigned int conY = Y + (5 * 2);
static unsigned int MINE = 10;

void SetConsoleSize(const std::string _width = std::to_string(conX), const std::string _height = std::to_string(conY));
void SetCursour(char _visible = 0, int _width = 1);
void dis(int _x = 0, int _Y = 0);
void clr(Color _word = Color::white, Color _back = Color::black);
void SetDifficult(Difficult _difficulty);
