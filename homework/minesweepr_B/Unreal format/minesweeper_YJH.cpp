#include "pch.h"
#include "Intro.h"
#include "Control.h"

#include "vld.h"

int main()
{
	srand(time(0));

	Intro intro;
	Controle move;

	intro.Getintro();
	intro.Level();

	while (true) { move.move(intro.x, intro.y); }

	return 0;
}