#pragma once
#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene(class SceneManager* a_pParent);
	virtual ~GameScene();

	// Scene��(��) ���� ��ӵ�
	virtual eScene GetScene() override;

	virtual void Init();
	virtual void Update(float a_fDeltaTime);
	virtual void Render();

};