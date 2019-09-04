#include "pch.h"
#include "IntroScene.h"
#include "GameManager.h"
#include "SceneManager.h"

IntroScene::IntroScene(class SceneManager* a_pParent) : Scene(a_pParent)
{

}

IntroScene::~IntroScene() {}

eScene IntroScene::GetScene()
{
	return eScene::Intro;
}

void IntroScene::Update(float a_fDeltaTime)
{
	if (m_refParent->GetKeyState(eKey::S) == eInputState::Press) {
		if (ViewDifficultyMenu == false) {
			SelectMenu = Exit;
		}
		else {
			if (eDifficulty::Back > DifficultySelect) {
				++DifficultySelect;
			}
		}
	}
	else if (m_refParent->GetKeyState(eKey::W) == eInputState::Press) {
		if (ViewDifficultyMenu == false) {
			SelectMenu = Start;
		}
		else {			
			if (DifficultySelect > 0) {
				DifficultySelect--;
			}
		}
	}
	else if (m_refParent->GetKeyState(eKey::SPACE) == eInputState::Press) {
		if (NowMenu == MainMenu && SelectMenu == Exit) {
			system("cls");
			m_refParent->ChangeScene(eScene::GameOver);
		}
		if (NowMenu == MainMenu && SelectMenu == Start) {
			system("cls");
			DifficultySelect = Easy;
			ViewDifficultyMenu = true;
		}
		else if (NowMenu == DifficultyMenu && ViewDifficultyMenu == true) {
			switch (DifficultySelect)
			{
			case Easy:
				GameMng()->GameInit(FieldInfo{ 9,9,10 });
				m_refParent->ChangeScene(eScene::Game);
				break;
			case Normal:
				GameMng()->GameInit(FieldInfo{ 16,16,40 });
				m_refParent->ChangeScene(eScene::Game);
				break;
			case Hard:
				GameMng()->GameInit(FieldInfo{ 30,16,99 });
				m_refParent->ChangeScene(eScene::Game);
				break;
			case Back:
				ViewDifficultyMenu = false;
				system("cls");
				break;
			}
		}
		if (NowMenu == MainMenu) { NowMenu = DifficultyMenu; }
		else { NowMenu = MainMenu; }
	}
}

void IntroScene::Render()
{
	SetCursor(0, 0);
	cout << "----- MineSweeper -----";
	if (ViewDifficultyMenu == false) {
		SetCursor(6, 2);
		cout << m_Start  + "      " << endl;
		SetCursor(6, 4);
		cout << m_Exit + "      " << endl;
		if (SelectMenu == Start) {
			SetCursor(12, 2);
			cout << m_Seleter;
		}
		else {
			SetCursor(12, 4);
			cout << m_Seleter;
		}		
	}
	else {
		SetCursor(6, 2);
		cout << m_Easy + "      " << endl;
		SetCursor(6, 4);
		cout << m_Normal + "      " << endl;
		SetCursor(6, 6);
		cout << m_Hard + "      " << endl;
		SetCursor(6, 8);
		cout << m_Back + "      " << endl;

		switch (DifficultySelect)
		{
		case IntroScene::Easy:
			SetCursor(12, 2);
			cout << m_Seleter;
			break;
		case IntroScene::Normal:
			SetCursor(12, 4);
			cout << m_Seleter;
			break;
		case IntroScene::Hard:
			SetCursor(12, 6);
			cout << m_Seleter;
			break;
		case IntroScene::Back:
			SetCursor(12, 8);
			cout << m_Seleter;
			break;
		}
	}

	SetCursor(30, 1);
	cout << "선택 : W(위) S(아래)";

	SetCursor(30, 3);
	cout << "결정 : SPACEBAR";
}

void IntroScene::KeyInput(eKey a_eKey)
{

}
