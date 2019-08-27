#pragma once
class GameManager
{
public:

private:
	static inline GameManager * m_pInstance = nullptr;

	GameManager() = default;
	virtual ~GameManager();

	GameManager operator=(GameManager&) = delete;
	GameManager(GameManager&&) = delete;
	GameManager(const GameManager&) = delete;

public:

	static inline int MapSize;

	static void CreateInstance() { if (m_pInstance == nullptr) { m_pInstance = new GameManager(); } }
	static GameManager * GetInstance() { return m_pInstance; }
	static void ReleaseInstance() { SAFE_DELETE(m_pInstance); }

public:

	void Init();
	void Update(float a_fDeltaTime);
	void Render();
	void KeyInput();

	void Draw(int x, int y, const char* c);
	void Clear(int x, int y);
	bool GetOverState();

	void RenderByType(int x, int y);


public:

	clock_t start;
	bool bOver = false;
	bool bFinish = false;

	int s = MapSize;
	int dX = (CONSOLE_X - 2 * s) / 2;
	int dY = (CONSOLE_Y - s) / 2 - 1;

	class Pointer* MyPointer = nullptr;
	eType** Map = nullptr;
	eState** ObjState = nullptr;
	vector<class Block*> Blocks;
	vector<class Mine*> Mines;

};


#define InitGameMng()			{GameManager::CreateInstance(); GameManager::GetInstance()->Init();}
#define GameMng()				(GameManager::GetInstance())
#define ReleaseGameMng()		(GameManager::ReleaseInstance())