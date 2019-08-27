#include "pch.h"
#include "Application.h"
#include "SceneManager.h"

Application::Application() { NEW_SM(); }

Application::~Application() { DEL_SM(); }

void Application::Run() {

	Begin();
	srand(time(NULL));

	while (Update()) {

		Render();
		KeyInput();
	}

	dis(0,19);system("pause");
}

void Application::Begin() { GET_SM()->Begin(); }

bool Application::Update() { return GET_SM()->Update(); }

void Application::Render() { GET_SM()->Render(); }

void Application::KeyInput() { GET_SM()->KeyInput(); }
