#include "pch.h"
#include "SceneIntro.h"

SceneIntro::SceneIntro(SceneManager * _instance) : Scene(_instance){}

SceneIntro::~SceneIntro(){}

void SceneIntro::Begin() {}
void SceneIntro::Update() {}
void SceneIntro::Render() {}
void SceneIntro::KeyInput() {}
scene_t SceneIntro::get_SceneType() { return scene_t::Intro; }