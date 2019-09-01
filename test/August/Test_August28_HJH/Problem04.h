#pragma once
#include "TestFormat.h"
class Problem04 :public TestFormat
{
public:
	Problem04(const std::vector<std::string>& _solutionInput);
	~Problem04();

	void Cal();
	virtual void summit() override;

public:
	//std::vector<std::string> testcoed;

	int n;
	bool error = false;
	std::vector<std::vector<int>> gambler;
	int solution = 0;	
};

