/*
▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨ ▨
▨                                                                    ▨
▨                                                                    ▨
▨                                                                    ▨
▨                                                                    ▨
▨                                                                    ▨
▨          =====    =====    =====   =   =    =     ===              ▨
▨            =      =          =     =  =     =    =    =            ▨
▨            =      =====      =     = =      =     ===              ▨
▨            =      =          =     =        =        =             ▨
▨            =      =====      =     =        =    ====              ▨
▨                                                                    ▨
▨                                                                    ▨
▨                                                                    ▨
▨                                                                    ▨
▨                          created by Mink                           ▨
▨                                                                    ▨
▨                                                                    ▨
▨                                                                    ▨
▨                           enter any key..                          ▨
▨                                                                    ▨
▨                                                                    ▨
▨                                                                    ▨
▨                                                                    ▨
▨                                                                    ▨
▨                                                                    ▨
▨                                                                    ▨
▨                                  ☆                                ▨
▨                                  **                                ▨
▨                                 ****                               ▨
▨                                ******                              ▨
▨                               ********                             ▨
▨                              **********                            ▨
▨                             ************                           ▨
▨                            **************                          ▨
▨                           ****************                         ▨
▨                          ******************                        ▨
▨                                  ▩                                ▨
▨                                  ▩                                ▨
▨                                  ▩                                ▨
▨                                  ▩                                ▨
▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨ ▨▨
*/


