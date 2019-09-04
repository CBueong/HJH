#pragma once
#include "SceneManager.h"
class GameManager
{
#pragma region SINGLE_TON
private:
	static inline GameManager* m_pInstance = nullptr;
	GameManager();
	~GameManager();

	GameManager operator=(GameManager&) = delete;
	GameManager(GameManager&&) = delete;
	GameManager(const GameManager&) = delete;

public:
	static void CreateInstance() {
		if (m_pInstance == nullptr) {
			m_pInstance = new GameManager();
			//m_pInstance->Init();
		}
	}

	static GameManager* GetInstance() {
		return m_pInstance;
	}

	static void ReleaseInstance() {
		SAFE_DELETE(m_pInstance);
	}
#pragma endregion

public:
	void Init();
	void GameInit(FieldInfo a_FieldInfo);
	void Update(float a_fDeltatime);
	void Render();
	void Release();

	// �� ����
	void CellMaker();
	int CheckNearbyMines(class Cell* a_Cell);
	void CheckNearbyCell(class Cell* a_Cell);

	// ���� Ŭ���� or ����
	bool IsClear();
	bool IsGameOVer() { return GameOver; }

	// ���콺 �Է�
	int be_input();
	int get_input(bool* vkey, COORD* pos);
	void Enable_MouseInput();
	void Disable_MoustInput();

private:
	// �� ���� �־�� ����
	std::vector<class Cell*> m_vcCell;
	FieldInfo m_FieldInfo;

	// ���� ����
	float Timer = 0;
	size_t MineNum = 0;
	int FlagNum = 0;
	int MakeMineCell = 0;
	size_t MaxCellCount = 0;
	size_t SafetyCellCount = 0;
	size_t FlagCellCount = 0;

	bool GameOver = false;

	HANDLE COUT = 0;    // �ܼ� ��� ��ġ
	HANDLE CIN = 0;     // �ܼ� �Է� ��ġ

	DWORD mode;
	bool key;
	COORD pos;
};

#define InitGameMng()		{GameManager::CreateInstance(); }
#define GameMng()			(GameManager::GetInstance())
#define ReleaseGameMng()	(GameManager::ReleaseInstance())