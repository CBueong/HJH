#include "pch.h"
#include "MapObject.h"
#include "Pointer.h"


MapObject::MapObject(int x, int y, eType type) : Type(type) {
	Pos.X = x;
	Pos.Y = y;
}

MapObject::~MapObject() {}

COORD MapObject::GetPos() { return Pos; }

eType MapObject::GetObjectType() { return Type; }

void MapObject::Interact(Pointer* MyPointer) {}

bool MapObject::IsCrossed(int x, int y) {
	if (Pos.X == x && Pos.Y == y) { return true; }
	return false;
}