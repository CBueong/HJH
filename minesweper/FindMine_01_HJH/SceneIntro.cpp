#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneIntro.h"

SceneIntro::SceneIntro(SceneManager * _instance) : Scene(_instance) {}

SceneIntro::~SceneIntro() {}

void SceneIntro::Begin() {

	SetConsoleSize();
	system("cls");

	dis((width() / 2) - (5));cout << "IntroScene";

	clr(Color::red);
	dis((width() / 2) - (8), 6);cout << "¡¶ Find Mine ¡·";
	clr();
	dis((width() / 2) - (8), 8);cout << "¡¶ Option    ¡·";
	dis((width() / 2) - (8), 10);cout << "¡¶ Run       ¡·";

	dis((width()) - (11), 19);cout << "HJH made";
}
bool SceneIntro::Update() {

	if (GetAsyncKeyState(VK_RETURN) & 0x8001) {

		switch ((select)sct)
		{
		case select::start: manager_instance->SceneChange(scene_t::Field);
			break;
		case select::option: manager_instance->SceneChange(scene_t::Option);
			break;
		case select::quit: return false;
			break;
		default: sct = (int)select::start;
			break;
		}
	}
	return true;
}

void SceneIntro::Render() {

	if (refresh) {

		clr();

		switch ((select)sct)
		{
		case select::start:
			dis((width() / 2) - (8), 8);cout << "¡¶ Option    ¡·";
			dis((width() / 2) - (8), 10);cout << "¡¶ Run       ¡·";
			clr(Color::red);
			dis((width() / 2) - (8), 6);cout << "¡¶ Find Mine ¡·";
			break;
		case select::option:
			dis((width() / 2) - (8), 6);cout << "¡¶ Find Mine ¡·";
			dis((width() / 2) - (8), 10);cout << "¡¶ Run       ¡·";
			clr(Color::green);
			dis((width() / 2) - (8), 8);cout << "¡¶ Option    ¡·";
			break;
		case select::quit:
			dis((width() / 2) - (8), 6);cout << "¡¶ Find Mine ¡·";
			dis((width() / 2) - (8), 8);cout << "¡¶ Option    ¡·";
			clr(Color::d_gray);
			dis((width() / 2) - (8), 10);cout << "¡¶ Run       ¡·";
			break;
		}

		clr();
	}
	refresh = false;
}

void SceneIntro::KeyInput() {

	if ((GetAsyncKeyState(VK_DOWN) & 0x0001) || (GetAsyncKeyState('S') & 0x0001)) { if (sct < (int)select::quit) { sct++;refresh = true; } }
	if ((GetAsyncKeyState(VK_UP) & 0x0001) || (GetAsyncKeyState('W') & 0x0001)) { if (sct > (int)select::start) { sct--;refresh = true; } }
}

scene_t SceneIntro::get_SceneType() { return scene_t::Intro; }

