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

void clearBlock(int x, int y, block_dir_t dir) {
	settextcolor(BLACK);
	settextstyle(23, 0, _T("楷体"));

	if (dir == BLOCK_UP || dir == BLOCK_RIGHT || dir == BLOCK_DOWN || dir == BLOCK_LEFT) {
		for (int i = 0; i < BLOCK_HEIGHT; i++) {
			for (int j = 0; j < BLOCK_WIDTH; j++) {
				//"■"
				outtextxy(x + j * UNIT_SIZE, y + i * UNIT_SIZE, _T("■"));
			}
		}
	}
}

// 在右上角区域中, 绘制下一个方块
void drawBlock(int x, int y,int next) {
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

void drawBlock(int x, int y, int blockIndex,block_dir_t dir) {

}

void nextBlock(void) {
	int x = 391;
	int y = 71;

	clearBlock(x, y);			// 在右侧的提示区清除原来的方块
	
	// 随机选择一种方块
	srand(time(NULL));		//使用时间函数的返回值, 来作为随机种子
	NextIndex = rand() % BLOCK_COUNT;
	drawBlock(x, y, NextIndex);

}

// 如果在指定位置可以向指定方向移动, 就返回1,否则就返回0
int moveAble(int x, int y, move_dir_t moveDir, block_dir_t blockDir) {

	if (moveDir == MOVE_DOWN) {
		//for(int i=0;i<)
	}
	else if (moveDir == MOVE_LEFT) {

	}
	else if (moveDir == MOVE_RIGHT) {

	}

	return 1;
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

void wait(int interval) {

}

void move() {
	int x = START_X;
	int y = START_Y;
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
	}
		
	//清除当前方块
	clearBlock(x, y, blockDir);

	if (_kbhit()) {
		int key = _getch();
		if (key == KEY_UP) {

		}
		else if (key == KEY_DOWN) {
			/*for (int i = 0; i < BLOCK_HEIGHT; i++) {
				for (int j = 0; j < BLOCK_WIDTH; j++) {
					visit[i - 1][j] = block[BlockIndex * 4][i][j];
				}
			}
		}
		else if (key == KEY_LEFT) {
			for (int i = 0; i < BLOCK_HEIGHT; i++) {
				for (int j = 0; j < BLOCK_WIDTH; j++) {
					visit[i][j - 1] = block[BlockIndex * 4][i][j];
				}
			}
		}
		else if (key == KEY_RIGHT) {
			for (int i = 0; i < BLOCK_HEIGHT; i++) {
				for (int j = 0; j < BLOCK_WIDTH; j++) {
					visit[i][j + 1] = block[BlockIndex * 4][i][j];
				}
			}*/
		}

	// 绘制当前方块
	//drawBlock()
	wait(curSpeed);

	// 方块的 "固化" 处理
	//to do.
	}
}

void newBlock() {
	// 确定即将使用的方块的类别
	BlockIndex = NextIndex;

	// 绘制刚从顶部下降的方块
	drawBlock(START_X, START_Y,BlockIndex);

	//让新出现的方块暂停一会,让用户识别到
	Sleep(100);	//0.1秒
	//在右上角区域, 绘制下一个方块
	nextBlock();

	//方块降落
	move();
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
	}

	system("pause");
	closegraph();
	return 0;
}