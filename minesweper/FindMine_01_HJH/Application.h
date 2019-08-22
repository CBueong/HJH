#pragma once
#include "SceneManager.h"

class Application
{
public:
	Application();
	~Application();

public:
	bool Launch = true;

	void Run();
	void Begin();
	void Update();
	void Render();
	void KeyInput();
};

