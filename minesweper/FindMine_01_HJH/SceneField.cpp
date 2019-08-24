#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "SceneField.h"
#include "Scene.h"

SceneField::SceneField(SceneManager * _instance) : Scene(_instance) {

	Field = new shell*[Y()];
	for (int i = 0;i < width();++i) { Field[i] = new shell(); }

}

SceneField::~SceneField() {

	for (int i = 0;i < width();++i) { SAFE_ARR(Field); }

	SAFE(Field);
}

void SceneField::Setting() {}//

void SceneField::Begin() {

	SetConsoleSize();
	system("cls");

	dis(width()/2 -7);cout << "This MineField";

	refresh = true;
}
bool SceneField::Update() {
	
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8001) {
		manager_instance->SceneChange(scene_t::Intro);
	}
	return true; 
}
void SceneField::Render() {	

	if (refresh) {		

		for (int y = 0; y < Y();++y) {

			dis((width() - X()*2)/2, 5+y);

			for (int x = 0; x < X();++x) {

				if (!(Field[y][x].sweeped)) { cout << "¡á"; }

				else {

					switch (Field[y][x].count)
					{
					case 0:cout << "  ";break;
					case 1:cout << "£±";break;
					case 2:cout << "£²";break;
					case 3:cout << "£³";break;
					case 4:cout << "£´";break;
					case 5:cout << "£µ";break;
					case 6:cout << "£¶";break;
					case 7:cout << "£·";break;
					case 8:cout << "£¸";break;
					default:cout << "£¿";break;
					}
				}
			}
			//cout << endl;
		}
	}

	refresh = false;
}
void SceneField::KeyInput() {}
scene_t SceneField::get_SceneType() { return scene_t::Field; }