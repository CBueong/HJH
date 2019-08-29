#pragma once
#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneIntro.h"
class SceneIntro : public Scene
{
	enum select_t {
		start,	// find mine
		option,	// option
		quit,	// run
	};

public:
	SceneIntro(class SceneManager * _instance);
	virtual~SceneIntro();

private:
	void menu(Color _t = Color::white, Color _b = Color::black);

public:
	//SceneManager* manager_instance = nullptr;
	//bool refresh = false;
	unsigned int select = select_t::start;

	virtual void Begin();
	virtual bool Update();
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType();
};

