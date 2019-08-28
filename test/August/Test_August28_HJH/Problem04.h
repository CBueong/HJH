#pragma once
#include "TestFormat.h"
class Problem04 :public TestFormat
{
public:
	Problem04(const std::vector<std::string>& _solutionInput);
	~Problem04();

	virtual void summit() override;

public:

	int n;						//사람수
	std::vector<int*> gamble;	//나온수
	int solution = 0;			//정답

	void play(int* _gambler);
};

