#include "pch.h"
#include "GameOverScene.h"


GameOverScene::GameOverScene(class SceneManager* a_pParent) : Scene(a_pParent)
{
}

GameOverScene::~GameOverScene()
{
}

eScene GameOverScene::GetScene()
{
	return eScene::GameOver;
}

void GameOverScene::Update(float a_fDeltaTime)
{
	system("cls");
	cout << "게임이 종료되었습니다.";
	exit(0);
}
