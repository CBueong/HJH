#pragma once
#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
class Scene
{
public:
	Scene(class SceneManager* _instance);
	virtual~Scene();

public:
	SceneManager* manager_instance = nullptr;
	bool refresh = true;

	virtual void Begin();
	virtual bool Update() = 0;
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType() = 0;
};

