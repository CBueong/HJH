#pragma once
#include "TestFormat.h"
class Problem07 :public TestFormat
{
public:
	Problem07(const std::vector<std::string>& _solutionInput);
	~Problem07();

	virtual void summit() override;
};

