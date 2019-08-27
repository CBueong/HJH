#include "pch.h"
#include "SceneFactory.h"
#include "SceneManager.h"

#include "IntroScene.h"
#include "ConfigScene.h"

#include "GameScene.h"

#include "FinishScene.h"
#include "OverScene.h"


Scene* SceneFactory::Make(eScene a_eScene) {

	SceneManager* pParent = SceneMng();
	Scene* pMakedScene = nullptr;

	switch (a_eScene) {
	case eScene::IntroScene:	pMakedScene = new IntroScene(pParent);	break;
	case eScene::ConfigScene:	pMakedScene = new ConfigScene(pParent);	break;
	case eScene::GameScene:		pMakedScene = new GameScene(pParent);	break;
	case eScene::FinishScene:	pMakedScene = new FinishScene(pParent);	break;
	case eScene::OverScene:		pMakedScene = new OverScene(pParent);	break;
	default:					assert(false && "arg error");			break;
	}

	return pMakedScene;
}


