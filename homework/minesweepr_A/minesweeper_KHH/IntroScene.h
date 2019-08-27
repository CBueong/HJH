#pragma once
#include "Scene.h"

class IntroScene :
	public Scene
{
protected:
	enum PrintPos { X = CONSOLE_X / 2 - 5, Y = CONSOLE_Y / 2 - 3, LastY = Y + 1, };
	int x = X;
	int y = Y;

public:
	IntroScene(SceneManager * a_pParent);
	virtual ~IntroScene();

	virtual eScene GetScene() override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;
	virtual void KeyInput() override;
	virtual void ShowMenu();
	virtual void SelectMenu();
	virtual void Draw(int x, int y, const char* c);
};

