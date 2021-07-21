#pragma once
#ifndef _STAR_H_
#define _STAR_H_

#define MAX_STAR 100 
#define SCREEN_WIDTH 640 
#define SCREEN_HEIGHT 480 
#define MAX_STEP 5 
#define MAX_RADIUS 3 
#define BOTTOM_MARGIN 100 

//星星状态 
enum STATUS {
	STOP = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	RANDOM,
	ALL_STATUS
};

struct STAR {
	int x;				//星星的 x 坐标 
	int y;				//星星的 y 坐标 
	enum STATUS stat;	//状态 
	unsigned radius;	//星星的半径 
	int step;			//每次跳跃的间隔 
	int color;			//星星的颜色 
};

typedef struct {
	struct STAR* elems;	//顺序表的基地址
	int length;			//顺序表的长度
	int size;			//顺序表的空间
}SqList;

bool initList(SqList& L);
bool listAppend(SqList& L, struct STAR e);
bool listDelete(SqList& L, int i);
void destroyList(SqList& L);
void listPrint(SqList& L);

#endif