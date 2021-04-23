#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int score = 0;	//分数
int rank = 0;		//等级

#define BLOCK_COUNT		5
#define BLOCK_WIDTH		5
#define BLOCK_HEIGHT	5
#define UNIT_SIZE				20

#define START_X				130
#define START_Y				30

#define KEY_UP					72
#define KEY_RIGHT			77
#define KEY_DOWN			80
#define KEY_LEFT				75
#define KEY_SPACE			32

int speed = 500;
int minX = 30;
int minY = 30;

typedef enum block_dir_t {
	BLOCK_UP,
	BLOCK_RIGHT,
	BLOCK_DOWN,
	BLOCK_LEFT
};

typedef enum move_dir_t {
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT
};

int NextIndex = -1;	//下一个方块的种类
int BlockIndex = -1;	//当前游戏区方块的种类

int color[BLOCK_COUNT] = {
	LIGHTGREEN,LIGHTCYAN,LIGHTMAGENTA,BROWN,YELLOW
};

int visit[30][15];		//访问数组
int markColor[30][15];	//表示对应位置的颜色

int block[BLOCK_COUNT * 4][BLOCK_HEIGHT][BLOCK_WIDTH] = {
	// "|" 形方块
	{	//向上
		0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,0,0,0
	},

	{	//向右
		0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},

	{	//向下
		0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,0,0,0
	},

	{	//向左
		0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0
	},

	// "L" 型方块
	{
		0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0
	},

	{ 
		0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,1,0,
		0,1,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,1,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,0,0,1,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	// "田" 形方块
	{ 
		0,0,0,0,0,
		0,1,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,1,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,1,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	{
		0,0,0,0,0,
		0,1,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	// "T" 形方块
	{ 
		0,0,0,0,0,
		0,1,1,1,0,
		0,0,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	},

	{ 
		0,0,0,0,0,
		0,0,0,1,0,
		0,0,1,1,0,
		0,0,0,1,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,0,1,0,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,1,0,0,0,
		0,1,1,0,0,
		0,1,0,0,0,
		0,0,0,0,0 
	},

	// "Z" 形方块
	{
		0,0,0,0,0,
		0,1,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,0,1,0,0,
		0,1,1,0,0,
		0,1,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,1,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0 
	},

	{ 
		0,0,0,0,0,
		0,0,1,0,0,
		0,1,1,0,0,
		0,1,0,0,0,
		0,0,0,0,0 
	}
};

void welcome(void) {
	initgraph(550, 660);
	HWND window = GetHWnd();		//获取窗口
	SetWindowText(window, _T("俄罗斯方块    老杨"));		//设置窗口标题

	//设置文本的	字体样式
	settextstyle(40, 0, _T("微软雅黑"));
	setcolor(WHITE);
	outtextxy(205, 200, _T("俄罗斯方块! "));
	settextstyle(20, 0, _T("楷体"));
	outtextxy(175, 300, _T("编程, 从俄罗斯方块开始! "));
	Sleep(3000);	//睡眠 (暂停) 3000毫秒, 3秒钟
}

//初始化游戏场景
void initGameScene(void) {
	char str[16];

	//清除屏幕
	cleardevice();
	//initgraph(550, 660);
	//HWND	window = GetHWnd();
	//SetWindowText(window, _T("俄罗斯方块    老杨"));

	setlinecolor(WHITE);
	rectangle(27, 27, 336, 635);
	rectangle(29, 29, 334, 633);
	rectangle(370, 50, 515, 195);

	settextstyle(24, 0, _T("楷体"));
	settextcolor(LIGHTGRAY);
	outtextxy(405, 215, _T("下一个: "));

	settextcolor(RED);
	outtextxy(405, 280, _T("分数: "));
	sprintf_s(str, "%d", score);
	outtextxy(415, 310, str);

	outtextxy(405, 375, _T("等级: "));
	sprintf_s(str, "%d", rank);
	outtextxy(425, 405, str);

	//操作说明	↑	↓	←	  →
	settextcolor(LIGHTBLUE);
	outtextxy(390, 475, _T("操作说明: "));
	outtextxy(390, 500, _T("↑: 旋转"));
	outtextxy(390, 525, _T("↓: 下降"));
	outtextxy(390, 550, _T("←: 左移"));
	outtextxy(390, 575, _T("→: 右移"));
	outtextxy(390, 600, _T("空格: 暂停"));
}

void clearBlock(int x, int y) {
	settextcolor(BLACK);
	settextstyle(23, 0, _T("楷体"));

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			//"■"
			outtextxy(x + j * UNIT_SIZE, y + i * UNIT_SIZE, _T("■"));
		}
	}
}

// 清除指定位置指定方向的方块
// 参数x: 方块的左上角的x坐标
// 参数y: 方块的左上角在游戏区域内的坐标, 距离游戏区域顶部的距离
void clearBlock(int x, int y, block_dir_t dir) {
	setcolor(BLACK);
	int id = BlockIndex * 4 + dir;
	y += START_Y;

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[id][i][j]) {
				//擦除该方块的第i行的第J列
				outtextxy(x + j * UNIT_SIZE, y + i * UNIT_SIZE, _T("■"));
			}
		}
	}
}

