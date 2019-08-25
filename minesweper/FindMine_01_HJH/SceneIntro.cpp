#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneIntro.h"

SceneIntro::SceneIntro(SceneManager * _instance) : Scene(_instance) {}

SceneIntro::~SceneIntro() {}

void SceneIntro::Begin() {

	system("cls");
	SetConsoleSize();
	menu();
}

bool SceneIntro::Update() {

	if (GetAsyncKeyState(VK_RETURN) & 0x0001) {

		switch ((select)sct)
		{
		case select::start:		manager_instance->SceneChange(scene_t::Field);	break;
		case select::option:	manager_instance->SceneChange(scene_t::Option);	break;
		case select::quit:		return false;									break;
		default:				sct = (int)select::start;						break;
		}
	}
	return true;
}

void SceneIntro::Render() {

	if (refresh) {

		switch ((select)sct)
		{
		case select::start:
			menu();
			clr(Color::d_red);
			dis((width() / 2) - (8), 6);cout << "¡¶ Find Mine ¡·";
			break;

		case select::option:
			menu();
			clr(Color::d_green);
			dis((width() / 2) - (8), 8);cout << "¡¶ Option    ¡·";
			break;

		case select::quit:
			menu();
			clr(Color::d_gray);
			dis((width() / 2) - (8), 10);cout << "¡¶ Run       ¡·";
			break;
		}		
	}
	refresh = false;
}

void SceneIntro::KeyInput() {

	if ((GetAsyncKeyState(VK_DOWN) & 0x0001) || (GetAsyncKeyState('S') & 0x0001)) { if (sct < (int)select::quit) { sct++;refresh = true; } }
	if ((GetAsyncKeyState(VK_UP) & 0x0001) || (GetAsyncKeyState('W') & 0x0001)) { if (sct > (int)select::start) { sct--;refresh = true; } }
}

scene_t SceneIntro::get_SceneType() { return scene_t::Intro; }

void SceneIntro::menu(Color _t, Color _b) {

	clr(_t, _b);

	dis((width() / 2) - (5));cout << "IntroScene";

	dis((width() / 2) - (8), 6);cout << "¡¶ Find Mine ¡·";

	dis((width() / 2) - (8), 8);cout << "¡¶ Option    ¡·";

	dis((width() / 2) - (8), 10);cout << "¡¶ Run       ¡·";

	dis(0, height() - 2);cout << this;
	dis(0, height() - 1);cout << manager_instance;
	dis((width()) - (11), height()-1);cout << "HJH made";
}