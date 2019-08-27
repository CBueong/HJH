#pragma once
#include "MapObject.h"

class Mine : public MapObject
{
public:
	eState state = eState::None;

public:
	Mine() = delete;
	Mine(int x, int y, eType type);
	~Mine();

	virtual void Interact(class Pointer* MyPointer);
};

