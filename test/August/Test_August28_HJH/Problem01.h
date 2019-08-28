#pragma once
#include "TestFormat.h"
class Problem01 :public TestFormat
{
public:
	Problem01(const std::vector<std::string>& _caseInput);
	~Problem01();

	virtual void summit() override;

public:

	enum {

		w = 10,
		h = 10,

		W = 100,
		H = 100,

	};

	bool Wall[H][W]{ 0, };

	int n;	// ������
	std::vector<int> x;	// ���� x ��ġ
	std::vector<int> y;	// ���� y ��ġ

	int solution=0;

	void wallpapaer(int _x, int _y);
};

