#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneField.h"

SceneField::SceneField(SceneManager * _instance) : Scene(_instance){}

SceneField::~SceneField(){}

void SceneField::Setting() {}//

void SceneField::Begin() {

	system("cls");

	// ¼³Á¤

	dis();cout << "This MineField";

}
bool SceneField::Update() { return true; }
void SceneField::Render() {}
void SceneField::KeyInput() {}
scene_t SceneField::get_SceneType() { return scene_t::Field; }