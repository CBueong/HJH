#include "pch.h"
#include "Problem02.h"


Problem02::Problem02(const std::string& _caseInput) 
{
	// ������ ���� �ٷ� ����Ѵ�.
	// ��� �ڸ��� ���� �����Ͽ� ���ϱ�

	std::string temp;

	for (int i = 0; i < _caseInput.size(); ++i) {

		if (_caseInput[i] == ' ') {

			solution += atoi(temp.c_str());
			temp.clear();
		}

		else { temp += _caseInput[i]; }
	}
	solution += atoi(temp.c_str());//������ ����
}


Problem02::~Problem02()
{

}

void Problem02::summit()
{
	// 10���� ������ ������

	solution %= 10;

	std::cout << solution << std::endl;
}