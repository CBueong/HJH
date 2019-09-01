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
#include "Input.h"

#define SPACE (std::cout<<std::endl)

int main()
{
	using namespace Input;

	//testcase01;
	//testcase02;
	//testcase03;
	//testcase04;
	//testcase05;
	//testcase06;
	//testcase07;
	//testcase08;
	//testcase09;
	//testcase10;

	std::cout << "test 01 " << std::endl;
	for (auto &testcase : testcase01) { Problem01(testcase).summit(); SPACE; }

	std::cout << "test 02 " << std::endl;
	for (auto &testcase : testcase02) { Problem02(testcase).summit(); SPACE; }

	std::cout << "test 03 " << std::endl;
	for (auto &testcase : testcase03) { Problem03(testcase).summit(); SPACE; }

	std::cout << "test 04 " << std::endl;
	for (auto &testcase : testcase04) { Problem04(testcase).summit(); SPACE; }

	std::cout << "test 05 " << std::endl;
	for (auto &testcase : testcase05) { Problem05(testcase).summit(); SPACE; }

	std::cout << "test 06 " << std::endl;
	for (auto &testcase : testcase06) { Problem06(testcase).summit(); SPACE; }

	std::cout << "test 07 " << std::endl;
	for (auto &testcase : testcase07) { Problem07(testcase).summit(); SPACE; }

	std::cout << "test 08 " << std::endl;
	for (auto &testcase : testcase08) { Problem08(testcase).summit(); SPACE; }

	std::cout << "test 09 " << std::endl;
	for (auto &testcase : testcase09) { Problem09(testcase).summit(); SPACE; }

	std::cout << "test 10 " << std::endl;
	for (auto &testcase : testcase10) { Problem10(testcase).summit(); SPACE; }


	getchar();
	getchar();
	return 0;
}

