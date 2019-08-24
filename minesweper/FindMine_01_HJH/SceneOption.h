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

	void menu(Color _color);
	void menu_diff(Difficult _difficulty);

public:
	SceneOption(class SceneManager* _instance);
	virtual~SceneOption();

public:
	SceneManager* manager_instance = nullptr;
	unsigned int sct = select::difficult;
	bool custom = false;
	unsigned int difficulty = (unsigned int)Difficult::easy;
	bool refresh = false;

	virtual void Begin();
	virtual bool Update();
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType();
};

