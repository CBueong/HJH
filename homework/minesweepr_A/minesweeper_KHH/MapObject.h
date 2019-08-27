#pragma once
class MapObject
{
protected:
	COORD Pos;
	eType Type;
public:
	MapObject() = delete;
	MapObject(int x, int y, eType type);
	~MapObject();

	virtual COORD GetPos();
	virtual eType GetObjectType();
	virtual void Interact(class Pointer* MyPointer);

	virtual bool IsCrossed(int x, int y);
};

