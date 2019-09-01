#include "pch.h"
#include "Problem05.h"


Problem05::Problem05(const std::vector<std::string>& _solutionInput) :TestFormat(_solutionInput)
{
	std::string temp;

	for (auto str : _solutionInput[0]) {
		temp += str;
	}
	n = atoi(temp.c_str());
	temp.clear();

	std::cout << n << std::endl;
	//

	for (int i = 1; i < _solutionInput.size(); ++i) {

		prame build{ 0,0 };

		for (auto str : _solutionInput[i]) {

			if (str == ' ') {
				build.dir = atoi(temp.c_str());
				temp.clear();

				std::cout << build.dir << " ";
			}

			else { temp += str; }
		}
		build.lenght = atoi(temp.c_str());
		temp.clear();

		std::cout << build.lenght << std::endl;


		farm.push_back(build);
	}
	//

}


Problem05::~Problem05()
{

}

void Problem05::Cal()
{
	int x = 0;
	int y = 0;

	for (auto i : farm) {

		if (i.dir < 3 && x < i.lenght) { x = i.lenght; }// 1 2

		if (i.dir > 2 && y < i.lenght) { y = i.lenght; }// 2 3
	}

	solution = x * y;

	for (int i = 0; i < farm.size(); ++i) {

		if (farm[i].dir == 1 && farm[i].dir == 3) {
			solution -= (farm[i].lenght * farm[i + 1].lenght);
		}
	}

	solution *= n;
}

void Problem05::summit()
{
	Cal();

	std::cout << solution << std::endl;
}