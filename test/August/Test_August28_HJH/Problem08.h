#pragma once
#include "TestFormat.h"
class Problem08 :public TestFormat
{
public:
	Problem08(const std::vector<std::string>& _solutionInput);
	~Problem08();

	virtual void summit() override;
};

