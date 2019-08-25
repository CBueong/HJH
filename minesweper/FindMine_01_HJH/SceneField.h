#pragma once
#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "SceneField.h"
#include "Scene.h"

enum class shell_t {
	empty,
	one,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	mine,
};

struct shell {
	bool sweeped = false;
	bool flag = false;
	shell_t type = shell_t::empty;
};

class SceneField : public Scene
{
public:
	SceneField(class SceneManager * _instance);
	virtual~SceneField();

private:
	shell ** Field = nullptr;
	POINT cur{ 0,0 };
	unsigned int click = 0;

	void Setting(int _x, int _y);		// Field 초기화
	shell_t check(int _x, int _y);
	void draw();
	void draw_f(int _x, int _y);
	void sweeping(int _x, int _y);		// main 기능
	void stepped(bool _step);			// gameover

public:
	//SceneManager* manager_instance = nullptr;
	//bool refresh = false;

	virtual void Begin();
	virtual bool Update();
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType();
};

