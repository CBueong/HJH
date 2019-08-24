#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"

Scene::Scene(SceneManager* _instance) {
	if (manager_instance == nullptr) { manager_instance = _instance; }
}

Scene::~Scene() {}

void Scene::Begin() {}
//bool Scene::Update() {}
void Scene::Render() {}
void Scene::KeyInput() {}
//scene_t Scene::get_SceneType()=0
