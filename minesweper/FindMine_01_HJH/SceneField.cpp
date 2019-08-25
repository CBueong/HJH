#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "SceneField.h"
#include "Scene.h"

SceneField::SceneField(SceneManager * _instance) : Scene(_instance) {

	Field = new shell*[Y()];
	for (int i = 0;i < width();++i) { Field[i] = new shell[X()]; }

	//srand(time(NULL));
}

SceneField::~SceneField() {

	for (int i = 0;i < width();++i) { SAFE_ARR(Field); }
	SAFE(Field);
}

void SceneField::Begin() {

	system("cls");
	SetConsoleSize();
	draw();
	system("pause");
} // Begin

bool SceneField::Update() {

	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) {
		manager_instance->SceneChange(scene_t::Intro);
	}
	return true;
} // Update

void SceneField::Render() {

	if (refresh) {
		draw();
		//dis(cur.x, cur.y); 커서위치 배경색 변경
	}
	refresh = false;
} // Render

void SceneField::KeyInput() {

	if (GetAsyncKeyState('E') & 0x0001) {

		if (click == 0) { Setting(cur.x, cur.y); }	// Field define

		sweeping(cur.x, cur.y);
		click++;

		refresh = true;
	} // E

	if (GetAsyncKeyState('Q') & 0x0001) {

		Field[cur.y][cur.x].flag = !Field[cur.y][cur.x].flag;	// flag reverse

		refresh = true;
	} // Q

	if ((GetAsyncKeyState(VK_UP) & 0x0001) || (GetAsyncKeyState('W') & 0x0001)) { if (cur.y > 0)cur.y--; }
	if ((GetAsyncKeyState(VK_DOWN) & 0x0001) || (GetAsyncKeyState('S') & 0x0001)) { if (cur.y < Y())cur.y++; }
	if ((GetAsyncKeyState(VK_LEFT) & 0x0001) || (GetAsyncKeyState('A') & 0x0001)) { if (cur.x > 0)cur.x--; }
	if ((GetAsyncKeyState(VK_RIGHT) & 0x0001) || (GetAsyncKeyState('D') & 0x0001)) { if (cur.x < X())cur.x++; }
} // KeyInput

scene_t SceneField::get_SceneType() { return scene_t::Field; }

// rough main logic !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void SceneField::Setting(int _x, int _y) {

	unsigned int count = static_Data.mine;

	while (count) {

		for (int y = 0; y < Y();++y) {

			for (int x = 0; x < X();++x) {

				if (&Field[x][y] != nullptr) {

					if (rand() % (X()*Y()) == 0) { Field[y][x].type = shell_t::mine;count--; }	//

					if (x == _x && y == _y) {} // setting expetion cur pos
				}
			}
		}
	}

	for (int y = 0; y < Y();++y) {

		for (int x = 0; x < X();++x) {

			if (&Field[x][y] != nullptr) { Field[y][x].type = check(x, y); }
		}
	}
} // Setting

shell_t SceneField::check(int _x, int _y) {

	int count = 0;

	for (int y = _y - 1;y <= _y + 1;++y) {

		for (int x = _x - 1;x <= _x + 1;++x) {

			if (Field[y][x].type == shell_t::mine) { count++; }
		}
	}

	return (shell_t)count;
}


void SceneField::sweeping(int _x, int _y) {

	// 지금 위치가(_x , _y) 빈칸이면 재귀 함수로 호출되어 연쇄 sweep 한다
	if (Field[_y][_x].sweeped == false && Field[_y][_x].type == shell_t::empty) {	// 빈칸 연쇄 sweep 

		for (int y = _y - 1;y <= _y + 1;++y) {

			for (int x = _x - 1;x <= _x + 1;++x) {

				if (&Field[x][y] != nullptr) {
					Field[x][y].sweeped = true;
					stepped(Field[x][y].sweeped);
					sweeping(x, y);
				}
			}
		}
	}// 깃발을 무시한다 (최우선순위)

	// 지금 위치가(_x , _y) sweeping 된 숫자이면 깃발을 찾고 있으면 sweeping
	else if (Field[_y][_x].sweeped && Field[_y][_x].type != shell_t::empty) {	// 숫자 연쇄 sweep

		bool onflag = false;

		for (int y = _y - 1;y <= _y + 1;++y) {
			for (int x = _x - 1;x <= _x + 1;++x) {
				if (Field[x][y].flag) { onflag = true; }	// 주변 9칸 깃발 검사
			}
		}

		if (onflag) {	// 깃발이 있음
			for (int y = _y - 1;y <= _y + 1;++y) {

				for (int x = _x - 1;x <= _x + 1;++x) {

					if (((Field[_y][_x].flag == false) && (Field[x][y].sweeped = false) && (&Field[x][y] != nullptr))) {	// 깃발이 없는 곳

						Field[x][y].sweeped = true;
						stepped(Field[x][y].sweeped);
					}
				}
			}
		}
		//
	}
}// 중복코딩줄이기...

void SceneField::stepped(bool _step) {
	//gameover
}

void SceneField::draw() {

	clr();

	dis(width() / 2 - 7);cout << "This MineField";
	dis((width()) - (11), height() - 1);cout << "HJH made";

	for (int y = 0; y < Y();++y) {

		dis((width() - X() * 2) / 2, 5 + y);

		for (int x = 0; x < X();++x) {

			//if ((x == cur.x) && (y == cur.y)) { clr(Color::white, Color::gray);draw_f(x, y); }

			draw_f(x, y);
		}
	}
} // draw

void SceneField::draw_f(int _x, int _y) {

	if (Field[_y][_x].sweeped == false) {

		if (Field[_y][_x].flag) { clr(Color::red, Color::white);cout << "Ｘ";clr(); }

		else { cout << "■"; }
	}

	else {

		switch (Field[_y][_x].type)
		{
		case shell_t::empty:									cout << "  ";	break;
		case shell_t::one:		clr(Color::d_gray);				cout << "１";	break;
		case shell_t::two:		clr(Color::d_green);			cout << "２";	break;
		case shell_t::three:	clr(Color::d_blue);				cout << "３";	break;
		case shell_t::four:		clr(Color::yellow);				cout << "４";	break;
		case shell_t::five:		clr(Color::d_violet);			cout << "５";	break;
		case shell_t::six:		clr(Color::sky);				cout << "６";	break;
		case shell_t::seven:	clr(Color::blue);				cout << "７";	break;
		case shell_t::eight:	clr(Color::green);				cout << "８";	break;
		case shell_t::mine:		clr(Color::black, Color::red);	cout << "¤";	break;
		default:cout << "？";break;
		}
	}
} // draw_field

/*
-로직 순서

1.sweep 클릭

1-1. sweep 됨	// 정상적으로 sweep 된 경우는 주변에 지뢰가 있어 숫자를 기록한 칸 뿐이다.
빈칸 - X
나머지 -
전방향 9 칸 조사 후
깃발이 있음 - 깃발을 제외한 나머지칸 sweep
깃발이 없음 - (어떤 칸이 sweep 된지 보여주는 연출) 구현안함

1-2. sweep 안됨
지뢰 - sweep 하고 게임 종료 연출
빈칸 - sweep 하고 연쇄 sweep 실행
나머지 - sweep 함

2.점수
sweeping 함수가 리턴하는 상태값 에따라 증분

typename sweeping()

typename::a >> unsigned int Aclick++
typename::b >> unsigned int Bclick++
typename::c >> unsigned int Cclick++

-구현할 것

첫 sweep 시 Field 초기화 함수
연쇄sweepg 함수
지뢰 sweep 시 종료 연출 함수





*/

