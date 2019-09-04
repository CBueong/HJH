// FPS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

#include "Application.h"

int main()
{
	setlocale(LC_ALL, "");
	SetCursorType(CURSOR_TYPE::NOCURSOR);
	srand(time(0));
	Application* pApp = new Application();
	pApp->Run();
	SAFE_DELETE(pApp);

	return 0;
}
