#pragma once
#include "SceneSelect.h"
#include "Scene.h"

class SceneManager
{
	static inline SceneManager* instance = nullptr;

	SceneManager();
	SceneManager(const SceneManager&) = delete;
	SceneManager(SceneManager&&) = delete;
	~SceneManager();

	SceneManager operator=(SceneManager&) = delete;

public:
	static void create_instance();
	static SceneManager * manage_instance();
	static void release_instance();

public:
	scene_t now = scene_t::Null;

	void Begin();
	void Update();
	void Render();
	void KeyInput();
};

#define NEW_SM() ( create_instance() )
#define GET_SM() ( manage_instance() )
#define DEL_SM() ( release_instance() )