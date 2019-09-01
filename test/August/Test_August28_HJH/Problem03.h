#pragma once
#include "TestFormat.h"
class Problem03 :public TestFormat
{
	struct Crood { int x; int y; };

public:
	Problem03(const std::vector<std::string>& _solutionInput);
	~Problem03();

	void Cal();
	virtual void summit() override;

public:
	//std::vector<std::string> testcoed;

	Crood area;
	std::vector<Crood> pos;

	int n;
	int X;
	int Y;

	int solution = 0;
};

