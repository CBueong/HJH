#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneIntro.h"

SceneIntro::SceneIntro(SceneManager * _instance) : Scene(_instance) {}

SceneIntro::~SceneIntro() {}

void SceneIntro::Begin() {

	SetDifficult(Difficult::easy);

	system("cls");

	dis(15);cout << "IntroScene";

	dis(12, 6);clr(Color::red);cout << "¡¶ Find Mine ¡·";clr();
	dis(12, 8);cout << "¡¶ Option    ¡·";
	dis(12, 10);cout << "¡¶ Run       ¡·";

	dis(31, 19);cout << "HJH made";
}
bool SceneIntro::Update() {

	if (GetAsyncKeyState(VK_RETURN) & 0x8001) {

		switch ((select)sct)
		{
		case select::start: manager_instance->SceneChange(scene_t::Field);
			break;
		case select::option:
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
			dis(12, 8);cout << "¡¶ Option    ¡·";
			dis(12, 10);cout << "¡¶ Run       ¡·";
			clr(Color::red);
			dis(12, 6);cout << "¡¶ Find Mine ¡·";
			break;
		case select::option:
			dis(12, 6);cout << "¡¶ Find Mine ¡·";
			dis(12, 10);cout << "¡¶ Run       ¡·";
			clr(Color::green);
			dis(12, 8);cout << "¡¶ Option    ¡·";
			break;
		case select::quit:
			dis(12, 6);cout << "¡¶ Find Mine ¡·";
			dis(12, 8);cout << "¡¶ Option    ¡·";
			clr(Color::d_gray);
			dis(12, 10);cout << "¡¶ Run       ¡·";
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

