#pragma once
#include "Define.h"
#include "SceneIntro.h"
#include "SceneField.h"
#include "Scene.h"
#include "SceneManager.h"

class SceneSelect{
public:
	Scene * Select(scene_t _type, SceneManager * _instance);	
};

