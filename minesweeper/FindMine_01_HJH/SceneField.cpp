#include "pch.h"
#include "Define.h"
#include "SceneManager.h"
#include "SceneField.h"
#include "Scene.h"

SceneField::SceneField(SceneManager * _instance) : Scene(_instance) {

	srand(time(NULL));

	static_Data = manager_instance->data;

	Field = new shell*[Y()];
	for (int i = 0; i < Y(); ++i) { Field[i] = new shell[X()]; }
}

SceneField::~SceneField() {

	for (int i = 0; i < Y(); ++i) { SAFE_ARR(Field); }
	SAFE(Field);

} // delete **arr but lick alive...

void SceneField::Begin() {

	cur.x = 0, cur.y = 0;
	click = 0;
	mine_check = 0;

	system("cls");
	SetConsoleSize();
	draw();
} // Begin

bool SceneField::Update() {

	if (end) {
		manager_instance->SceneChange(scene_t::Intro);
		return true;
	}

	if (mine_check == (X()*Y()) - static_Data.mine) {
		End(true);
	}// win condition check		

	return true;
} // Update

void SceneField::Render() {

	if (refresh) {
		draw();
		dis(0, height() - 2); cout << "scene   :" << this;
		dis(0, height() - 1); cout << "manager :" << manager_instance;

		dis(width() - 5, height() - 2); cout << mine_check;
		// sweeped count
	}

	refresh = false;
} // Render

void SceneField::KeyInput() {

	if (GetAsyncKeyState('E') & 0x0001) {

		if (click == 0) { LandingMine(cur.x, cur.y); }	// only first click

		//Field[cur.y][cur.x].sweeped = true;		
		sweepping(cur.x, cur.y);
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

	if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) {
		manager_instance->SceneChange(scene_t::Intro);
	}// ESC // back to Intro

	//cheat
	if (GetAsyncKeyState(VK_NUMPAD1) & 0x0001) {	// sweep reverse	
		for (int y = 0; y < Y(); ++y) {
			for (int x = 0; x < X(); ++x) {
				Field[y][x].sweeped = !Field[y][x].sweeped;
				refresh = true;
			}
		}
	}

	if (GetAsyncKeyState(VK_NUMPAD2) & 0x0001) {
		// custom cheat		
	}

} // KeyInput

scene_t SceneField::get_SceneType() { return scene_t::Field; }

void SceneField::LandingMine(int _x, int _y) {

	int count = static_Data.mine;

	while (count) {

		int x = rand() % X();
		int y = rand() % Y();

		if (Field[y][x].type != shell_t::mine && (x != _x && y != _y)) {

			Field[y][x].type = shell_t::mine; count--;
			//mine set here
		}
	}

	for (int y = 0; y < Y(); ++y) {

		for (int x = 0; x < X(); ++x) {

			if (Field[y][x].type == shell_t::empty) { Field[y][x].type = check(x, y); }
			//number set here
		}
	}
} // Setting

SceneField::shell_t SceneField::check(int _x, int _y) {

	unsigned int count = 0;

	for (int y = _y - 1; y <= _y + 1; ++y) {
		for (int x = _x - 1; x <= _x + 1; ++x) {

			if ((0 <= x) && (x < X()) && (0 <= y) && (y < Y())) {
				if (Field[y][x].type == shell_t::mine) { count++; }
			}
		}
	}
	return (shell_t)count;
}// check near mine count

void SceneField::draw() {

	clr();

	dis(width() / 2 - 7); cout << "This MineField";
	dis((width()) - (11), height() - 1); cout << "HJH made";

	for (int y = 0; y < Y(); ++y) {

		dis((width() - X() * 2) / 2, 5 + y);

		for (int x = 0; x < X(); ++x) {

			draw_shell(x, y);//pass
		}
	}
} // draw

