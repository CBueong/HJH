#include "pch.h"
#include "Problem02.h"


Problem02::Problem02(const std::string& _caseInput) 
{
	// 들어오는 값을 바로 계산한다.
	// 모든 자릿수 마다 제곱하여 더하기

	std::string temp;

	for (int i = 0; i < _caseInput.size(); ++i) {

		if (_caseInput[i] == ' ') {

			solution += atoi(temp.c_str());
			temp.clear();
		}

		else { temp += _caseInput[i]; }
	}
	solution += atoi(temp.c_str());//마지막 숫자
}


Problem02::~Problem02()
{

}

void Problem02::summit()
{
	// 10으로 나누고 나머지

	solution %= 10;

	std::cout << solution << std::endl;
}