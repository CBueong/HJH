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

	Data data{10,10,10};

	unsigned int sct = select::difficult;
	unsigned int difficulty = (unsigned int)Difficult::easy;
	bool custom = false;

	void menu(Color _t = Color::white, Color _b = Color::black);
	void menu_diff(Color _t, Color _b);

public:
	SceneOption(class SceneManager* _instance);
	virtual~SceneOption();

public:
	//SceneManager* manager_instance = nullptr;	
	//bool refresh = false;

	virtual void Begin();
	virtual bool Update();
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType();
};

