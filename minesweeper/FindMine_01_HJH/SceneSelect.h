#pragma once
#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneSelect.h"
#include "SceneIntro.h"
#include "SceneField.h"

class SceneSelect{
public:
	static class Scene * Select(scene_t _type, class SceneManager * _instance);	
};