// 在右上角区域中, 绘制下一个方块
void drawBlock(int x, int y) {
	settextcolor(color[NextIndex]);
	settextstyle(23, 0, _T("楷体"));

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[NextIndex * 4][i][j]) {
				//"■"
				outtextxy(x + j * UNIT_SIZE, y + i * UNIT_SIZE, _T("■"));
			}
		}
	}
}

// 绘制方块: 在指定位置绘制指定方块的指定方向
void drawBlock(int x, int y, int blockIndex,block_dir_t dir) {
	settextcolor(color[BlockIndex]);
	settextstyle(23, 0, _T("楷体"));

	int id = blockIndex * 4 + dir;

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[id][i][j]) {
				//"■"
				outtextxy(x + j * UNIT_SIZE, y + i * UNIT_SIZE, _T("■"));
			}
		}
	}
}

void nextBlock(void) {
	int x = 391;
	int y = 71;

	clearBlock(x, y);			// 在右侧的提示区清除原来的方块

	// 随机选择一种方块
	srand(time(NULL));		//使用时间函数的返回值, 来作为随机种子
	NextIndex = rand() % BLOCK_COUNT;

	drawBlock(x, y);

}

// 如果在指定位置可以向指定方向移动, 就返回1,否则就返回0
int moveAble(int x0, int y0, move_dir_t moveDir, block_dir_t blockDir) {
	// 计算当前方块的左上角在30*15的游戏区中的位置(第多少行, 第多少列)
	int x = (y0 - minY) / UNIT_SIZE;
	int y = (x0 - minX) / UNIT_SIZE;
	int id = BlockIndex * 4 + blockDir;
	int ret = 1;

	if (moveDir == MOVE_DOWN) {
		for (int i = 0; i < BLOCK_HEIGHT; i++) {
			for (int j = 0; j < BLOCK_WIDTH; j++) {
				if (block[id][i][j] && ((x + i + 1) >= 30 || visit[x + i + 1][y + j])) {	//(x + i >= 0 && x + i < 30 && y + j >= 0 && y + j < 15 && 
					ret = 0;
				}
			}
		}
	}
	else if (moveDir == MOVE_LEFT) {
		for (int i = 0; i < BLOCK_HEIGHT; i++) {
			for (int j = 0; j < BLOCK_WIDTH; j++) {
				if (block[id][i][j] && ((y + j) == 0 || visit[x + i][y + j - 1])) {
					ret = 0;
				}
			}
		}
	}
	else if (moveDir == MOVE_RIGHT) {
		for (int i = 0; i < BLOCK_HEIGHT; i++) {
			for (int j = 0; j < BLOCK_WIDTH; j++) {
				if (block[id][i][j] && ((y + j + 1) >= 15 || visit[x + i][y + j + 1])) {
					ret = 0;
				}
			}
		}
	}

	return ret;
}

//检测游戏是否结束
void failCheck() {
	if (!moveAble(START_X, START_Y, MOVE_DOWN, BLOCK_UP)) {
		setcolor(WHITE);
		settextstyle(45, 0, _T("隶书"));
		outtextxy(75, 300, _T("GAME OVER"));
		Sleep(1000);
		system("pause");
		closegraph();
		exit(0);
	}
}

void wait(int interval) {		//500
	int count = interval / 10;
	for (int i = 0; i < count; i++) {
		Sleep(10);
		if (_kbhit()) {
			return;
		}
	}
}

// 判断当前方块是否可以转向到指定方向
// 注意, 此时还没有转到该方向! ! !
int rotatable(int x, int y, block_dir_t dir) {
	int id = BlockIndex * 4 + dir;
	int xIndex = (y - minY) / UNIT_SIZE;
	int yIndex = (x - minX) / UNIT_SIZE;

	if (!moveAble(x, y, MOVE_DOWN, dir)) {
		return 0;
	}

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[id][i][j] && (yIndex + j < 0 || yIndex + j >= 15 || visit[xIndex + i][yIndex + j])) {
				return 0;
			}
		}
	}

	return 1;
}

