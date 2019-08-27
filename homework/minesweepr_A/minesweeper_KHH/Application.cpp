#include "pch.h"
#include "Application.h"
#include "SceneManager.h"

constexpr float Application::GetTargetFPS() {
	constexpr float nTargetFPS = 30;
	return (1 / nTargetFPS) * 1000;
}

Application::Application() {

	system("mode con cols=100 lines=50");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	srand(time(NULL));

	InitSceneMng();
}

Application::~Application() {
	ReleaseSceneMng();
}

void Application::Run() {

	while (true) {

		clock_t now = clock();
		clock_t term = now - m_nLastStamp;

		if (term > GetTargetFPS()) {
			m_nDeltaTick = term;
			m_nLastStamp = now;

			float fDeltaTime = m_nDeltaTick / (float)1000;

			KeyInput();

			if (Update(fDeltaTime) == eUpdateState::Final) { system("cls");  break; }
			Render();
			SceneMng()->ChangeScene();
			if (SceneMng()->Exit() == true) { system("cls");  break; }
		}
	}
}

eUpdateState Application::Update(float a_fDelta) {

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { return eUpdateState::Final; }

	SceneMng()->Update(a_fDelta);

	return eUpdateState::Run;
}

void Application::Render() { SceneMng()->Render(); }

void Application::KeyInput() { SceneMng()->KeyInput(); }