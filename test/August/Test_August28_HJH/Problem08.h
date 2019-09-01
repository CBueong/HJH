#pragma once
#include "TestFormat.h"
class Problem08 :public TestFormat
{
	struct physical {
		int weight;
		int tall;
	};

public:
	Problem08(const std::vector<std::string>& _solutionInput);
	~Problem08();

	//std::vector<std::string> testcoed;

	virtual void summit() override;

public:
	int n = 0;

	std::vector<physical> table;

	std::vector<int> solution;

	void Cal();

};

