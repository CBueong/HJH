#pragma once
#include "TestFormat.h"
class Problem02 :public TestFormat
{
public:
	Problem02(const std::vector<std::string>& _caseInput);
	~Problem02();

	virtual void summit() override;

public:
	//std::vector<std::string> testcoed;

	unsigned int solution = 0;
};