#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>
#define LEFT 75 //좌로 이동    //키보드값들 
#define RIGHT 77 //우로 이동 
#define UP 72 //회전 
#define DOWN 80 //soft drop
#define SPACE 32 //hard drop
#define p 112 //일시정지 
#define P 80 //일시정지
#define ESC 27 //게임종료 
#define NOCONDITION -7
#define FRAMEBLOCK -1
#define EMPTYBLOCK 0
#define FREEZEDBLOCK 2
#define FLOORBLOCK 3
#define ACTIVE_BLOCK 1
#define INACTIVE_BLOCK 5
#define Ceiling 4
#define true 1
#define false 2
#define gameboard_x 14
#define gameboard_y 25
#define offset_x 1
#define offset_y 1
int _startflag = true;
int _gameflag = true;
int _Rotating = false;
int key = 0;
int block_x = 0;
int block_y = 0;
int pre_key = 0;
int blocks[7][4][4][4] = {
	{ { 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },
	{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 } },
	{ { 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 },{ 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 },{ 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 } },
	{ { 0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0 },
	{ 0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0 } },
	{ { 0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0 },{ 0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0 },
	{ 0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0 },{ 0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0 } },
	{ { 0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0 } },
	{ { 0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0 },{ 0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0 } },
	{ { 0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0 },{ 0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0 } }
};
int myBlocks[4][4];
int gameboard[gameboard_x][gameboard_y];
int gameboard_cpy[gameboard_x][gameboard_y];
int rotation = 0;
int block_type = 6;
int status = 0;
int _newblock = false;
int _crush = false;
int _drop = false;
int _harddrop = false;
void rotate();
void gotoxy(int x, int y)
{
	COORD Pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//박스를 보여주는 함수


typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //커서숨기는 함수에 사용되는 열거형 

void setcursortype(CURSOR_TYPE c) { //커서숨기는 함수 
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}


void set_gameboard(void) {

	int i = 0; int j = 0;

	for (i = 0; i<gameboard_x; i++) {
		for (j = 0; j < gameboard_y; j++) {
			gameboard[i][j] = 0;
		}
	}// 0으로 초기화 


	for (int i = 0; i < gameboard_y; i++) {
		gameboard[0][i] = FREEZEDBLOCK;
	}
	for (int i = 0; i < gameboard_y; i++) {
		gameboard[gameboard_x - 1][i] = FREEZEDBLOCK;
	}// 좌우 벽 생성


	for (int i = 0; i < gameboard_x; i++) {
		gameboard[i][gameboard_y - 1] = FLOORBLOCK;
	}// 바닥 생성
	for (int i = 0; i < gameboard_x; i++) {
		gameboard[i][0] = Ceiling;
	}


}

int crush_check(int condition) {

	int i = 0;
	int j = 0;
	int  x = 0;
	int y = 0;
	int upCondition = false;
	switch (condition)
	{
	case LEFT:
		x = -1;
		break;
	case RIGHT:
		x = +1;
		break;
	case DOWN:
		y = +1;
		break;
	case UP:
		upCondition = true;

	}


	if ((condition == LEFT || condition == RIGHT || condition == DOWN) && upCondition == false) {
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if (gameboard[block_x + i][block_y + j] == ACTIVE_BLOCK) {
					if (gameboard[block_x + i + x][block_y + j + y] == FREEZEDBLOCK) { _crush = true; return FREEZEDBLOCK; }
					else if (gameboard[block_x + i + x][block_y + j + y] == FLOORBLOCK) { _crush = true; return FLOORBLOCK; }
					else if (gameboard[block_x + i + x][block_y + j + y] == INACTIVE_BLOCK) { _crush = true; return INACTIVE_BLOCK; }
					// else if (gameboard[block_x + i + x][block_y + j + y] == FRAMEBLOCK) {_crush=true; return FRAMEBLOCK; }
					else if (gameboard[block_x + i + x][block_y + j + y] == Ceiling) { _crush = true; status = Ceiling; return Ceiling; }

				}
			}
		}
	}
	else if (upCondition == true) {
		_Rotating = true;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (gameboard[block_x + i][block_y + j] == ACTIVE_BLOCK)
					gameboard[block_x + i][block_y + j] = EMPTYBLOCK;

			}
		}

		rotation = (rotation + 1) % 3;

		int y = 0;
		int x = 0;


		for (int i = 0; i<4; i++) {
			for (int j = 0; j < 4; j++) {
				if (blocks[block_type][rotation][i][j] == 1 && gameboard[block_x + i + x][block_y + j + y] == INACTIVE_BLOCK) {
					y--;
					_crush = true;
					i = 0;
					j = 0;
					break;
				}
				if (blocks[block_type][rotation][i][j] == 1 && gameboard[block_x + i + x][block_y + j + y] == FLOORBLOCK) {
					y--;
					_crush = true;
					i = 0;
					j = 0;
					break;
				}
				if (blocks[block_type][rotation][i][j] == 1 && gameboard[block_x + i + x][block_y + j + y] == FREEZEDBLOCK && block_x <= 5) {
					x++;
					_crush = true;
					i = 0;
					j = 0;
					break;
				}
				if (blocks[block_type][rotation][i][j] == 1 && gameboard[block_x + i + x][block_y + j + y] == FREEZEDBLOCK && block_x > 5) {
					x--;
					_crush = true;
					i = 0;
					j = 0;
					break;
				}
			}
		}

		block_x += x;
		block_y += y;


	}//up condition end


	return true;

}


void draw_gameboard(void) {

	for (int i = 0; i < gameboard_x; i++) {

		for (int j = 0; j < gameboard_y; j++) {

			if (gameboard[i][j] != gameboard_cpy[i][j]) {
				gameboard_cpy[i][j] = gameboard[i][j];
				int condition = gameboard[i][j];
				gotoxy((offset_x + i), (offset_y + j));
				switch (condition)
				{
				case FREEZEDBLOCK:
					printf("▩");
					break;
				case FLOORBLOCK:
					printf("▩");
					break;
				case EMPTYBLOCK:
					printf("  ");
					break;
				case Ceiling:
					printf(". ");
					break;
				case INACTIVE_BLOCK:
					printf("□");
					break;
				case ACTIVE_BLOCK: //움직이고있는 블럭 모양  
					printf("■");
					break;
				}
			}
		}
	}
}
void move_blocks(int condition) {
	int x = 0;
	int y = 0;
	switch (condition)
	{
	case LEFT:
		x = -1;
		break;
	case RIGHT:
		x = +1;
		break;
	case DOWN:
		y = +1;
		break;

	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (blocks[block_type][rotation][i][j] == 1) {
				gameboard[block_x + i][block_y + j] = EMPTYBLOCK;
			}

		}
	}
	block_x += x;
	block_y += y;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (blocks[block_type][rotation][i][j] == 1) {
				gameboard[block_x + i][block_y + j] = ACTIVE_BLOCK;
			}

		}
	}

}
void make_inactive() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (gameboard[block_x + i][block_y + j] == ACTIVE_BLOCK)
				gameboard[block_x + i][block_y + j] = INACTIVE_BLOCK;

		}
	}
	_newblock = true;
}
void drop() {
	if (_crush == true)
		return;
	int condition = crush_check(DOWN);
	if (_crush == false || condition == true) {
		move_blocks(DOWN);
	}
	else if (condition == FLOORBLOCK || condition == INACTIVE_BLOCK) {
		make_inactive();
	}
}
void harddrop() {
	int condition = 0;
	condition = crush_check(DOWN);
	while (_crush == false || condition == true) {
		move_blocks(DOWN);
		condition = crush_check(DOWN);

		if (condition == FLOORBLOCK || condition == INACTIVE_BLOCK) {
			make_inactive();
			condition = false;

		}
	}

}

