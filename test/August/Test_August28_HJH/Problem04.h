#pragma once
#include "TestFormat.h"
class Problem04 :public TestFormat
{
public:
	Problem04(const std::vector<std::string>& _solutionInput);
	~Problem04();

	virtual void summit() override;

public:

	int n;									//사람수
	std::vector<std::vector<int>> gambler;	//나온수
	int solution = 0;						//정답

	int play(std::vector<int> _gambler);
};

