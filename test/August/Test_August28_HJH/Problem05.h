#pragma once
#include "TestFormat.h"
class Problem05 :public TestFormat
{
public:
	Problem05(const std::vector<std::string>& _solutionInput);
	~Problem05();

	virtual void summit() override;
};

