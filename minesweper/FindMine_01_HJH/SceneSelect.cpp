#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneSelect.h"
#include "SceneIntro.h"
#include "SceneOption.h"
#include "SceneField.h"

Scene * SceneSelect::Select(scene_t _type, class SceneManager * _instance) {

	Scene * scene_instance = nullptr;

	switch (_type)
	{
	case scene_t::Intro: 	scene_instance = new SceneIntro(_instance); break;
	case scene_t::Option:	scene_instance = new SceneOption(_instance); break;
	case scene_t::Field: 	scene_instance = new SceneField(_instance);break;
	default:				scene_instance = new SceneIntro(_instance); break; // anyware launch
	}

	return scene_instance;
}