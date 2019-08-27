#include "pch.h"
#include "Pointer.h"


Pointer::Pointer(int x, int y, eType type) : MapObject(x, y, type){}

Pointer::~Pointer(){}

void Pointer::MoveTo(int x, int y) {
	Pos.X = x;
	Pos.Y = y;
}