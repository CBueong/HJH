#include "pch.h"
#include "Define.h"
#include "vld.h"

#include "Application.h"

int main() {	

	Application * App = new Application;

	App->Run();

	SAFE(App);

	return 0;
}
