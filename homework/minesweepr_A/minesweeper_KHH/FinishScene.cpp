#include "pch.h"
#include "FinishScene.h"

FinishScene::FinishScene(SceneManager* a_pParent) : Scene(a_pParent) {}

FinishScene::~FinishScene() { m_refParent = nullptr; }

eScene FinishScene::GetScene() { return eScene::OverScene; }

void FinishScene::Init() {}

void FinishScene::Update(float a_fDeltaTime) {}

void FinishScene::Render() {
	gotoxy(1, 1);
	cout << "½Â¸®ÇÏ¼Ì½À´Ï´Ù!!!";
	getchar();
	Exit();
}

void FinishScene::KeyInput() {}