void key_check() {
	key = 0;
	if (_crush == true)
		return;
	if (kbhit()) {

		key = getch();
		if (key == 224) {
			do {
				key = getch();
			} while (key == 224);

			switch (key)
			{
			case LEFT:
				//	printf("LEFT KEY Check");
				if (crush_check(LEFT) == true) {
					move_blocks(LEFT);
					pre_key = LEFT;
				}
				break;
			case RIGHT:
				//printf("Right KEY Check");
				if (crush_check(RIGHT) == true) {
					move_blocks(RIGHT);
					pre_key = RIGHT;
				}
				break;
			case UP:
				//printf("UP KEY Check");


				if (crush_check(UP))
					rotate();

				pre_key = UP;
				break;
			case DOWN:
				//	printf("DOWN KEY Check");
				pre_key = DOWN;
				if (_drop == true)
					return;
				else
				{
					_drop = true;
					drop();
				}
				break;

			}

			while (kbhit()) getch();
		}
		else {
			switch (key)
			{
			case SPACE:
				if (_drop == true) {
					return;
				}
				else {
					_drop = true;
					_harddrop = true;
					harddrop();
				}
				break;
			}
			while (kbhit()) getch();
		}



	}// kbhit if 문 end 


	while (kbhit()) getch();

}



void make_block() {
	block_x = (gameboard_x + offset_x) / 2 - 1;
	block_y = offset_y;
	block_type = rand() % 6;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (blocks[block_type][rotation][i][j] == 1) {
				gameboard[block_x + i][block_y + j] = ACTIVE_BLOCK;
			}

		}
	}
}

void drop_Block() {

}

void rotate() {


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (blocks[block_type][rotation][i][j] == 1) {
				gameboard[block_x + i][block_y + j] = ACTIVE_BLOCK;
			}

		}
	}

}

