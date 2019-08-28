#pragma once
#include "TestFormat.h"
class Problem03 :public TestFormat
{
public:
	Problem03(const std::vector<std::string>& _solutionInput);
	~Problem03();

	virtual void summit() override;

public:

	int solution = 0;

	void cal();
};

