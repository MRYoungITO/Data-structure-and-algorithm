#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include "boxman.h"

IMAGE images[ALL];

POS man;	//小人在二维数组中的位置

int map[LINE][COLUMN] = {
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,1,1,1,1,1,1,0,0},
	{0,1,4,1,0,2,1,0,2,1,0,0},
	{0,1,0,1,0,1,0,0,1,1,1,0},
	{0,1,0,2,0,1,1,4,1,1,1,0},
	{0,1,1,1,0,3,1,1,1,4,1,0},
	{0,1,2,1,1,4,1,1,1,1,1,0},
	{0,1,0,0,1,0,1,1,0,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0}
};

/************************************************************************
* 判断游戏是否结束, 如果不存在箱子目的地, 就代表游戏结束 
* 输入:	无
*返回值:	
*			true - 游戏结束			false - 游戏继续
************************************************************************/
bool isGameOver() {
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < COLUMN; j++) {
			if (map[i][j] == BOX_DES) {
				return false;
			}
		}
	}
	return true;
}

/************************************************************************
* 游戏结束场景, 在玩家通关后显示, 
* 输入:
*				bg - 背景图片变量的指针
*返回值:	无
************************************************************************/
void gameOverScene(IMAGE *bg) {
	putimage(0, 0, bg);
	settextcolor(WHITE);
	RECT rec = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	settextstyle(20, 0, _T("宋体"));
	drawtext(_T("恭喜您~ \n您终于成为了一个合格的搬箱子老司机! "), &rec, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

/************************************************************************
* 游戏失败场景, 在玩家游戏失败时显示,
* 输入:
*				bg - 背景图片变量的指针
*返回值:	无
************************************************************************/
void gameLose(IMAGE *bg) {
	putimage(0, 0, bg);
	settextcolor(WHITE);
	RECT rec = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	settextstyle(20, 0, _T("宋体"));
	drawtext(_T("胜败乃兵家常事, 大侠请重新来过^_^"), &rec, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

/**********************************************************
* 改变游戏地图视图中一格对应道具并重新显示
* 输入:
*			line - 道具在地图数组的行下标
*			colum - 道具在地图数组的列下标
*			prop - 道具的类型
*返回值:	无
**********************************************************/
void changeMap(POS *pos, PROPS prop) {
	map[pos->x][pos->y] = prop;
	putimage(START_X + pos->y * RATIO, START_Y + pos->x * RATIO, &images[prop]);
}

/**********************************************************
* 实现游戏四个方向(上、下、左、右) 的控制
* 输入:
* direct - 人前进方向
* 输出: 无
**********************************************************/
void gameControl(DIRECTION direct) {
	POS next_pos = man;
	POS next_next_pos = man;
	switch (direct) {
	case UP:
		next_pos.x--;
		next_next_pos.x -= 2;
		break;
	case DOWN:
		next_pos.x++;
		next_next_pos.x += 2;
		break;
	case LEFT:
		next_pos.y--;
		next_next_pos.y -= 2;
		break;
	case RIGHT:
		next_pos.y++;
		next_next_pos.y += 2;
		break;
	}
	//宏展开	next_pos.x >= 0 && next_pos.x < LINE && next_pos.y >= 0 && next_pos.y < COLUMN
	if (isValid(next_pos) && map[next_pos.x][next_pos.y] == FLOOR) {		//小人的前方是地板
		changeMap(&next_pos, MAN);		//小人前进一格
		changeMap(&man, FLOOR);			//原小人位置变为地板		//人可以从箱子目的地上走过  changeMap(&man, BOX_DES);
		man = next_pos;								//将当前小人位置赋给之前的小人变量的旧位置
	}
	/*q
	if (isValid(next_pos) && map[next_pos.x][next_pos.y] == BOX_DES) {
		changeMap(&next_pos, MAN);
		changeMap(&man, FLOOR);
		man = next_pos;
	}*/
	if (isValid(next_next_pos) && map[next_pos.x][next_pos.y] == BOX) {	//小人的前方是箱子
		//两种情况, 箱子前面是地板或者是箱子目的地
		if (map[next_next_pos.x][next_next_pos.y] == FLOOR) {
			changeMap(&next_next_pos, BOX);
			changeMap(&next_pos, MAN);
			changeMap(&man, FLOOR);
			man = next_pos;
		}
		else if (map[next_next_pos.x][next_next_pos.y] == BOX_DES) {
			changeMap(&next_next_pos, HIT);		//小人可以将箱子从箱子的目的地移开  changeMap(&next_next_pos, BOX);
			changeMap(&next_pos, MAN);
			changeMap(&man, FLOOR);
			man = next_pos;
		}
	}
}



int main(void) {
	IMAGE bg_img;
	IMAGE man_steps;
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	loadimage(&bg_img, _T("blackground.bmp"), 0, 0, true);
	putimage(0, 0, &bg_img);

	loadimage(&images[WALL], _T("wall_right.bmp"), RATIO, RATIO, true);
	loadimage(&images[FLOOR], _T("floor.bmp"), RATIO, RATIO, true);
	loadimage(&images[BOX_DES], _T("des.bmp"), RATIO, RATIO, true);
	loadimage(&images[MAN], _T("man.bmp"), RATIO, RATIO, true);
	loadimage(&images[BOX], _T("box.bmp"), RATIO, RATIO, true);
	loadimage(&images[HIT], _T("box.bmp"), RATIO, RATIO, true);	

	for (int32 i = 0; i < LINE; i++) {
		for (int32 j = 0; j < COLUMN; j++) {
			if (map[i][j] == MAN) {
				man.x = i;
				man.y = j;
			}
			putimage(START_X + j * RATIO, START_Y + i * RATIO, &images[map[i][j]]);
		}
	}

	//游戏环节
	int times = 0;
	int* steps = &times;
	bool quit = false;
	do {
		//cout << "第" << *steps << "步";
		if (_kbhit()) {		//玩家按键
			char ch = _getch();
			if (ch == KEY_UP) {
				gameControl(UP);
				(*steps)++;
			}
			else if (ch == KEY_DOWN) {
				gameControl(DOWN);
				(*steps)++;
			}
			else if (ch == KEY_LEFT) {
				gameControl(LEFT);
				(*steps)++;
			}
			else if (ch == KEY_RIGHT) {
				gameControl(RIGHT);
				(*steps)++;
			}
			else if (ch == KEY_QUIT) {
				quit = true;
			}
			if (*steps > 60) {
				gameLose(&bg_img);
				quit = true;
			}
			if (isGameOver()) {
				gameOverScene(&bg_img);
					quit = true;
			}
		}
		Sleep(100);
	} while (quit == false);		//!quit

	system("pause");
	//游戏结束, 释放资源
	closegraph();
	return 0;
}