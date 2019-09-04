#pragma once

#include "SceneManager.h"

class Scene
{
public:

	Scene(SceneManager * a_pParent);
	virtual ~Scene();

	virtual eScene GetScene() = 0;

	virtual void Init();
	virtual void Update(float a_fDeltaTime);
	virtual void Render();
	virtual void KeyInput(eKey a_eKey);

public:

	class SceneManager * m_refParent = nullptr;
};