void check_lines() {

	int lineCollector[gameboard_y];
	int cnt = 0;
	int gameboardRedifined[gameboard_x][gameboard_y];

	int i = 0; int j = 0;

	for (i = 0; i<gameboard_x; i++) {
		for (j = 0; j < gameboard_y; j++) {
			gameboardRedifined[i][j] = 0;
		}
	}// 0으로 초기화 


	for (int i = 0; i < gameboard_y; i++) {
		gameboardRedifined[0][i] = FREEZEDBLOCK;
	}
	for (int i = 0; i < gameboard_y; i++) {
		gameboardRedifined[gameboard_x - 1][i] = FREEZEDBLOCK;
	}// 좌우 벽 생성


	for (int i = 0; i < gameboard_x; i++) {
		gameboardRedifined[i][gameboard_y - 1] = FLOORBLOCK;
	}// 바닥 생성
	for (int i = 0; i < gameboard_x; i++) {
		gameboardRedifined[i][0] = Ceiling;
	}


	for (int i = 0; i < gameboard_y - 1; i++) {
		int linechecker = 0;
		for (int j = 1; j < gameboard_x - 1; j++) {
			if (gameboard[j][i] == INACTIVE_BLOCK)
				linechecker++;
		}
		if (linechecker == 12)
		{
			lineCollector[cnt++] = i;
		}
	}


	if (cnt > 0) {

		for (int i = gameboard_y - 1; i >0; i--) {
			if (lineCollector[cnt] != i) {
				for (int j = 1; j < gameboard_x - 1; j++) {
					gameboardRedifined[j][i] = gameboard[j][i];
				}
			}
			else if (lineCollector[cnt] == i) {
				cnt--;
			}
		}


		for (int i = 1; i < gameboard_y - 1; i++) {
			for (int j = 1; j < gameboard_x - 1; j++) {

				gameboard[j][i] = gameboardRedifined[j][i];
			}
		}

	}

}
void set_main() {
	system("mode con:cols=73  lines=42");
	printf("▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨          =====    =====    =====   =   =    =     ===              ▨\n");
	printf("▨            =      =          =     =  =     =    =    =            ▨\n");
	printf("▨            =      =====      =     = =      =     ===              ▨\n");
	printf("▨            =      =          =     =        =        =             ▨\n");
	printf("▨            =      =====      =     =        =    ====              ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                         created by Mink                            ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                          enter any key..                           ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨                               ☆                                   ▨\n");
	printf("▨                               **                                   ▨\n");
	printf("▨                              ****                                  ▨\n");
	printf("▨                             ******                                 ▨\n");
	printf("▨                            ********                                ▨\n");
	printf("▨                           **********                               ▨\n");
	printf("▨                          ************                              ▨\n");
	printf("▨                         **************                             ▨\n");
	printf("▨                        ****************                            ▨\n");
	printf("▨                       ******************                           ▨\n");
	printf("▨                               ▩                                   ▨\n");
	printf("▨                               ▩                                   ▨\n");
	printf("▨                               ▩                                   ▨\n");
	printf("▨                               ▩                                   ▨\n");
	printf("▨                                                                    ▨\n");
	printf("▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨\n");


	/*
	▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨          =====    =====    =====   =   =    =     ===              ▨
	▨            =      =          =     =  =     =    =    =            ▨
	▨            =      =====      =     = =      =     ===              ▨
	▨            =      =          =     =        =        =             ▨
	▨            =      =====      =     =        =    ====              ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                          created by Mink                           ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                           enter any key..                          ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                                                                    ▨
	▨                                  ☆                                ▨
	▨                                  **                                ▨
	▨                                 ****                               ▨
	▨                                ******                              ▨
	▨                               ********                             ▨
	▨                              **********                            ▨
	▨                             ************                           ▨
	▨                            **************                          ▨
	▨                           ****************                         ▨
	▨                          ******************                        ▨
	▨                                  ▩                                ▨
	▨                                  ▩                                ▨
	▨                                  ▩                                ▨
	▨                                  ▩                                ▨
	▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨
	*/
}


int main(void) {


	setcursortype(NOCURSOR);
	set_main();
	while (_startflag) {
		if (kbhit())
		{
			_startflag = -1;
			system("cls");
			break;
		}
	}
	while (kbhit())getch();

	set_gameboard();
	draw_gameboard();

	make_block();

	Sleep(200);


	while (1) {


		for (int i = 0; i < 5; i++) {

			key_check();

			draw_gameboard();
			if (_crush == true && _Rotating == true)
				Sleep(150);

			if (pre_key == DOWN || _crush == true || _Rotating == false) {
				i = 4;
				break;

			}

		}

		check_lines();

		// for loop 추가로 넣어서 key 여러번 받을수 있게하고 그때마다  화면 그림 
		//key_check , draw gameboard  
		Sleep(16);
		//	move_blocks(NOCONDITION);
		if (_harddrop == false || _crush == false)
			drop();

		draw_gameboard();
		_drop = false;
		_harddrop = false;
		_crush = false;
		_Rotating = false;

		if (_newblock == true) { make_block(); _newblock = false; }
		pre_key = 0;
		//if 문을 통해 newblock Check ~
		Sleep(100);

	}// while end


	return 0;

}
