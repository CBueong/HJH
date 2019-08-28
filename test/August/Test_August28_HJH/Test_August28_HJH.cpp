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

	std::vector<std::vector<std::string>> testcase02
	{
	std::vector<std::string>{"1 1 9 0 5"},
	std::vector<std::string>{"1 1 8 0 3"},
	std::vector<std::string>{"2 0 3 1 1"},
	};

	std::vector<std::vector<std::string>> testcase02
	{
	std::vector<std::string>{"3","6 3 6","4 4 4","6 2 5"},
	std::vector<std::string>{"1","1 1 1"},
	std::vector<std::string>{"2","1 2 3","4 5 6"},
	};

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