void SceneField::draw_shell(int _x, int _y) {

	if (cur.x == _x && cur.y == _y) {

		if (Field[cur.y][cur.x].sweeped == false) {

			if (Field[cur.y][cur.x].flag) { clr(Color::d_red, Color::gray);	cout << "Ｘ"; }
			else { clr(Color::white, Color::gray); cout << "■"; }
		}

		else {
			switch (Field[cur.y][cur.x].type)
			{
			case shell_t::empty:	clr(Color::gray, Color::gray);	cout << "  ";	break;
			case shell_t::one:		clr(Color::d_gray, Color::gray);	cout << "１";	break;
			case shell_t::two:		clr(Color::d_green, Color::gray);	cout << "２";	break;
			case shell_t::three:	clr(Color::d_blue, Color::gray);	cout << "３";	break;
			case shell_t::four:		clr(Color::yellow, Color::gray);	cout << "４";	break;
			case shell_t::five:		clr(Color::d_violet, Color::gray);	cout << "５";	break;
			case shell_t::six:		clr(Color::sky, Color::gray);	cout << "６";	break;
			case shell_t::seven:	clr(Color::blue, Color::gray);	cout << "７";	break;
			case shell_t::eight:	clr(Color::green, Color::gray);	cout << "８";	break;
			case shell_t::mine:		clr(Color::black, Color::red);	cout << "⊙";	break;
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
} // draw_s

void SceneField::sweepping(int _x, int _y) {

	if (Field[_y][_x].flag) { return; }
	// flag can not sweep

	if (Field[_y][_x].sweeped == false) {

		if (Field[_y][_x].type == shell_t::empty) {

			Field[_y][_x].sweeped = true;
			mine_check++;
			//sweep here

			for (int y = _y - 1; y <= _y + 1; ++y) {
				for (int x = _x - 1; x <= _x + 1; ++x) {

					if ((0 <= x) && (x < X()) && (0 <= y) && (y < Y())) {
						sweepping(x, y);
					}//chain sweep
				}
			}
		}// empty

		else if (Field[_y][_x].type == shell_t::mine) { End(false); }
		// mine

		else {
			if ((0 <= _x) && (_x < X()) && (0 <= _y) && (_y < Y())) {
				Field[_y][_x].sweeped = true;
				mine_check++;
			}
		}// empty near mine

	}// sweep false

	else {
		unsigned int flagged = 0;

		for (int y = _y - 1; y <= _y + 1; ++y) {
			for (int x = _x - 1; x <= _x + 1; ++x) {

				if ((0 <= x) && (x < X()) && (0 <= y) && (y < Y())) {
					if (Field[y][x].flag) { flagged++; }
				}
			}
		}// check flag for flip

		if (flagged >= (unsigned int)Field[_y][_x].type) {

			for (int y = _y - 1; y <= _y + 1; ++y) {
				for (int x = _x - 1; x <= _x + 1; ++x) {

					if ((0 <= x) && (x < X()) && (0 <= y) && (y < Y())) {
						if (!Field[y][x].sweeped) { sweepping(x, y); }
					}//chain sweep  (be able to sweepping mine cause flag)
				}
			}
		}//flip

	}// sweep true

	if ((Field[cur.y][cur.x].type == shell_t::mine)) { End(false); }
	// sweep mine ;;
}

void SceneField::End(bool _result) {

	if (_result) {

		for (int y = 0; y < Y(); ++y) {

			for (int x = 0; x < X(); ++x) {

				clr(Color::red, Color::white);

				if (Field[y][x].type == shell_t::mine) {

					dis(((width() - X() * 2) / 2) + x * 2, 5 + y);
					cout << "Ｘ";
				}
			}
		} // show mine to "Ｘ"

		dis(width() / 2 - 2, Y() + 7);
		clr(Color::white);
		cout << "뿌듯";
	}

	else {

		for (int y = 0; y < Y(); ++y) {

			for (int x = 0; x < X(); ++x) {

				clr(Color::red, Color::white);

				if (Field[y][x].type == shell_t::mine) {

					dis(((width() - X() * 2) / 2) + x * 2, 5 + y);
					cout << "⊙";
				}
			}
		} // show mine to "⊙"

		dis(width() / 2 - 5, Y() + 7);
		clr(Color::red);
		cout << "객사했다.";
	}

	clr();

	dis(width() / 2 - 5, Y() + 9);
	cout << "클릭횟수 : " << click;

	dis(0, height() - 2);
	system("pause");

	end = true;
}

/*

로직순서

1. 클릭

2. 맵 초기화
- 클릭한 곳 제외한 곳을 랜덤하게 지뢰로 바꾼다

3. 숫자 세기
- 지뢰가 설치되고 주변에 있는 빈칸들은 주변 9칸의 지뢰 수를 세서 표시한다

4. sweep
- 클릭했던 곳 주변에 지뢰가 없으면 모두 sweep 한다
- 또 그 주변이 빈칸이면 '4번' 반복
- 주변에 지뢰가 있는 숫자칸이면 더 이상 chain sweep 은 하지 않는다

- sweep 되어있고 지뢰가 근처에있는 숫자칸 이면
주변에 깃발이 있는지 확인한다
없으면 주변에서 sweep될 칸을 미리 표시한다(구현안함)
있으면 깃발을 제외한 나머지 주변칸을 sweep 한다
이때 지뢰가있으면 밟힌다. -> '6번' 순서로

5. 지뢰를 제외한 모든 칸이 sweep 되면 승리
6. 지뢰를 swep 하면 패배

7. 승리와 패배는 연출만 다르고 동작은 같다.

*/