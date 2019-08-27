#pragma once
class Controle
{
	char c;
	int X = 1;
	int Y = 1;
	Map map;

public:
	void move(int x, int y);
	void Select(int x, int y);

	void Flag();
};

