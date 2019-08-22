#pragma once
#include "Define.h"
#include "SceneManager.h"

class Scene
{
public:
	Scene(SceneManager* _instance);
	virtual~Scene();

public:
	SceneManager* manager_instance = nullptr;

	virtual void Begin();
	virtual void Update();
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType() = 0;
};

