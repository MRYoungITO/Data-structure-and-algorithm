#include <iostream>
#include <graphics.h>
#include <stdio.h>

#define RATIO 61

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 768

#define LINE 9
#define COLUMN 12

#define START_X 100
#define STRAT_Y 150

enum _PROPS {
	WALL,			//墙
	FLOOR,		//地板
	BOX_DES,	//箱子目的地
	MAN,			//小人
	BOX,			//箱子
	HIT,				//箱子命中目标
	ALL
};

using namespace std;

struct _POS {
	int x;		//小人所在的二维数组的行
	int y;		//小人所在的二维数组的列
};

IMAGE images[ALL];

struct _POS man;

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
			putimage(100 + j * 61, 150 + i * 61, &images[map[i][j]]);
		}
	}

	system("pause");
	return 0;
}