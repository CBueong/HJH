#pragma once

#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>

#define SAFE(x) { if(x != nullptr){ delete x; x= nullptr;} }
#define SAFE_ARR(x) { if(x != nullptr){ delete[] x; x= nullptr;} }

enum {

	consoleSpace_Width = 10,
	consoleSpace_Height = 10,

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
	unsigned int x;
	unsigned int y;
	unsigned int mine;
};

static inline Data static_Data{ 10,10,10 };	// 설정 값 저장 하는 곳

static inline unsigned int X() { return static_Data.x; }								// map x
static inline unsigned int Y() { return static_Data.y; }								//
static inline unsigned int width() { return(X() * 2) + (consoleSpace_Width * 2); }		// console x
static inline unsigned int height() { return(Y() + (consoleSpace_Height * 2)); }		//

void SetConsoleSize(const std::string _width = std::to_string(width()), const std::string _height = std::to_string(height()));	//
void SetCursour(char _visible = 0, int _width = 1);																				//
void dis(int _x = 0, int _Y = 0);																								// gotoxy
void clr(Color _word = Color::white, Color _back = Color::black);																// SetColor ( Text , Background )
void SetDifficult(Difficult _difficulty);																						// not used