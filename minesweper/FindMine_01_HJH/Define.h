#pragma once

#include <Windows.h>
#include <cassert>
#include <string>

#define SAFE(x) { if(x != nullptr){ delete x; x= nullptr;} }
#define SAFE_ARR(x) { if(x != nullptr){ delete[] x; x= nullptr;} }

static struct Data;
enum class Color;
enum class Difficult;
enum class scene_t;

void SetConsoleSize(const std::string _width = "40", const std::string _height = "20");
void SetCursour(char _visible = 0, int _width = 1);
void dis(int _x = 0, int _Y = 0);
void clr(Color _word = Color::white, Color _back = Color::black);
void SetDifficult(Difficult _difficulty);


static struct Data {

	static Difficult difficulty;
	static unsigned int x;
	static unsigned int y;
	static unsigned int mine;
};

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
	Field,
};