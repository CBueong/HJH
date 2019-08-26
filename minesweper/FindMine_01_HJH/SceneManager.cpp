#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "SceneSelect.h"
#include "Scene.h"

SceneManager::SceneManager() {}
SceneManager::~SceneManager() { SAFE(scene_instance); }

void SceneManager::create_instance() {
	if (instance == nullptr) { instance = new SceneManager; }
}

SceneManager * SceneManager::manage_instance() { return instance; }

void SceneManager::release_instance() { SAFE(instance); }

void SceneManager::SceneChange(scene_t _type) {

	SAFE(scene_instance);

	scene_instance = SceneSelect::Select(_type, this);	

	scene_instance->Begin();
}

void SceneManager::Begin() {

	now = scene_t::Intro;
	SceneChange(now);
}
bool SceneManager::Update() { return scene_instance->Update(); }
void SceneManager::Render() { scene_instance->Render(); }
void SceneManager::KeyInput() { scene_instance->KeyInput(); }
