#pragma once
class TestFormat
{
public:
	TestFormat() = default;
	TestFormat(const std::vector<std::string>&);
	~TestFormat();	

	virtual void summit() = 0;
};

