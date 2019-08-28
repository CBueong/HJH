#pragma once
#include "TestFormat.h"
class Problem10 :public TestFormat
{
public:
	Problem10(const std::vector<std::string>& _solutionInput);
	~Problem10();

	virtual void summit() override;
};

