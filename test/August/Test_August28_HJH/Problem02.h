#pragma once
#include "TestFormat.h"
class Problem02 :public TestFormat
{
public:
	Problem02(const std::vector<std::string>& _solutionInput);
	~Problem02();

	virtual void summit() override;
};

