#include "pch.h"
#include "Search.h"

void Search::Find(int st, int x, int y)
{
	Map map;

	if (map.GetMap(st, x, y) >= One && map.GetMap(st, x, y) <= Nine)
	{
		map.DData[st][y][x] = map.GetMap(st, x, y);
	}

	if (map.GetMap(st, x, y) == ' ')
	{
		map.DData[st][y][x] = ' ';
		while (1)
		{
			if (map.GetMap(st, x + X, y) >= One && map.GetMap(st, x + X, y) <= Nine || map.GetMap(st, x + X, y) == '|')
			{
				map.DData[st][y][x + X] = map.GetMap(st, x + X, y);
				X = 0;
				Y = 0;
				Y1 = 0;
				break;
			}// 

			if (map.GetMap(st, x + X, y + Y) != ' ' && map.GetMap(st, x + X, y + Y1) != ' ')
			{
				map.DData[st][y + Y][x + X] = map.GetMap(st, x + X, y + Y);
				map.DData[st][y + Y1][x + X] = map.GetMap(st, x + X, y + Y1);
				Y = 0;
				Y1 = 0;
				--X;
			}

			if (map.GetMap(st, x + X, y + Y) == ' ')
			{
				map.DData[st][y + Y][x + X] = ' ';
				for (int r = -1; r < 2; ++r)
					for (int c = -1; c < 2; ++c)
					{
						if (!(r | c))continue;
						if (map.GetMap(st, x + X + c, y + Y + r) == ' ')
							map.DData[st][y + Y + r][x + X + c] = ' ';
						else
							map.DData[st][y + Y + r][x + X + c] = map.GetMap(st, x + X + c, y + Y + r);
					}
				--Y;
			}

			if (map.GetMap(st, x + X, y + Y1) == ' ')
			{
				map.DData[st][y + Y1][x + X] = ' ';
				for (int r = -1; r < 2; ++r)
					for (int c = -1; c < 2; ++c)
					{
						if (!(r | c))continue;
						if (map.GetMap(st, x + X + c, y + Y1 + r) == ' ')
							map.DData[st][y + Y1 + r][x + X + c] = ' ';
						else
							map.DData[st][y + Y1 + r][x + X + c] = map.GetMap(st, x + X + c, y + Y1 + r);
					}
				++Y1;
			}
		}

		while (1)
		{
			if (map.GetMap(st, x + X, y) >= One && map.GetMap(st, x + X, y) <= Nine || map.GetMap(st, x + X, y) == '|')
			{
				map.DData[st][y][x + X] = map.GetMap(st, x + X, y);
				X = 0;
				Y = 0;
				Y1 = 0;
				break;
			}

			if (map.GetMap(st, x + X, y + Y) != ' ' && map.GetMap(st, x + X, y + Y1) != ' ')
			{
				map.DData[st][y + Y][x + X] = map.GetMap(st, x + X, y + Y);
				map.DData[st][y + Y1][x + X] = map.GetMap(st, x + X, y + Y1);
				Y = 0;
				Y1 = 0;
				++X;
			}

			if (map.GetMap(st, x + X, y + Y) == ' ')
			{
				map.DData[st][y + Y][x + X] = ' ';
				for (int r = -1; r < 2; ++r)
					for (int c = -1; c < 2; ++c)
					{
						if (!(r | c))continue;
						if (map.GetMap(st, x + X + c, y + Y + r) == ' ')
							map.DData[st][y + Y + r][x + X + c] = ' ';
						else
							map.DData[st][y + Y + r][x + X + c] = map.GetMap(st, x + X + c, y + Y + r);
					}
				--Y;
			}

			if (map.GetMap(st, x + X, y + Y1) == ' ')
			{
				map.DData[st][y + Y1][x + X] = ' ';
				for (int r = -1; r < 2; ++r)
					for (int c = -1; c < 2; ++c)
					{
						if (!(r | c))continue;
						if (map.GetMap(st, x + X + c, y + Y1 + r) == ' ')
							map.DData[st][y + Y1 + r][x + X + c] = ' ';
						else
							map.DData[st][y + Y1 + r][x + X + c] = map.GetMap(st, x + X + c, y + Y1 + r);
					}

				++Y1;
			}
		}
	}
}