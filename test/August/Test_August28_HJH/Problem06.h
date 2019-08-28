#pragma once
#include "TestFormat.h"
class Problem06 :public TestFormat
{
public:
	Problem06(const std::vector<std::string>& _solutionInput);
	~Problem06();

	virtual void summit() override;
};

