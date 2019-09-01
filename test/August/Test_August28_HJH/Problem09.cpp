#include "pch.h"
#include "Problem09.h"


Problem09::Problem09(const std::vector<std::string>& _solutionInput) :TestFormat(_solutionInput)
{
	std::string temp;

	for (auto str : _solutionInput[0]) { temp += str; }
	year = atoi(temp.c_str());
	temp.clear();
}


Problem09::~Problem09()
{

}

void Problem09::summit()
{
	int a = ((year / 10) + (year / 60)) % 10;
	int b = ((year / 12) + (year / 60)) % 12;

	std::cout << ten[a] << twelve[b] << std::endl;
}

// 갑 을 병 정 무 기 경 신 임 계
// 자 축 인 묘 진 사 오 미 신 유 술 해

