#pragma once
#include "TestFormat.h"
class Problem04 :public TestFormat
{
public:
	Problem04(const std::vector<std::string>& _solutionInput);
	~Problem04();

	virtual void summit() override;

public:

	int n;									//�����
	std::vector<std::vector<int>> gambler;	//���¼�
	int solution = 0;						//����

	int play(std::vector<int> _gambler);
};

