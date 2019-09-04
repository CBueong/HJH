#include "pch.h"

#include "GameScene.h"
#include "GameManager.h"


GameScene::GameScene(class SceneManager* a_pParent) : Scene(a_pParent)
{
}

GameScene::~GameScene()
{
}

eScene GameScene::GetScene()
{
	return eScene::Game;
}

void GameScene::Init()
{
	GameMng()->Init();
}

void GameScene::Update(float a_fDeltaTime)
{
	GameMng()->Update(a_fDeltaTime);
}

void GameScene::Render()
{
	GameMng()->Render();
}
