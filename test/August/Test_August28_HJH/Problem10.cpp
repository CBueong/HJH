#include "pch.h"
#include "Problem10.h"


Problem10::Problem10(const std::vector<std::string>& _solutionInput) :TestFormat(_solutionInput)
{
	std::string temp;

	for (auto str : _solutionInput[0]) { temp += str; }
	n = atoi(temp.c_str());
	temp.clear();

	std::cout << n << std::endl;
	//

	for (int i = 1; i < _solutionInput.size(); ++i) {

		for (auto str : _solutionInput[i]) {

			if (str == ' ') {

				building.push_back(atoi(temp.c_str()));
				temp.clear();
			}
			else { temp += str; }
		}
		building.push_back(atoi(temp.c_str()));
		temp.clear();
	}

	for (auto i : building) { std::cout << i << " "; }
	std::cout << std::endl;
	//
}

Problem10::~Problem10()
{

}

void Problem10::Cal()
{
	for (int i = 0; i < building.size(); ++i) {

		int signal = 0;

		for (int j = i; j >= 0; --j) {

			if (i != j && building[i] < building[j]) {

				signal = j + 1; break;
			}
		}

		solution.push_back(signal);
	}
}

void Problem10::summit()
{
	Cal();

	for (auto i : solution) { std::cout << i << " "; }
	std::cout << std::endl;
}