#include "pch.h"
#include "Define.h"

#include "Application.h"

int main() {

	system("title Mine Sweeper HJH");
	SetConsoleSize();
	SetCursour(false);

	Application * App = new Application;

	App->Run();

	SAFE(App);

	return 0;
}
