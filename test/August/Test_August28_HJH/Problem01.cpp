#include "pch.h"
#include "Problem01.h"


Problem01::Problem01(const std::vector<std::string>& _caseInput) :TestFormat(_caseInput)
{
	// ���ڰ� ���� ������ �ʱ�ȭ
	n = atoi(_caseInput[0].c_str());
	std::cout << n << std::endl;

	for (int i = 1; i < _caseInput.size(); ++i) {

		bool xy = false;
		std::string tempX;
		std::string tempY;

		for (int j = 0; j < _caseInput[i].size(); j++) {

			if (_caseInput[i][j] == ' ') { xy = true; }

			else {
				switch (xy)
				{
				case false: tempX += _caseInput[i][j]; break;
				case true: tempY += _caseInput[i][j]; break;
				}
			}
		}

		std::cout << tempX << " " << tempY << std::endl;

		x.push_back(atoi(tempX.c_str()));
		y.push_back(atoi(tempY.c_str()));
		tempX.clear();
		tempY.clear();
	}
}


Problem01::~Problem01()
{

}

void Problem01::Cal(int _x, int _y) {

	// ���� �� bool ���� �ϰ� 
	//false �� true�� �ϰ� count++	

	for (int y = _y; y < _y + 10; ++y) {
		for (int x = _x; x < _x + 10; ++x) {

			if (!Wall[y][x]) { Wall[y][x] = true;  solution++; }
		}
	}
}

void Problem01::summit()
{
	for (int i = 0; i < n; ++i) { Cal(x[i], y[i]); }

	std::cout << solution << std::endl; // ����
}

