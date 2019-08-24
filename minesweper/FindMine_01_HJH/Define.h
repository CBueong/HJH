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

enum {

	consoleSpace_Width = 10,
	consoleSpace_Height = 5,
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
	Option,
	Field,
};

struct Data {
	unsigned int x = 10;
	unsigned int y = 10;
	unsigned int mine = 10;
};

static Data static_Data;	// 설정 값 저장 하는 곳

static constexpr unsigned int X() { return static_Data.x; }
static constexpr unsigned int Y() { return static_Data.y; }
static constexpr unsigned int width() { return(X() * 2) + (consoleSpace_Width * 2); }
static constexpr unsigned int height() { return(Y() * 2) + (consoleSpace_Height * 2); }

void SetConsoleSize(const std::string _width = std::to_string(static_Data.x), const std::string _height = std::to_string(static_Data.x));
void SetCursour(char _visible = 0, int _width = 1);
void dis(int _x = 0, int _Y = 0);
void clr(Color _word = Color::white, Color _back = Color::black);
void SetDifficult(Difficult _difficulty);

