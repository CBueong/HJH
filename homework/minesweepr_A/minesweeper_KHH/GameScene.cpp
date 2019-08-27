#include "pch.h"
#include "GameScene.h"
#include "GameManager.h"

GameScene::GameScene(SceneManager* a_pParent) : Scene(a_pParent) {}

GameScene::~GameScene() {
	m_refParent = nullptr;
	ReleaseGameMng();
}

eScene GameScene::GetScene() { return eScene::GameScene; }

void GameScene::Init() { InitGameMng(); }

void GameScene::Update(float a_fDeltaTime) {

	GameMng()->Update(a_fDeltaTime);

	if (GameMng()->bFinish == true) { m_refParent->ChangeScene(eScene::FinishScene); }

	else if (GameMng()->bOver == true) { m_refParent->ChangeScene(eScene::OverScene); }
}
void GameScene::Render() { GameMng()->Render(); }

void GameScene::KeyInput() { GameMng()->KeyInput(); }