void mark(int x, int y, int blocklndex, block_dir_t dir) {
	int id = blocklndex * 4 + dir;
	int x2 = (y - minY) / UNIT_SIZE;
	int y2 = (x - minX) / UNIT_SIZE;
	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[id][i][j]) {
				visit[x2 + i][y2 + j] = 1;
				markColor[x2 + i][y2 + j] = color[blocklndex];
			}
		}
	}
}

void move(void) {
	int x = START_X;
	int y = START_Y;
	int k = 0;
	block_dir_t blockDir = BLOCK_UP;
	int curSpeed = speed;

	//检测游戏是否结束
	failCheck();

	//持续向下降落
	while (1) {
		if (_kbhit()) {
			int key = _getch();
			if (key == KEY_SPACE) {
				_getch();
			}
		}
		
		//清除当前方块
		clearBlock(x, k, blockDir);
		
		if (_kbhit()) {
			int key = _getch();

			if (key == KEY_UP) {
				block_dir_t nextDir = (block_dir_t)((blockDir + 1) % 4);
				if (rotatable(x, y + k, nextDir)) {
					blockDir = nextDir;
				}
			}
			else if (key == KEY_DOWN) {
				curSpeed = 50;
			}
			else if (key == KEY_LEFT) {
				if (moveAble(x, y + k + 20, MOVE_LEFT, blockDir)) {
					x -= UNIT_SIZE;
				}
			}
			else if (key == KEY_RIGHT) {
				if (moveAble(x, y + k + 20, MOVE_RIGHT, blockDir)) {
					x += UNIT_SIZE;		//x = x + 20;
				}
			}
		}

		k += 20;
		// 绘制当前方块
		drawBlock(x, y + k, BlockIndex, blockDir);

		wait(curSpeed);
			
		// 方块的 "固化" 处理
		if (!moveAble(x, y + k, MOVE_DOWN, blockDir)) {
			mark(x, y+k, BlockIndex, blockDir);
			break;
		}
	}
}

void newBlock() {
	// 确定即将使用的方块的类别
	BlockIndex = NextIndex;

	// 绘制刚从顶部下降的方块
	drawBlock(START_X, START_Y);

	//让新出现的方块暂停一会,让用户识别到
	Sleep(100);	//0.1秒
	//在右上角区域, 绘制下一个方块
	nextBlock();

	//方块降落
	move();
}

//消除第x行, 并把上面的行都下移
void down(int x) {
	for (int i = x; i >= 0; i--) {
		// 消除第i行, 第j列的方格消除
		for (int j = 0; j < 15; j++) {
			if (visit[i - 1][j]) {
				visit[i][j] = 1;
				markColor[i][j] = markColor[i - 1][j];
				setcolor(markColor[i][j]);
				outtextxy(minX + j * UNIT_SIZE, minY + i * UNIT_SIZE, _T("■"));
			}
			else {
				visit[i][j] = 0;
				setcolor(BLACK);
				outtextxy(minX + j * UNIT_SIZE, minY + i * UNIT_SIZE, _T("■"));
			}
		}
	}

	//清除最顶上的一行(就是航标为0的哪一行)
	setcolor(BLACK);
	for (int j = 0; j < 15; j++) {
		visit[0][j] = 0;
		outtextxy(minX + j * UNIT_SIZE, minY, _T("■"));
	}
}

void check(void) {
	int i, j;

	for (i = 29; i >= 0; i--) {
		// 检查第i行有没有满
		for (j = 0; j < 15 && visit[i][j]; j++);
			// 执行到此处时, 有两种情况:
			// 1. 第i行没有满, 即表示有空位 此时j<15
			// 2. 第i行已经满了, j>=15
		if (j >= 15) {
			// 此时, 第i行已经满了, 就需要消除第i行
			down(i);	//消除第i行, 并把上面的行都下移
			i++;	//因为最外层的循环中有i--, 所以我们先i++,使得下次循环时,再把这一行检查一下
		}
	}
}
 
int main(void) {
	welcome();
	initGameScene();

	//右上方显示下一个新方块
	nextBlock();
	Sleep(500);

	//初始化访问数组
	memset(visit, 0, sizeof(visit));

	while (1) {
		newBlock();

		// 消除满行, 并更新分数和速度
		check();
	}

	system("pause");
	closegraph();
	return 0;
}