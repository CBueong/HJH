#pragma once
#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
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

private:
	class Scene* scene_instance = nullptr;

public:
	scene_t now = scene_t::Null;
	Data data{ 10,10,10 };

	void SceneChange(scene_t _type);

	void Begin();
	bool Update();
	void Render();
	void KeyInput();
};

#define NEW_SM() ( SceneManager::create_instance() )
#define GET_SM() ( SceneManager::manage_instance() )
#define DEL_SM() ( SceneManager::release_instance() )