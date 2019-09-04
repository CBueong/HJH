#pragma once
#include "Scene.h"

class IntroScene : public Scene
{
	enum{ Exit = 0, Start, MainMenu, DifficultyMenu, };
	enum eDifficulty {
		Easy,
		Normal,
		Hard,
		Back,
	};

public:
	IntroScene(class SceneManager* a_pParent);
	virtual ~IntroScene();

	// Scene을(를) 통해 상속됨
	virtual eScene GetScene() override;

	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;
	virtual void KeyInput(eKey a_eKey) override;

private:
	int DifficultySelect = eDifficulty::Easy;
	int NowMenu = MainMenu;
	bool ViewDifficultyMenu = false;
	bool SelectMenu = Start;

	std::string m_Start = "시작";
	std::string m_Exit = "종료";

	std::string m_Easy = "Easy";
	std::string m_Normal = "Normal";
	std::string m_Hard = "Hard";
	std::string m_Back = "뒤로";

	std::string m_Seleter = "<<";
};
