#include "pch.h"
#include "Problem03.h"


Problem03::Problem03(const std::vector<std::string>& _solutionInput) :TestFormat(_solutionInput)
{
	std::string temp;

	for (auto str : _solutionInput[0]) {

		if (str == ' ') {

			X = atoi(temp.c_str());
			temp.clear();
		}

		else { temp += str; }
	}
	Y = atoi(temp.c_str());
	temp.clear();

	std::cout << X << " " << Y << std::endl;//
	// 

	n = atoi(_solutionInput[1].c_str());
	std::cout << n << std::endl;//
	//

	for (int i = 2; i < _solutionInput.size(); ++i) {

		Crood locate{ 0,0 };

		for (auto str : _solutionInput[i]) {

			if (str == ' ') {

				locate.x = atoi(temp.c_str());
				temp.clear();
			}

			else { temp += str; }
		}

		locate.y = atoi(temp.c_str());
		temp.clear();

		std::cout << locate.x << " " << locate.y << std::endl;//
		pos.push_back(locate);
	}
	//
}


Problem03::~Problem03()
{

}

void Problem03::Cal() {

	std::vector<int> distance;

	solution = (X + Y) * 2;
	int min = solution;
	int index = 0;

	for (int i = 0; i < pos.size() - 1; ++i) {

		if ((pos.back().x - pos[i].x) ||
			(pos.back().y - pos[i].y)) {

			int a = pos.back().x - pos[i].x;
			int b = pos.back().y - pos[i].y;

			if (a < 0) { a *= -1; }
			if (b < 0) { b *= -1; }

			distance.push_back(a + b);
		}

		else {
			distance.push_back(pos.back().x + pos[i].x + pos.back().y + pos[i].y);
		}
	}
	//

	for (int i = 0; i < distance.size(); ++i) {

		if (min > i) { index = i; }
	}

	distance.erase(distance.begin() + index);	//  제일 작은 수를 지운다.

	for (auto i : distance) { if (min > i) { min = i - 1; } }	// 그 다음으로 작은 수를 찾는다.	

	solution -= min;//두번째로 짧은 거리
}

void Problem03::summit()
{
	Cal();

	std::cout << solution << std::endl;
}