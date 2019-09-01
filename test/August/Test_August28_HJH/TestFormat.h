#pragma once
class TestFormat
{
public:
	TestFormat(const std::vector<std::string>&);
	~TestFormat();	

	std::vector<std::string> testcoed;

	virtual void summit() = 0;
};

