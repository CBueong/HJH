#include "pch.h"
#include "Problem01.h"


Problem01::Problem01(const std::vector<std::string>& _caseInput) :TestFormat(_caseInput)
{
	// 인자값 으로 변수들 초기화
	n = atoi(_caseInput[0].c_str());

	for (int i = 1; i < _caseInput.size(); ++i) {

		bool xy = false;
		std::string tempX;
		std::string tempY;

		for (int j = 0; j < _caseInput[i].size(); j++) {

			if (_caseInput[i][j] == ' ') { xy = true; j++; }

			switch (xy)
			{
			case false: tempX += _caseInput[i][j]; break;
			case true: tempY += _caseInput[i][j]; break;
			}
		}

		x.push_back(atoi(tempX.c_str()));
		y.push_back(atoi(tempY.c_str()));
		tempX.clear();
		tempY.clear();
	}
}


Problem01::~Problem01()
{

}

void Problem01::summit()
{
	for (int i = 0; i < n; ++i) { wallpapaer(x[i], y[i]); }

	std::cout << solution << std::endl; // 정답
}

void Problem01::wallpapaer(int _x, int _y) {

	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {

			if (((_x <= x) && (x <= _x + 10) &&		// x
				((_y <= y) && (y <= _y + 10))))		// y
			{
				if (Wall[y][x]) { Wall[y][x] = false; solution--; }
				else { Wall[y][x] = true;  solution++; }

				// 범위 내 bool 반전 하고 
				//true 시 ++
				//true 를 false 시 --
			}
		}
	}
}