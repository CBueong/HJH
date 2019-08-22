#include "pch.h"
#include "SceneField.h"

SceneField::SceneField(SceneManager * _instance) : Scene(_instance){}

SceneField::~SceneField(){}

void SceneField::Begin() {}
void SceneField::Update() {}
void SceneField::Render() {}
void SceneField::KeyInput() {}
scene_t SceneField::get_SceneType() { return scene_t::Field; }