#pragma once

class Application
{
public:
	Application();
	~Application();

public:
	bool Launch = true;

	void Run();
	void Begin();
	bool Update();
	void Render();
	void KeyInput();
};

