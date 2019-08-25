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
		//dis(cur.x, cur.y); Ŀ����ġ ���� ����
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

	// ���� ��ġ��(_x , _y) ��ĭ�̸� ��� �Լ��� ȣ��Ǿ� ���� sweep �Ѵ�
	if (Field[_y][_x].sweeped == false && Field[_y][_x].type == shell_t::empty) {	// ��ĭ ���� sweep 

		for (int y = _y - 1;y <= _y + 1;++y) {

			for (int x = _x - 1;x <= _x + 1;++x) {

				if (&Field[x][y] != nullptr) {
					Field[x][y].sweeped = true;
					stepped(Field[x][y].sweeped);
					sweeping(x, y);
				}
			}
		}
	}// ����� �����Ѵ� (�ֿ켱����)

	// ���� ��ġ��(_x , _y) sweeping �� �����̸� ����� ã�� ������ sweeping
	else if (Field[_y][_x].sweeped && Field[_y][_x].type != shell_t::empty) {	// ���� ���� sweep

		bool onflag = false;

		for (int y = _y - 1;y <= _y + 1;++y) {
			for (int x = _x - 1;x <= _x + 1;++x) {
				if (Field[x][y].flag) { onflag = true; }	// �ֺ� 9ĭ ��� �˻�
			}
		}

		if (onflag) {	// ����� ����
			for (int y = _y - 1;y <= _y + 1;++y) {

				for (int x = _x - 1;x <= _x + 1;++x) {

					if (((Field[_y][_x].flag == false) && (Field[x][y].sweeped = false) && (&Field[x][y] != nullptr))) {	// ����� ���� ��

						Field[x][y].sweeped = true;
						stepped(Field[x][y].sweeped);
					}
				}
			}
		}
		//
	}
}// �ߺ��ڵ����̱�...

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

		if (Field[_y][_x].flag) { clr(Color::red, Color::white);cout << "��";clr(); }

		else { cout << "��"; }
	}

	else {

		switch (Field[_y][_x].type)
		{
		case shell_t::empty:									cout << "  ";	break;
		case shell_t::one:		clr(Color::d_gray);				cout << "��";	break;
		case shell_t::two:		clr(Color::d_green);			cout << "��";	break;
		case shell_t::three:	clr(Color::d_blue);				cout << "��";	break;
		case shell_t::four:		clr(Color::yellow);				cout << "��";	break;
		case shell_t::five:		clr(Color::d_violet);			cout << "��";	break;
		case shell_t::six:		clr(Color::sky);				cout << "��";	break;
		case shell_t::seven:	clr(Color::blue);				cout << "��";	break;
		case shell_t::eight:	clr(Color::green);				cout << "��";	break;
		case shell_t::mine:		clr(Color::black, Color::red);	cout << "��";	break;
		default:cout << "��";break;
		}
	}
} // draw_field

/*
-���� ����

1.sweep Ŭ��

1-1. sweep ��	// ���������� sweep �� ���� �ֺ��� ���ڰ� �־� ���ڸ� ����� ĭ ���̴�.
��ĭ - X
������ -
������ 9 ĭ ���� ��
����� ���� - ����� ������ ������ĭ sweep
����� ���� - (� ĭ�� sweep ���� �����ִ� ����) ��������

1-2. sweep �ȵ�
���� - sweep �ϰ� ���� ���� ����
��ĭ - sweep �ϰ� ���� sweep ����
������ - sweep ��

2.����
sweeping �Լ��� �����ϴ� ���°� ������ ����

typename sweeping()

typename::a >> unsigned int Aclick++
typename::b >> unsigned int Bclick++
typename::c >> unsigned int Cclick++

-������ ��

ù sweep �� Field �ʱ�ȭ �Լ�
����sweepg �Լ�
���� sweep �� ���� ���� �Լ�





*/

