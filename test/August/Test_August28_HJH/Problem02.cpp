#include "pch.h"
#include "Problem02.h"


Problem02::Problem02(const std::vector<std::string>& _caseInput) :TestFormat(_caseInput)
{
	// 들어오는 값을 바로 계산한다.
	// 모든 자릿수 마다 제곱하여 더하기

	std::vector<int> comv;
	std::string temp;

	for (int i = 0; i < _caseInput[0].size(); ++i) {

		if (_caseInput[0][i] == ' ') {

			comv.push_back(atoi(temp.c_str()));
			temp.clear();
		}

		else { temp += _caseInput[0][i]; }
	}
	comv.push_back(atoi(temp.c_str()));

	for (auto i : comv) {
		std::cout << i << " ";
		solution += (i*i);

	}
}

Problem02::~Problem02()
{

}

void Problem02::summit()
{
	// 10으로 나누고 나머지

	std::cout << std::endl << solution << std::endl;

	solution %= 10;

	std::cout << solution << std::endl;
}