#pragma once

class Intro
{
	int stage = 0;
	int X = 22;
	int Y = 9;

public:
	int x = 0;
	int y = 0;

	const char* intro =
	{
		"----------------------"
		"|                    |"
		"|                    |"
		"|                    |"
		"|      >Easy         |"
		"|       Normal       |"
		"|       Hord         |"
		"|                    |"
		"----------------------"
	};

	void Getintro();
	void Level();
};

