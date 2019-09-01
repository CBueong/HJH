#include "pch.h"
#include "Problem08.h"


Problem08::Problem08(const std::vector<std::string>& _solutionInput) :TestFormat(_solutionInput)
{
	std::string temp;

	for (auto str : _solutionInput[0]) { temp += str; }
	n = atoi(temp.c_str());
	temp.clear();
	//

	for (int i = 1; i < _solutionInput.size(); ++i) {

		physical body{ 0,0 };

		for (auto str : _solutionInput[i]) {

			if (str == ' ') {
				body.weight = atoi(temp.c_str());
				temp.clear();
			}
			else { temp += str; }
		}
		body.tall = atoi(temp.c_str());
		temp.clear();

		table.push_back(body);
	}
	//
}


Problem08::~Problem08()
{

}

void Problem08::Cal()
{
	for (int i = 0; i < table.size(); ++i) {

		int rank = 1;

		for (int j = 0; j < table.size(); ++j) {

			if (i != j) {

				if ((table[i].tall < table[j].tall) &&
					(table[i].weight < table[j].weight)) {

					rank++;
				}
			}
		}

		solution.push_back(rank);
	}
}

void Problem08::summit()
{
	Cal();

	for (auto i : solution) { std::cout << i << " "; }
	std::cout << std::endl;
}