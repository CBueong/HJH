#pragma once
#include "TestFormat.h"
class Problem09 :public TestFormat
{
public:
	Problem09(const std::vector<std::string>& _solutionInput);
	~Problem09();

	virtual void summit() override;
};

