#include "pch.h"
#include "Problem04.h"


Problem04::Problem04(const std::vector<std::string>& _solutionInput) :TestFormat(_solutionInput)
{
	n = atoi(_solutionInput[0].c_str());

	std::string temp;
	std::vector<int> result;

	for (int i = 1; i < _solutionInput.size(); ++i) {
		for (int j = 0; j < _solutionInput[i].size(); ++j) {

			if (_solutionInput[i][j] == ' ') {

				result.push_back(atoi(temp.c_str()));
				temp.clear();
			}
			else { temp += _solutionInput[i]; }

		}
		gambler.push_back(result);
		result.clear();
	}
}


Problem04::~Problem04()
{

}

void Problem04::summit()
{
	for (auto i : gambler) { if (play(i) > solution) { solution = play(i); } }

	std::cout << solution << std::endl;
}

int Problem04::play(std::vector<int> _gambler) {

	int count = 0;
	int index = 0;

	for (int i = 0; i < 3; ++i)for (int j = 0; j < 3; ++j)
	{
		if ((_gambler[i] == _gambler[j]) && (i != j))
		{
			index = i; count++;
		}
	}

	int max = _gambler[0];

	switch (count)
	{
	case 0:
		for (auto i : _gambler) { if (i > max) { max = i; } }

		return (max * 200);
		break;

	case 1:
		return ((_gambler[index] * 500) + 2000);
		break;

	case 2:
		return ((_gambler[index] * 1000) + 5000);
		break;
	}
}
