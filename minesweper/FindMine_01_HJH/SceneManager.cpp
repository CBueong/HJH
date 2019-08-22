#include "pch.h"
#include "SceneManager.h"

SceneManager::SceneManager(){}
SceneManager::~SceneManager(){}

void SceneManager::create_instance() {
	if (instance == nullptr) { instance = new SceneManager; }
}

SceneManager * SceneManager::manage_instance() { return instance; }

void SceneManager::release_instance() { SAFE(instance); }

void SceneManager::Begin() {
	now = scene_t::Intro;

}
void SceneManager::Update() {}
void SceneManager::Render() {}
void SceneManager::KeyInput() {}
