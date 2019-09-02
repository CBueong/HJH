#include "pch.h"
#include "Problem07.h"


Problem07::Problem07(const std::vector<std::string>& _solutionInput) :TestFormat(_solutionInput)
{
	std::string temp;

	for (auto str : _solutionInput[0]) {

		if (str == ' ') {
			
			minit = atoi(temp.c_str()) * 60;
			temp.clear();
		}

		else { temp += str; }
	}
	minit += atoi(temp.c_str());
	temp.clear();
	//

	for (auto str : _solutionInput[1]) { temp += str; }
	alarm = atoi(temp.c_str());
	temp.clear();
	//
	std::cout << _solutionInput[0] << " + " << _solutionInput[1] << std::endl;
}


Problem07::~Problem07()
{

}

void Problem07::summit()
{
	std::cout << (minit + alarm) / 60 % 24 << " " << (minit + alarm) % 60 << std::endl;
}