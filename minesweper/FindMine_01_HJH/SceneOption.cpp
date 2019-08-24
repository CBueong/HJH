#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneOption.h"


SceneOption::SceneOption(SceneManager* _instance) : Scene(_instance) {}

SceneOption::~SceneOption() {}

void SceneOption::Begin() {	// highlight = white , default = d_gray

	SetConsoleSize();
	system("cls");
	menu(Color::d_gray);

	clr();dis((conX / 2) - (10), 8);cout << "¡¶    e a s y    ¡·";
}

bool SceneOption::Update() { return true; }

void SceneOption::Render() {

	if (refresh) {

		switch ((select)sct)
		{
		case select::difficult:

			menu(Color::d_gray);
			menu_diff((Difficult)difficulty);
			break;

		case select::x:
			menu(Color::d_gray);
			clr();
			dis((conX / 2) - (10), 10);cout << "¡¶  Width        ¡·";
			break;
		case select::y:
			menu(Color::d_gray);
			clr();
			dis((conX / 2) - (10), 12);cout << "¡¶  Height       ¡·";
			break;
		case select::mine:
			menu(Color::d_gray);
			clr();
			dis((conX / 2) - (10), 14);cout << "¡¶  Mine         ¡·";
			break;
		case select::back:
			menu(Color::d_gray);
			clr();
			dis((conX / 2) - (2), 16);cout << "Back";
			break;
		}
	}
	refresh = false;
}

void SceneOption::KeyInput() {

	if ((GetAsyncKeyState(VK_LEFT) & 0x0001) || (GetAsyncKeyState('A') & 0x0001)) {

		switch ((select)sct)
		{
		case select::difficult:
			if (difficulty > (unsigned int)Difficult::easy) { difficulty--; }
			break;
		case select::x:
			if (X > 1) { X--; };
			break;
		case select::y:
			if (Y > 1) { Y--; };
			break;
		case select::mine:
			if (MINE > 1) { MINE--; };
			break;
		}
		refresh = true;
	}

	if ((GetAsyncKeyState(VK_RIGHT) & 0x0001) || (GetAsyncKeyState('D') & 0x0001)) {

		switch ((select)sct)
		{
		case select::difficult:
			if (difficulty < (unsigned int)Difficult::custom) { difficulty++; }
			break;

		case select::x:
			X++;
			break;

		case select::y:
			Y++;
			break;

		case select::mine:
			if (mine < X*Y) { MINE++; };
			break;
		}
		refresh = true;
	}

	if ((GetAsyncKeyState(VK_UP) & 0x0001) || (GetAsyncKeyState('W') & 0x0001)) {

		if (sct > (unsigned int)select::difficult) { sct--; }
		refresh = true;
	}

	if ((GetAsyncKeyState(VK_DOWN) & 0x0001) || (GetAsyncKeyState('S') & 0x0001)) {

		if (sct < (unsigned int)select::back) { sct++; }
		refresh = true;
	}

	if ((GetAsyncKeyState(VK_RETURN) & 0x0001)&& sct == (unsigned int)select::back) {
		manager_instance->SceneChange(scene_t::Intro);	
	}
}

scene_t SceneOption::get_SceneType() { return scene_t::Option; }

void SceneOption::menu(Color _color) {
	clr();
	dis((conX / 2) - (4));cout << "Option";

	clr(_color);
	dis((conX / 2) - (6), 6);cout << "Difficulty ";
	
	dis((conX / 2) - (10), 8);cout << "¡¶    e a s y    ¡·";
	
	dis((conX / 2) - (10), 10);cout << "¡¶  Width        ¡·";

	dis((conX / 2) - (10), 12);cout << "¡¶  Height       ¡·";

	dis((conX / 2) - (10), 14);cout << "¡¶  Mine         ¡·";

	dis((conX / 2) - (2), 16);cout << "Back";

	dis((conX) - (11), (conY - 1));cout << "HJH made";
}

void SceneOption::menu_diff(Difficult _difficulty) {

	switch ((Difficult)_difficulty)
	{
	case Difficult::easy:
		clr();
		dis((conX / 2) - (10), 8);cout << "¡¶    e a s y    ¡·";
		break;
	case Difficult::normal:
		clr();
		dis((conX / 2) - (10), 8);cout << "¡¶  n o r m a l  ¡·";
		break;
	case Difficult::hard:
		clr();
		dis((conX / 2) - (10), 8);cout << "¡¶    h a r d    ¡·";
		break;
	case Difficult::insane:
		clr();
		dis((conX / 2) - (10), 8);cout << "¡¶  i n s a n e  ¡·";
		break;
	case Difficult::custom:
		clr();
		dis((conX / 2) - (10), 8);cout << "¡¶  c u s t o m  ¡·";
		break;
	}
}