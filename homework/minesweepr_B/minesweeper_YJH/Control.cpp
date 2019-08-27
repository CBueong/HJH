#include "pch.h"
#include "Control.h"
#include "Search.h"

void Controle::move(int x, int y)
{
	c = _getch();

	switch (c)
	{
	case 72:
		if (map.GetMap(map.stage, X, Y - 1) != '-') { --Y; }
		break;
	case 80:
		if (map.GetMap(map.stage, X, Y + 1) != '-') { ++Y; }
		break;
	case 75:
		if (map.GetMap(map.stage, X - 1, Y) != '|') { --X; }
		break;
	case 77:
		if (map.GetMap(map.stage, X + 1, Y) != '|') { ++X; }
		break;
	}

	if (c == 'a') { Flag(); }	// flag on

	if (c == ' ') { if (map.DData[map.stage][Y][X] != '!') { Select(x, y); } }	// not flag do sweep

	gotoxy(0, 0);
	map.DrawMap(map.stage, x, y);
	gotoxy(X, Y);
	std::cout << '@';	// cursor
}

void Controle::Select(int x, int y)
{
	Search search;

	if (map.GetMap(map.stage, X, Y) == '*')
	{
		map.DData[map.stage][y][x] = '*';
		for (int i = 0; i < y; ++i)
		{
			for (int j = 0; j < x; ++j)
			{
				if (map.GetMap(map.stage, j, i) == '*')
				{
					map.DData[map.stage][i][j] = '*';
				}
			}
		}// draw all mines

		gotoxy(0, 0);
		map.DrawMap(map.stage, x, y);
		exit(0);							// return CMD;
	}// mine

	else
	{
		search.Find(map.stage, X, Y);// sweep here
		gotoxy(0, 0);
		map.DrawMap(map.stage, x, y);
	}
}

void Controle::Flag()
{
	if (map.DData[map.stage][Y][X] != '!') { map.DData[map.stage][Y][X] = '!'; }

	else { map.DData[map.stage][Y][X] = '#'; }
}//on off