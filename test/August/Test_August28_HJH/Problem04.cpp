#include "pch.h"
#include "Problem04.h"


Problem04::Problem04(const std::vector<std::string>& _solutionInput) :TestFormat(_solutionInput)
{
	// 첫 인자는 사람수
	// 이후 주사위를 굴린 결과 값이다.

	std::string temp;

	for (auto str : _solutionInput[0]) { temp += str; }

	std::cout << temp << std::endl;
	n = atoi(temp.c_str());
	temp.clear();

	if (n < 2 || n > 1000) { error = true; }

	std::vector<int> result;

	for (int i = 1; i < _solutionInput.size(); ++i) {

		for (int j = 0; j < _solutionInput[i].size(); ++j) {

			if (_solutionInput[i][j] == ' ') {

				result.push_back(atoi(temp.c_str()));
				temp.clear();
			}

			else { temp += _solutionInput[i][j]; }
		}

		result.push_back(atoi(temp.c_str()));
		temp.clear();

		gambler.push_back(result);
		result.clear();
	}
}

Problem04::~Problem04()
{

}

void Problem04::Cal() {
	
	//중복되는 수를 찾는다 중복횟수 체크
	//없으면 가장 큰수를 찾는다.
	//조건에 따라 결과 값을 내고 가장 큰 수를 찾는다.
	
	int biggest = 0;

	for (auto result : gambler) {

		int count = 0;
		int max = 0;
		int b = 0;

		for (int i = 0; i < result.size(); ++i) {
			for (int j = 0; j < result.size(); ++j) {

				if (result[i] == result[j]) { max = result[i]; count++; }

			}
			if (count < 2) { count = 0; }
			if (count) { break; }
		}

		switch (count)
		{
		case 0:
			for (int i : result) { if (i > max) { max == i; } }
			b = max * 200;
			break;
		case 2:b = max * 500 + 2000; break;
		case 3:b = max * 1000 + 5000; break;
		}

		for (auto i : result) { std::cout << i << " "; }
		std::cout << b << std::endl;

		if (b > biggest) { biggest = b; }	
	}
	solution = biggest;
}

void Problem04::summit() {

	Cal();

	switch (error) {
	case false:std::cout << solution << std::endl; break;
	case true:std::cout << "입력 오류" << std::endl; break;
	}
}
