#pragma once
#include "MapObject.h"

class Pointer : public MapObject
{
public:
	float NowTerm = 0;
	float TargetTerm = 0.05f;
	bool bMove = true;
	bool bAlive = true;

public:
	Pointer() = delete;
	Pointer(int x, int y, eType type);
	~Pointer();

	void MoveTo(int x, int y);
};

