#pragma once
#include "Define.h"
#include "Scene.h"
#include "SceneManager.h"

struct shell {
	bool Mine = false;
	bool swipped = false;	
	int count = 0;
};

class SceneField : public Scene
{
public:
	SceneField(SceneManager * _instance);
	virtual~SceneField();

	//SceneManager* manager_instance = nullptr;

	virtual void Begin();
	virtual void Update();
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType();
};

