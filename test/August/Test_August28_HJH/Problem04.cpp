#include "pch.h"
#include "Problem04.h"


Problem04::Problem04(const std::vector<std::string>& _solutionInput) :TestFormat(_solutionInput)
{

}


Problem04::~Problem04()
{

}

void Problem04::summit()
{
	for (auto i : gamble) { play(i); }

	std::cout << solution << std::endl;
}

void Problem04::play(int* _gambler) {

	int count=0;

	int min=0, max=0, temp=0;

	// ¿¬»ê

	if (count == 3) { solution += ((temp * 1000) + 5000); }

	else if (count == 2) { solution += ((temp * 500) + 2000); }

	else { solution += (max * 200); }

}