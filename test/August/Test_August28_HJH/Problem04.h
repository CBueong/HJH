#pragma once
#include "TestFormat.h"
class Problem04 :public TestFormat
{
public:
	Problem04(const std::vector<std::string>& _solutionInput);
	~Problem04();

	virtual void summit() override;

public:

	int n;						//�����
	std::vector<int*> gamble;	//���¼�
	int solution = 0;			//����

	void play(int* _gambler);
};

