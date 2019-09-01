#pragma once
#include "TestFormat.h"
class Problem06 :public TestFormat
{
public:
	Problem06(const std::vector<std::string>& _solutionInput);
	~Problem06();

	//std::vector<std::string> testcoed;

	virtual void summit() override;

public:
	int n;
	int X, Y;
	int solution = 0;


	std::vector<std::vector<int>> table;

	void Cal();

};

