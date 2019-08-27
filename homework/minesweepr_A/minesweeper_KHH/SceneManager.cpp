#include "pch.h"
#include "SceneManager.h"
#include "SceneFactory.h"
#include "Scene.h"


SceneManager::~SceneManager() {
	SAFE_DELETE(m_pNowScene);
}

void SceneManager::Init() {
	ChangeScene(eScene::IntroScene);
}

void SceneManager::ChangeScene() {
	if (m_pNowScene->bOver == true) {
		eScene etype = m_pNowScene->GetScene();

		switch (etype)
		{
		case eScene::IntroScene:	ChangeScene(eScene::ConfigScene);	break;
		case eScene::ConfigScene:	ChangeScene(eScene::GameScene);		break;
		default:break;
		}
	}
}

eScene SceneManager::GetNowScene() {
	return m_pNowScene->GetScene();
}


void SceneManager::ChangeScene(eScene a_eScene)
{
	SAFE_DELETE(m_pNowScene);

	m_pNowScene = SceneFactory::Make(a_eScene);

	assert((m_pNowScene != nullptr) && "error");

	system("cls");
	m_pNowScene->Init();
}

void SceneManager::Update(float a_fDeltaTime)
{
	m_pNowScene->Update(a_fDeltaTime);
}

void SceneManager::Render()
{
	m_pNowScene->Render();
}

void SceneManager::KeyInput() {
	m_pNowScene->KeyInput();
}

bool SceneManager::Exit() {
	return m_pNowScene->bExit;
}