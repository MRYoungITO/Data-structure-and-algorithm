#pragma once
#ifndef _STAR_H_
#define _STAR_H_

#define MAX_STAR 100 
#define SCREEN_WIDTH 640 
#define SCREEN_HEIGHT 480 
#define MAX_STEP 5 
#define MAX_RADIUS 3 
#define BOTTOM_MARGIN 100 

//����״̬ 
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
	int x;				//���ǵ� x ���� 
	int y;				//���ǵ� y ���� 
	enum STATUS stat;	//״̬ 
	unsigned radius;	//���ǵİ뾶 
	int step;			//ÿ����Ծ�ļ�� 
	int color;			//���ǵ���ɫ 
};

typedef struct {
	struct STAR* elems;	//˳���Ļ���ַ
	int length;			//˳���ĳ���
	int size;			//˳���Ŀռ�
}SqList;

bool initList(SqList& L);
bool listAppend(SqList& L, struct STAR e);
bool listDelete(SqList& L, int i);
void destroyList(SqList& L);
void listPrint(SqList& L);

#endif