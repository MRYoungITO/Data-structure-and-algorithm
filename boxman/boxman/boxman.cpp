#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <string>
#include <conio.h>

#define RATIO 61

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 768

//控制上、下、左、右控制方向. 'q' 退出
#define KEY_UP			'w'
#define KEY_LEFT		'a'
#define KEY_RIGHT	'd'
#define KEY_DOWN	's'
#define KEY_QUIT		'q'

#define LINE 9
#define COLUMN 12

#define isValid(pos) pos.x >= 0 && pos.x < LINE && pos.y >= 0 && pos.y < COLUMN

#define START_X 100
#define START_Y 150

enum _PROPS {
	WALL,			//墙
	FLOOR,		//地板
	BOX_DES,	//箱子目的地
	MAN,			//小人
	BOX,			//箱子
	HIT,				//箱子命中目标
	ALL
};

//游戏控制方向
enum _DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

using namespace std;

struct _POS {
	int x;		//小人所在的二维数组的行
	int y;		//小人所在的二维数组的列
};

IMAGE images[ALL];

struct _POS man;	//小人在二维数组中的位置

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

/**********************************************************
* 改变游戏地图视图中一格对应道具并重新显示
* 输入:
*			line - 道具在地图数组的行下标
*			colum - 道具在地图数组的列下标
*			prop - 道具的类型
*返回值:	无
*/
void changeMap(struct _POS *pos, enum _PROPS prop) {
	map[pos->x][pos->y] = prop;
	putimage(START_X + pos->y * RATIO, START_Y + pos->x * RATIO, &images[prop]);
}

/**********************************************************
* 实现游戏四个方向(上、下、左、右) 的控制
* 输入:
* direct - 人前进方向
* 输出: 无
**********************************************************/
void gameControl(enum _DIRECTION direct) {
	struct _POS next_pos = man;
	switch (direct) {
	case UP:
		next_pos.x--;
		break;
	case DOWN:
		next_pos.x++;
		break;
	case LEFT:
		next_pos.y--;
		break;
	case RIGHT:
		next_pos.y++;
		break; 
	}
	//宏展开	next_pos.x >= 0 && next_pos.x < LINE && next_pos.y >= 0 && next_pos.y < COLUMN
	if (isValid(next_pos) && map[next_pos.x][next_pos.y] == FLOOR) {
		changeMap(&next_pos, MAN);		//小人前进一格
		changeMap(&man, FLOOR);					//原小人位置变为地板
		man = next_pos;													//将当前小人位置赋给之前的小人变量的旧位置
	}
}

int main(void) {
	IMAGE bg_img;
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	loadimage(&bg_img, _T("blackground.bmp"), 0, 0, true);
	putimage(0, 0, &bg_img);

	loadimage(&images[WALL], _T("wall_right.bmp"), RATIO, RATIO, true);
	loadimage(&images[FLOOR], _T("floor.bmp"), RATIO, RATIO, true);
	loadimage(&images[BOX_DES], _T("des.bmp"), RATIO, RATIO, true);
	loadimage(&images[MAN], _T("man.bmp"), RATIO, RATIO, true);
	loadimage(&images[BOX], _T("box.bmp"), RATIO, RATIO, true);
	loadimage(&images[HIT], _T("bos.bmp"), RATIO, RATIO, true);

	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < COLUMN; j++) {
			if (map[i][j] == MAN) {
				man.x = i;
				man.y = j;
			}
			putimage(START_X + j * RATIO, START_Y + i * RATIO, &images[map[i][j]]);
		}
	}

	//游戏环节
		bool quit = false;
		do {
			if (_kbhit()) {		//玩家按键
				char ch = _getch();
				if (ch == KEY_UP) {
					gameControl(UP);
				}
				else if (ch == KEY_DOWN) {
					gameControl(DOWN);
				}
				else if (ch == KEY_LEFT) {
					gameControl(LEFT);
				}
				else if (ch == KEY_RIGHT) {
					gameControl(RIGHT);
				}
				else if (ch == KEY_QUIT) {
					quit = true;
				}
			}
		Sleep(100);
		} while (quit == false);		//!quit

	system("pause");
	return 0;
}