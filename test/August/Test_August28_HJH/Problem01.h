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

	int n;	// 벽지수
	std::vector<int> x;	// 벽지 x 위치
	std::vector<int> y;	// 벽지 y 위치

	int solution=0;

	void wallpapaer(int _x, int _y);
};

