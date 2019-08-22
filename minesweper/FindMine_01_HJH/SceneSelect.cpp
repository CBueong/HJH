#include "pch.h"
#include "SceneSelect.h"

Scene * SceneSelect::Select(scene_t _type, SceneManager * _instance) {

	SAFE(_instance);

	Scene * scene_instance = nullptr;

	switch (_type)
	{
	case scene_t::Intro: scene_instance = new SceneIntro(_instance); break;
	case scene_t::Field: scene_instance = new SceneField(_instance);break;
	default: break;
	}

	return scene_instance;
}