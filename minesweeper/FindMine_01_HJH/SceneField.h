#pragma once
#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "SceneField.h"
#include "Scene.h"

class SceneField : public Scene
{
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

public:
	SceneField(class SceneManager * _instance);
	virtual~SceneField();

private:
	shell **	 Field;
	POINT		 cur;
	unsigned int click;
	unsigned int mine_check;
	bool		 end = false;

	void LandingMine(int _x, int _y);	// set mine
	shell_t check(int _x, int _y);		// set number to check near mine
	void draw();						
	void draw_shell(int _x, int _y);	 
	void sweepping(int _x, int _y);		// open shell
	void End(bool _result = false);		// end event

public:
	//SceneManager* manager_instance = nullptr;
	//bool refresh = false;

	virtual void Begin();
	virtual bool Update();
	virtual void Render();
	virtual void KeyInput();
	virtual scene_t get_SceneType();
};

