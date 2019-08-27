#include "pch.h"
#include "ConfigScene.h"
#include "GameManager.h"


ConfigScene::ConfigScene(SceneManager * a_pParent) : IntroScene(a_pParent) {}

ConfigScene::~ConfigScene() {	m_refParent = nullptr;}

eScene ConfigScene::GetScene() {	return eScene::ConfigScene;}

void ConfigScene::Init() {	ShowMenu();}

void ConfigScene::Update(float a_fDeltaTime) {	SelectMenu();}

void ConfigScene::Render() {}

void ConfigScene::KeyInput() {}

void ConfigScene::ShowMenu() {
	Draw(x, y - 2, "   MAP SIZE");
	Draw(x, y,     ">> SMALL");
	Draw(x, y + 1, "   MIDDLE");
	Draw(x, y + 2, "   LARGE");
}

void ConfigScene::SelectMenu() {

	eKey c = (eKey)GetKeyInput();

	switch (c)
	{
	case eKey::Up:
		Draw(x, y, "  ");

		if (y == Y) { y = LastY; }
		else { y = y - 1; }

		Draw(x, y, ">>");
		break;
	case eKey::Down:
		Draw(x, y, "  ");

		if (y == LastY) { y = Y; }
		else { y = y + 1; }

		Draw(x, y, ">>");
		break;
	case eKey::Enter:
		switch (y)
		{
		case Y:     GameManager::MapSize = SMALL;   break;
		case Y + 1:	GameManager::MapSize = MIDDLE;	break;
		case LastY:	GameManager::MapSize = LARGE;	break;
		}

		Over();

		break;
	}
}