#pragma once
#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneOption.h"

class SceneOption :
	public Scene
{
	enum select {
		difficult,
		x,
		y,
		mine,
		back,
	};

	Data data;

	unsigned int sct = select::difficult;
	unsigned int difficulty = (unsigned int)Difficult::easy;
	bool custom = false;
	bool refresh = false;

	void menu(Color _color);
	void menu_diff();

public:
	SceneOption(class SceneManager* _instance);
	virtual~SceneOption();

public:
	//SceneManager* manager_instance = nullptr;	

	virtual void Begin();
	virtual bool Update();
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType();
};

