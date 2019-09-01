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

	std::vector<std::string> ten{ "갑","을","병","정","무","기","경","신","임","계" };
	std::vector<std::string> twelve{ "자","축","인","묘","진","사","오","미","신","유","술","해" };

};

