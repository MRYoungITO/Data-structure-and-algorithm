#include <graphics.h> 
#include <conio.h>
#include <stdlib.h>
#include <stdio.h> 
#include <string>
#include "starLinkList.h"

using namespace std;

//struct STAR star[MAX_STAR];

//bool isQuit() {
//	for (int i = 0; i < MAX_STAR; i++) {
//		if (star[i].x > 0 && star[i].x < SCREEN_WIDTH && star[i].y>0 &&
//			star[i].y < SCREEN_HEIGHT) {
//			return false;
//		}
//	}
//
//	return true;
//}

void MoveStar(SqList& L, int i) {

	if (L.elems[i].stat == STOP) return;

	//����ԭ�������� 
	setfillcolor(BLACK);
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius);

	if (L.elems[i].stat == DOWN) {
		L.elems[i].y = L.elems[i].y + L.elems[i].step;
		if (L.elems[i].y > SCREEN_HEIGHT) listDelete(L, i);
	}
	else if (L.elems[i].stat == UP) {
		L.elems[i].y -= L.elems[i].step;
		if (L.elems[i].y < 0) listDelete(L, i);
	}
	else if (L.elems[i].stat == LEFT) {
		L.elems[i].x -= L.elems[i].step;
		if (L.elems[i].x < 0) listDelete(L, i);
	}
	else if (L.elems[i].stat == RIGHT) {
		L.elems[i].x += L.elems[i].step;
		if (L.elems[i].x > SCREEN_WIDTH) listDelete(L, i);
	}

	setfillcolor(L.elems[i].color);
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius);
}

/************************************
* ���ܣ���ʼ������
* * ���������
* i - ������ȫ�������е��±�
* ����ֵ����
************************************/

void initStar(struct STAR& _star) {
	int rgb = 0;

	//rand() �õ��������Χ 0 - 32767 RAND_MAX 
	_star.x = rand() % SCREEN_WIDTH; // x ��Χ 0 -639 
	_star.y = rand() % (SCREEN_HEIGHT - BOTTOM_MARGIN);// y ��Χ 0 - 379 

	_star.stat = UP;	//(enum STATUS)(rand() % ALL_STATUS);  ����״̬���
	_star.radius = 1 + rand() % MAX_RADIUS; //�뾶���� 1 - 3 
	_star.step = rand() % MAX_STEP + 1; //���� 1 - 5 
	rgb = 255 * _star.step / MAX_STEP; // 0 - 255 
	_star.color = RGB(rgb, rgb, rgb);
}

int main() {

	bool quit = false;
	STAR star;

	DbLinkList starList = star.node;

	InitLoopList(starList);

	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	for (int i = 0; i < MAX_STAR; i++) {
		initStar(star);
		DbListInsert_back(starList, star.node);
	}

	while(starList.next) {
		setfillcolor(star.color);
		solidcircle(star.x, star.y, star.radius);
		starList = starList.next;
	}

	IMAGE tortoise; //����ͼƬ 
	loadimage(&tortoise, _T("tortoise.jpg"), 30, 30, false);
	putimage(SCREEN_WIDTH * 4 / 10 - 30, SCREEN_HEIGHT - 30, &tortoise);
	putimage(SCREEN_WIDTH * 6 / 10, SCREEN_HEIGHT - 30, &tortoise);

	while (quit == false) {
		for (int i = 0; i < starList.length; i++) {
			MoveStar(starList, i);
		}
		if (starList.length == 0) {
			quit = true;
		}

		Sleep(50);
	}

	system("pause");
	closegraph();
	return 0;
}