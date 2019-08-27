#include "pch.h"

#include "Application.h"

int main() {

	Application* pApp = new Application();
	pApp->Run();
	SAFE_DELETE(pApp);
}
