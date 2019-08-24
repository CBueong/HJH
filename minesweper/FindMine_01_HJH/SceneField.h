#pragma once
#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "SceneField.h"
#include "Scene.h"

struct shell {
	shell() {
		mine = false;
		sweeped = false;
		count = 0;
	}
	bool mine;
	bool sweeped;
	int count;
};

class SceneField : public Scene
{
public:
	SceneField(class SceneManager * _instance);
	virtual~SceneField();

public:
	//SceneManager* manager_instance = nullptr;
	shell ** Field = nullptr;

	bool refresh = false;

	void Setting();

	virtual void Begin();
	virtual bool Update();
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType();
};

