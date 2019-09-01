#pragma once
#include "TestFormat.h"
class Problem07 :public TestFormat
{
public:
	Problem07(const std::vector<std::string>& _solutionInput);
	~Problem07();

	//std::vector<std::string> testcoed;

	virtual void summit() override;

public:

	int minit = 0;
	int alarm = 0;
};

