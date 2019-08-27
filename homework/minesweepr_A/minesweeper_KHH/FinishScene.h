#pragma once
#include "Scene.h"

class FinishScene : public Scene {
public:

	FinishScene(SceneManager* a_pParent);
	virtual ~FinishScene();


	virtual eScene GetScene() override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;
	virtual void KeyInput() override;
};

