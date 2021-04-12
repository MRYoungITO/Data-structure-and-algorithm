#include <graphics.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//墙:0
//地板:1
//箱子目的地:2
//小人:3
//箱子:4
//箱子命中目标:5

#define RATIO 61
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 768

IMAGE images[6];

/*游戏地图*/
int map[9][12] = {
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,1,1,1,1,1,1,0,0},
	{0,1,4,1,0,2,1,0,2,1,0,0},
	{0,1,0,1,0,1,0,0,1,1,1,0},
	{0,1,0,2,0,1,1,4,1,1,1,0},
	{0,1,1,1,0,3,1,1,1,4,1,0},
	{0,1,2,1,1,4,1,1,1,1,1,0},
	{0,1,0,0,1,0,1,1,0,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0},
};

int main(void) {
	IMAGE bg_img;

	//搭台唱戏
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	loadimage(&bg_img, _T("blackground.bmp"), SCREEN_WIDTH, SCREEN_HEIGHT, true);
	putimage(0, 0, &bg_img);

	//加载道具图标
	loadimage(&images[0], _T("wall_right.bmp"), RATIO, RATIO, true);
	loadimage(&images[1], _T("floor.bmp"), RATIO, RATIO, true);
	loadimage(&images[2], _T("des.bmp"), RATIO, RATIO, true);
	loadimage(&images[3], _T("man.bmp"), RATIO, RATIO, true);
	loadimage(&images[4], _T("box.bmp"), RATIO, RATIO, true);
	loadimage(&images[5], _T("box.bmp"), RATIO, RATIO, true);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 12; j++) {
			putimage(100 + j * RATIO, 150 + i * RATIO, &images[map[i][j]]);
		}
		cout << endl;
	}

	system("pause");
	return 0;
}