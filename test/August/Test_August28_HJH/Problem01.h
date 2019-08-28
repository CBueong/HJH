#pragma once
#include "TestFormat.h"
class Problem01 :public TestFormat
{
public:
	Problem01(const std::vector<std::string>& _solutionInput);
	~Problem01();

	virtual void summit() override;
};

