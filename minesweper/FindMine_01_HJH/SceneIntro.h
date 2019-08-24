#pragma once
#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneIntro.h"
class SceneIntro : public Scene
{
	enum class select {
		start,
		option,
		quit,
	};

public:
	SceneIntro(class SceneManager * _instance);
	virtual~SceneIntro();

public:
	//SceneManager* manager_instance = nullptr;
	unsigned int sct = (int)select::start;
	bool refresh = false;

	virtual void Begin();
	virtual bool Update();
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType();
};

