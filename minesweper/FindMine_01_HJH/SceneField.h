#pragma once
#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneField.h"

struct shell {
	bool Mine = false;
	bool swipped = false;	
	int count = 0;
};

class SceneField : public Scene
{
	shell ** Field = nullptr;

public:
	SceneField(class SceneManager * _instance);
	virtual~SceneField();
	
public:
	//SceneManager* manager_instance = nullptr;
	// ¸Ê ±¸¼º Á¤º¸


	void Setting();

	virtual void Begin();
	virtual bool Update();
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType();
};

