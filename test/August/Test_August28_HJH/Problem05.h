#pragma once
#include "TestFormat.h"
class Problem05 :public TestFormat
{
	struct prame { int dir; int lenght; };

public:
	Problem05(const std::vector<std::string>& _solutionInput);
	~Problem05();

	//std::vector<std::string> testcoed;

	virtual void summit() override;

public:
	int n;
	std::vector<prame> farm;

	int solution = 0;

	void Cal();

};

