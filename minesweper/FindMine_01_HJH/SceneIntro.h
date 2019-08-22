#pragma once
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"

class SceneIntro : public Scene
{
public:
	SceneIntro(SceneManager * _instance);
	virtual~SceneIntro();

	//SceneManager* manager_instance = nullptr;

	virtual void Begin();
	virtual void Update();
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType();
};

