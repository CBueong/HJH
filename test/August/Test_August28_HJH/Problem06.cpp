#include "pch.h"
#include "Problem06.h"


Problem06::Problem06(const std::vector<std::string>& _solutionInput) :TestFormat(_solutionInput)
{	
	std::string temp;
	std::vector<int> data;

	for (auto str : _solutionInput[0]) { temp += str; }
	n = atoi(temp.c_str());
	temp.clear();

	std::cout << n << std::endl;
	//

	for (int i = 1; i < _solutionInput.size(); ++i) {

		for (auto str : _solutionInput[i]) {

			if (str == ' ') {

				data.push_back(atoi(temp.c_str()));
				temp.clear();
			}
			else { temp += str; }
		}

		data.push_back(atoi(temp.c_str()));
		temp.clear();

		table.push_back(data);
		data.clear();
	}
	//
}


Problem06::~Problem06()
{

}

void Problem06::Cal() {

	for (int i = 0; i < table.size(); ++i) {
		for (int j = 0; j < table[i].size(); ++j) {

			if (solution < table[i][j]) {

				solution = table[i][j];
				X = j;
				Y = i;
			}

			std::cout << table[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Problem06::summit()
{
	Cal();

	std::cout << Y << "За " << X << "ї­ " << table[Y][X] << std::endl;
}