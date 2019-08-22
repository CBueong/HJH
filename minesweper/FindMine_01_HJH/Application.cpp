#include "pch.h"
#include "Application.h"

Application::Application() {}

Application::~Application() {}

void Application::Run() {

	Begin();

	while (Launch) {

		Render();
		KeyInput();
		Update();
	}

}

void Application::Begin() {}

void Application::Update() {}

void Application::Render() {}

void Application::KeyInput() {}
