#pragma once
#include "Scene.h"

class OverScene : public Scene {
public:

	OverScene(SceneManager* a_pParent);
	virtual ~OverScene();


	virtual eScene GetScene() override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;
	virtual void KeyInput() override;
};

