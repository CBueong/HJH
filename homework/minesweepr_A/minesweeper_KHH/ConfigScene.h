#pragma once
#include "IntroScene.h"

class ConfigScene :
	public IntroScene
{

	enum PrintPos { X = CONSOLE_X / 2 - 5, Y = CONSOLE_Y / 2 - 3, LastY = Y + 2, };

public:
	ConfigScene(SceneManager * a_pParent);
	virtual ~ConfigScene();

	virtual eScene GetScene() override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;
	virtual void KeyInput() override;
	virtual void ShowMenu() override;
	virtual void SelectMenu() override;
};

