#pragma once
#include "TestFormat.h"
class Problem02 :public TestFormat
{
public:
	Problem02(const std::string& _caseInput);
	~Problem02();

	virtual void summit() override;

public:
	unsigned int solution;
};

