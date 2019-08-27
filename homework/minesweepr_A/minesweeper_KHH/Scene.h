#pragma once
#include "SceneManager.h"


class Scene
{
public:
	bool bExit = false;
	bool bOver = false;


	Scene(SceneManager * a_pParent);
	virtual ~Scene();

	virtual eScene GetScene() = 0;

	virtual void Init();
	virtual void Update(float a_fDeltaTime);
	virtual void Render();
	virtual void KeyInput();

	virtual inline bool GetState() const { return bOver; }
	virtual inline void Over() { bOver = true; }
	virtual inline void Exit() { bExit = true; }

public:

	class SceneManager * m_refParent = nullptr;
};
