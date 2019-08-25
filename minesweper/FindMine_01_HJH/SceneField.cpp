#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "SceneField.h"
#include "Scene.h"

SceneField::SceneField(SceneManager * _instance) : Scene(_instance) {

	Field = new shell*[Y()];
	for (int i = 0;i < Y();++i) { Field[i] = new shell[X()]; }
}

SceneField::~SceneField() {

	for (int i = 0;i < Y();++i) { SAFE_ARR(Field); }
	SAFE(Field);
}

void SceneField::Begin() {

	system("cls");
	SetConsoleSize();
	draw();
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
		dis(0, height() - 2);cout << this;
		dis(0, height() - 1);cout << manager_instance;
	}

	refresh = false;
} // Render

void SceneField::KeyInput() {

	if (GetAsyncKeyState('E') & 0x0001) {

		if (click == 0) { Setting(cur.x, cur.y); }	// 처음 클릭시 셋팅

		stepped((Field[cur.y][cur.x].type == shell_t::mine));

		Field[cur.y][cur.x].sweeped = true;
		//sweeping(cur.x, cur.y);
		click++;

		refresh = true;
	} // E	// sweeping

	if (GetAsyncKeyState('Q') & 0x0001) {

		if (Field[cur.y][cur.x].sweeped == false)Field[cur.y][cur.x].flag = !Field[cur.y][cur.x].flag;

		refresh = true;
	} // Q	// flag reverse

	if ((GetAsyncKeyState(VK_UP) & 0x0001) || (GetAsyncKeyState('W') & 0x0001)) { if (cur.y > 0)	cur.y--;	refresh = true; }
	if ((GetAsyncKeyState(VK_DOWN) & 0x0001) || (GetAsyncKeyState('S') & 0x0001)) { if (cur.y < Y() - 1)	cur.y++;	refresh = true; }
	if ((GetAsyncKeyState(VK_LEFT) & 0x0001) || (GetAsyncKeyState('A') & 0x0001)) { if (cur.x > 0)	cur.x--;	refresh = true; }
	if ((GetAsyncKeyState(VK_RIGHT) & 0x0001) || (GetAsyncKeyState('D') & 0x0001)) { if (cur.x < X() - 1)	cur.x++;	refresh = true; }

	//cheat
	if (GetAsyncKeyState(VK_NUMPAD1) & 0x0001) {	// sweep reverse
		for (int y = 0; y < Y();++y) {
			for (int x = 0; x < X();++x) {
				Field[y][x].sweeped = !Field[y][x].sweeped;
				refresh = true;
			}
		}
	}
	if (GetAsyncKeyState(VK_NUMPAD2) & 0x0001) {	// show mine
		for (int y = 0; y < Y();++y) {
			for (int x = 0; x < X();++x) {
				if (Field[y][x].type == shell_t::mine && Field[y][x].sweeped == false) {
					// logic
				}
				refresh = true;
			}
		}
	}

} // KeyInput

scene_t SceneField::get_SceneType() { return scene_t::Field; }

void SceneField::Setting(int _x, int _y) {

	int count = static_Data.mine;

	while (count) {

		int x = rand() % X();
		int y = rand() % Y();

		if (Field[y][x].type != shell_t::mine && !(x == _x && y == _y)) {
			// 클릭한 위치가 아니면서 지뢰가 아닐 때
			Field[rand() % Y()][rand() % X()].type = shell_t::mine; count--;
		}
	}

	for (int y = 0; y < Y(); ++y) {

		for (int x = 0; x < X(); ++x) {

			if (Field[y][x].type == shell_t::empty) { Field[y][x].type = check(x, y); }
		}
	}
} // Setting

shell_t SceneField::check(int _x, int _y) { return shell_t::empty; }

void SceneField::draw() {

	clr();

	dis(width() / 2 - 7); cout << "This MineField";
	dis((width()) - (11), height() - 1); cout << "HJH made";

	for (int y = 0; y < Y(); ++y) {

		dis((width() - X() * 2) / 2, 5 + y);

		for (int x = 0; x < X(); ++x) {

			draw_f(x, y);
		}
	}
} // draw

void SceneField::draw_f(int _x, int _y) {
	if (cur.x == _x && cur.y == _y) {

		if (Field[cur.y][cur.x].sweeped == false) {

			if (Field[cur.y][cur.x].flag) { clr(Color::d_red, Color::gray);	cout << "Ｘ"; }
			else { clr(Color::white, Color::gray); cout << "■"; }
		}

		else {
			switch (Field[cur.y][cur.x].type)
			{
			case shell_t::empty:	clr(Color::gray, Color::gray);				cout << "  ";	break;
			case shell_t::one:		clr(Color::d_gray, Color::gray);			cout << "１";	break;
			case shell_t::two:		clr(Color::d_green, Color::gray);			cout << "２";	break;
			case shell_t::three:	clr(Color::d_blue, Color::gray);			cout << "３";	break;
			case shell_t::four:		clr(Color::yellow, Color::gray);			cout << "４";	break;
			case shell_t::five:		clr(Color::d_violet, Color::gray);			cout << "５";	break;
			case shell_t::six:		clr(Color::sky, Color::gray);				cout << "６";	break;
			case shell_t::seven:	clr(Color::blue, Color::gray);				cout << "７";	break;
			case shell_t::eight:	clr(Color::green, Color::gray);				cout << "８";	break;
			case shell_t::mine:		clr(Color::black, Color::red);				cout << "⊙";	break;
			}
		}
	}

	else {

		clr();

		if (Field[_y][_x].sweeped == false) {

			if (Field[_y][_x].flag) { clr(Color::red, Color::white); cout << "Ｘ"; clr(); }

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
			case shell_t::mine:		clr(Color::black, Color::red);	cout << "⊙";	break;
			default:cout << "？"; break;
			}
		}
	}
} // draw_f

void SceneField::sweeping(int _x, int _y) {}

void SceneField::stepped(bool _step) {

	if (_step) {
		for (int y = 0; y < Y(); ++y) {

			for (int x = 0; x < X(); ++x) {

				if (Field[y][x].type == shell_t::mine) {

					dis(((width() - X() * 2) / 2) + x * 2, 5 + y);
					clr(Color::black, Color::red);
					cout << "⊙";
				}
			}
		}
		clr();
		dis(0, height() - 2);
		system("pause");

		manager_instance->SceneChange(scene_t::Field);
		// 아무것도 초기화 되지 않음
	}
}
