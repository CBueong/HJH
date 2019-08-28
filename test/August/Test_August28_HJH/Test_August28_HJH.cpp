#include "pch.h"

#include "Problem01.h"
#include "Problem02.h"
#include "Problem03.h"
#include "Problem04.h"
#include "Problem05.h"
#include "Problem06.h"
#include "Problem07.h"
#include "Problem08.h"
#include "Problem09.h"
#include "Problem10.h"

#define SPACE (std::cout<<std::endl)

int main()
{
	std::vector<std::vector<std::string>> testcase01
	{
		std::vector<std::string>{"3","2 9","4 3","14 9"},
		std::vector<std::string>{"1","1 1"},
		std::vector<std::string>{"2","1 1","5 5"},
	};

	std::vector<std::string> testcase02
	{
	{"1 1 9 0 5"},
	{"1 1 8 0 3"},
	{"2 0 3 1 1"}
	};

	std::vector<std::string> case03
	{
	{},
	{},
	{}
	};

	std::vector<std::string> case04
	{
	{},
	{},
	{}
	};

	std::vector<std::string> case05
	{
	{},
	{},
	{}
	};

	std::vector<std::string> case06
	{
	{},
	{},
	{}
	};

	std::vector<std::string> case07
	{
	{},
	{},
	{}
	};

	std::vector<std::string> case08
	{
	{},
	{},
	{}
	};

	std::vector<std::string> case09
	{
	{},
	{},
	{}
	};

	std::vector<std::string> case10
	{
	{},
	{},
	{}
	};



	//Problem01 P02(case02);	// 
	//Problem01 P03(case03);	//
	//Problem01 P04(case04);	//
	//Problem01 P05(case05);	//
	//Problem01 P06(case06);	//
	//Problem01 P07(case07);	//
	//Problem01 P08(case08);	//
	//Problem01 P09(case09);	//
	//Problem01 P10(case10);	//

	std::cout << "test 01 " << std::endl;
	for (auto &testcase : testcase01) { Problem01(testcase).summit(); SPACE; }

	std::cout << "test 02 " << std::endl;
	for (auto &testcase : testcase02) { Problem02(testcase).summit(); SPACE; }

	//	P03.summit(); SPACE;
	//	P04.summit(); SPACE;
	//	P05.summit(); SPACE;
	//	P06.summit(); SPACE;
	//	P07.summit(); SPACE;
	//	P08.summit(); SPACE;
	//	P09.summit(); SPACE;
	//	P10.summit(); SPACE;

	getchar();
	getchar();
	return 0;
}
