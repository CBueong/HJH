#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneOption.h"


SceneOption::SceneOption(SceneManager* _instance) : Scene(_instance) {}

SceneOption::~SceneOption() {}

void SceneOption::Begin() {	// highlight = white , default = d_gray	

	system("cls");
	static_Data = manager_instance->data;
	SetConsoleSize();
	menu(Color::d_gray);
}

bool SceneOption::Update() {

	if ((GetAsyncKeyState(VK_RETURN) & 0x0001) && (sct == (unsigned int)select::back)) {

		switch ((Difficult)difficulty)
		{
		case Difficult::easy:	manager_instance->data = { 10,10,10 };		break;
		case Difficult::normal:	manager_instance->data = { 16,16,40 };		break;
		case Difficult::hard:	manager_instance->data = { 21,21,99 };		break;
		case Difficult::insane:	manager_instance->data = { 30,30,250 };		break;
		case Difficult::custom:	manager_instance->data = data;				break;
		default:				manager_instance->data = { 10,10,10 };		break;
		}// 설정 값 전달

		manager_instance->SceneChange(scene_t::Intro);
	}
	return true;
}

void SceneOption::Render() {

	if (refresh) {

		switch ((select)sct)
		{
		case select::difficult:
			menu(Color::d_gray);
			break;

		case select::x:
			menu(Color::d_gray);
			clr();
			dis((width() / 2) - (10), 10);cout << "《  Width        》";
			dis((width() / 2) + 2, 10);cout << data.x;
			break;
		case select::y:
			menu(Color::d_gray);
			clr();
			dis((width() / 2) - (10), 12);cout << "《  Height       》";
			dis((width() / 2) + 2, 12);cout << data.y;
			break;
		case select::mine:
			menu(Color::d_gray);
			clr();
			dis((width() / 2) - (10), 14);cout << "《  Mine         》";
			dis((width() / 2) + 2, 14);cout << data.mine;
			break;
		case select::back:
			menu(Color::d_gray);
			clr();
			dis((width() / 2) - (2), 16);cout << "Back";

			break;
		}
		dis(0, height() - 2);cout << "scene   :" << this;
		dis(0, height() - 1);cout << "manager :" << manager_instance;
	}
	refresh = false;
}

void SceneOption::KeyInput() {

	if ((GetAsyncKeyState(VK_LEFT) & 0x0001) || (GetAsyncKeyState('A') & 0x0001)) {

		switch ((select)sct)
		{
		case select::difficult:	if (difficulty > (unsigned int)Difficult::easy) { difficulty--; }	break;
		case select::x:			if (data.x > 1) { data.x--; };										break;
		case select::y:			if (data.y > 1) { data.y--; };										break;
		case select::mine:		if (data.mine > 1) { data.mine--; };								break;
		}
		refresh = true;
	}

	if ((GetAsyncKeyState(VK_RIGHT) & 0x0001) || (GetAsyncKeyState('D') & 0x0001)) {

		switch ((select)sct)
		{
		case select::difficult:	if (difficulty < (unsigned int)Difficult::custom) { difficulty++; }	break;
		case select::x:			data.x++;															break;
		case select::y:			data.y++;															break;
		case select::mine:		if (mine < (width()*Y())) { data.mine++; };							break;
		}
		refresh = true;
	}

	if ((GetAsyncKeyState(VK_UP) & 0x0001) || (GetAsyncKeyState('W') & 0x0001)) {

		if (difficulty != (unsigned int)Difficult::custom) { sct = select::difficult; }
		else if (sct > (unsigned int)select::difficult) { sct--; }
		refresh = true;
	}

	if ((GetAsyncKeyState(VK_DOWN) & 0x0001) || (GetAsyncKeyState('S') & 0x0001)) {
		if (difficulty != (unsigned int)Difficult::custom) { sct = select::back; }
		else if (sct < select::back) { sct++; }
		refresh = true;
	}
}

scene_t SceneOption::get_SceneType() { return scene_t::Option; }

void SceneOption::menu(Color _t, Color _b) {

	clr(_t, _b);

	dis((width() / 2) - (4));cout << "Option";

	dis((width() / 2) - (6), 6);cout << "Difficulty ";

	//dis((width() / 2) - (10), 8);cout << "《    e a s y    》";		// menu_diff()

	//dis((width() / 2) - (10), 10);cout << "《  Width        》";

	//dis((width() / 2) - (10), 12);cout << "《  Height       》";

	//dis((width() / 2) - (10), 14);cout << "《  Mine         》";

	//dis((width() / 2) - (2), 16);cout << "Back";

	dis((width()) - (11), (height() - 1));cout << "HJH made";

	menu_diff(_t, _b);														// menu_diff() here
}

void SceneOption::menu_diff(Color _t, Color _b) {

	if (sct == select::difficult) { clr(); }

	switch ((Difficult)difficulty)
	{
	case Difficult::easy:
		dis((width() / 2) - (10), 8);cout << "《    e a s y    》";
		clr(_t, _b);
		dis((width() / 2) - (10), 10);cout << "《  Width    10  》";

		dis((width() / 2) - (10), 12);cout << "《  Height   10  》";

		dis((width() / 2) - (10), 14);cout << "《  Mine     10  》";

		dis((width() / 2) - (2), 16);cout << "Back";
		break;

	case Difficult::normal:
		dis((width() / 2) - (10), 8);cout << "《  n o r m a l  》";
		clr(_t, _b);
		dis((width() / 2) - (10), 10);cout << "《  Width    16  》";

		dis((width() / 2) - (10), 12);cout << "《  Height   16  》";

		dis((width() / 2) - (10), 14);cout << "《  Mine     40  》";

		dis((width() / 2) - (2), 16);cout << "Back";
		break;

	case Difficult::hard:
		dis((width() / 2) - (10), 8);cout << "《    h a r d    》";
		clr(_t, _b);
		dis((width() / 2) - (10), 10);cout << "《  Width    20  》";

		dis((width() / 2) - (10), 12);cout << "《  Height   20  》";

		dis((width() / 2) - (10), 14);cout << "《  Mine     99  》";

		dis((width() / 2) - (2), 16);cout << "Back";
		break;

	case Difficult::insane:
		dis((width() / 2) - (10), 8);cout << "《  i n s a n e  》";
		clr(_t, _b);
		dis((width() / 2) - (10), 10);cout << "《  Width    30  》";

		dis((width() / 2) - (10), 12);cout << "《  Height   30  》";

		dis((width() / 2) - (10), 14);cout << "《  Mine    250  》";

		dis((width() / 2) - (2), 16);cout << "Back";
		break;

	case Difficult::custom:
		dis((width() / 2) - (10), 8);cout << "《  c u s t o m  》";
		clr(_t, _b);
		dis((width() / 2) - (10), 10);cout << "《  Width        》";
		dis((width() / 2) + 4, 10);cout << data.x;

		dis((width() / 2) - (10), 12);cout << "《  Height       》";
		dis((width() / 2) + 4, 12);cout << data.y;

		dis((width() / 2) - (10), 14);cout << "《  Mine         》";
		dis((width() / 2) + 4, 14);cout << data.mine;

		dis((width() / 2) - (2), 16);cout << "Back";
		break;
	}
}