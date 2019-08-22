#pragma once

#include <Windows.h>
#include <cassert>

#define SAFE(x) { if(x != nullptr){ delete x; x= nullptr;} }
#define SAFE_ARR(x) { if(x != nullptr){ delete[] x; x= nullptr;} }

enum {};

enum class scene_t{
	Null,
	Intro,
	Field,
};

