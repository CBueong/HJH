#pragma once
#include "TestFormat.h"
class Problem04 :public TestFormat
{
public:
	Problem04(const std::vector<std::string>& _solutionInput);
	~Problem04();

	virtual void summit() override;
};

