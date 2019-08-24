#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "SceneField.h"
#include "Scene.h"

SceneField::SceneField(SceneManager * _instance) : Scene(_instance) {

	Field = new shell*[Y];
	for (int i = 0;i < X;++i) { Field[i] = new shell; }

}

SceneField::~SceneField() {

	for (int i = 0;i < X;++i) { SAFE_ARR(Field); }

	SAFE(Field);

}

void SceneField::Setting() {}//

void SceneField::Begin() {

	system("cls");

	// ¼³Á¤

	dis();cout << "This MineField";

	refresh = true;
}
bool SceneField::Update() { return true; }
void SceneField::Render() {	

	if (refresh) {

		dis();

		for (int y = 0; y < Y;++y) {

			for (int x = 0; x < X;++x) {

				if (!(Field[y][x].swipped)) { cout << "¡á"; }

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
			cout << endl;
		}
	}

	refresh = false;
}
void SceneField::KeyInput() {}
scene_t SceneField::get_SceneType() { return scene_t::Field; }