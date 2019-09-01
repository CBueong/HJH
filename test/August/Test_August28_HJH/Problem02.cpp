#include "pch.h"
#include "Problem02.h"


Problem02::Problem02(const std::vector<std::string>& _caseInput) :TestFormat(_caseInput)
{
	// ������ ���� �ٷ� ����Ѵ�.
	// ��� �ڸ��� ���� �����Ͽ� ���ϱ�

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
	// 10���� ������ ������

	std::cout << std::endl << solution << std::endl;

	solution %= 10;

	std::cout << solution << std::endl;
}