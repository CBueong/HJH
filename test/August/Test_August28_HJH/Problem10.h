#pragma once
#include "TestFormat.h"
class Problem10 :public TestFormat
{
public:
	Problem10(const std::vector<std::string>& _solutionInput);
	~Problem10();

	//std::vector<std::string> testcoed;

	virtual void summit() override;

public:
	int n;
	std::vector<int> building;
	std::vector<int> solution;

	void Cal();
};

