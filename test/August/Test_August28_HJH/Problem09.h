#pragma once
#include "TestFormat.h"
class Problem09 :public TestFormat
{
public:
	Problem09(const std::vector<std::string>& _solutionInput);
	~Problem09();

	//std::vector<std::string> testcoed;

	virtual void summit() override;

public:
	int year = 0;

	std::vector<std::string> ten{ "��","��","��","��","��","��","��","��","��","��" };
	std::vector<std::string> twelve{ "��","��","��","��","��","��","��","��","��","��","��","��" };

};

