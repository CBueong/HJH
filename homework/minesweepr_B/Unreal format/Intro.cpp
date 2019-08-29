#include "pch.h"
#include "Intro.h"

void Intro::Getintro()
{
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			int index = X * y + x;
			std::cout << intro[index];
		}
		std::cout << std::endl;
	}
}

void Intro::Level()
{
	Map map;

	while (true)
	{
		char c = _getch();
		switch (c)
		{
		case 72:
			if (stage != 0)
			{
				gotoxy(7, 4 + stage);
				cout << ' ';
				--stage;
				gotoxy(7, 4 + stage);
				cout << '>';
			}
			break;
		case 80:
			if (stage != 2)
			{
				gotoxy(7, 4 + stage);
				cout << ' ';
				++stage;
				gotoxy(7, 4 + stage);
				cout << '>';
			}
			break;
		}
		if (c == ' ')
		{
			switch (stage)
			{
			case 0:
				x = map.LV1_x;
				y = map.LV1_y;
				break;
			case 1:
				x = map.LV2_x;
				y = map.LV2_y;
				break;
			case 2:
				x = map.LV3_x;
				y = map.LV3_y;
				break;
			}
			break;
		}
	}
	map.stage = stage;
	map.Draw(stage, x, y);
	system("cls");
	map.DrawMap(stage, x, y);
	gotoxy(1, 1);
	std::cout << '@';
}