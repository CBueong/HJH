#include "pch.h"
#include "Mine.h"
#include "Pointer.h"

Mine::Mine(int x, int y, eType type) : MapObject(x, y, type){}

Mine::~Mine(){}

void Mine::Interact(Pointer* MyPointer) { if (state == eState::None) { MyPointer->bAlive = false; } }