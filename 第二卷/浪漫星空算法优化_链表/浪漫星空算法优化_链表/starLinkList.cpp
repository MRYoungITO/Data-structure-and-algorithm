#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <graphics.h> 
#include <conio.h>

using namespace std;

#define MAX_STAR 100 
#define SCREEN_WIDTH 440 
#define SCREEN_HEIGHT 280 
#define MAX_STEP 5 
#define MAX_RADIUS 3 
#define BOTTOM_MARGIN 100 

typedef struct _DoubleLinkNode {
	//int data; //节点的数据域
	struct _DoubleLinkNode* next; //下一个节点的指针域
	struct _DoubleLinkNode* prev; //上一个节点的指针域
}DbLinkNode, DbLinkList;  //LinkList 为指向结构体LNode的指针类型

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

typedef struct {
	int x;				//星星的x坐标
	int y;				//星星的y坐标
	enum STATUS stat;	//状态
	unsigned radius;	//星星的半径
	int step;			//每次跳跃的距离
	int color;			//星星的颜色
	DbLinkNode node;	//双向链表节点 "挂件"
}STAR;

bool InitLoopList(DbLinkList& L) { //构造一个空的循环链表

	L.next = NULL;	//头结点的next指针域指向自己
	L.prev = NULL;	//头结点的prev指针域指向自己
	return true;
}

//尾插法 
bool DbListInsert_back(DbLinkList& L, DbLinkNode& node) {
	DbLinkNode* last = NULL;

	last = &L;

	while (last->next) last = last->next;

	node.next = NULL;
	last->next = &node;
	node.prev = last;
	return true;
}

void initStar(STAR* _star) {
	int rgb = 0;

	//rand() 得到随机数范围 0 - 32767 RAND_MAX 
	_star->x = rand() % SCREEN_WIDTH; // x 范围 0 -639 
	_star->y = rand() % (SCREEN_HEIGHT - BOTTOM_MARGIN);// y 范围 0 - 379 

	_star->stat = (enum STATUS)(rand() % ALL_STATUS);  //星星状态随机
	_star->radius = 1 + rand() % MAX_RADIUS; //半径控制 1 - 3 
	_star->step = rand() % MAX_STEP + 1; //步长 1 - 5 
	rgb = 255 * _star->step / MAX_STEP; // 0 - 255 
	_star->color = RGB(rgb, rgb, rgb);
}

int main(void) {

	STAR* sl = NULL, * s = NULL;
	int n = 0;

	//1. 初始化一个空的双向链表
	sl = new STAR;
	sl->x = -1;

	InitLoopList(sl->node);
	
	//2. 使用尾插法
	cout << "尾插法创建双向链表" << endl;
	std::cout << "请输入星星个数 n：";
	cin >> n;

	while (n > 0) {
		s = new STAR; //生成新节点 s 
		initStar(s);
		printf("s 的地址:%p node: %p\n", s , &(s->node));
		DbListInsert_back(sl->node, s->node);
		n--;
	}

	//3. 根据链表节点访问数据
	DbLinkNode* p = NULL;
	p = &(sl->node);
	cout << "遍历所有星星：" << endl;

	while (p) {
		int offset = offsetof(STAR, node);
		STAR* ct = (STAR*)((size_t)p - offset);
		cout << ct->x << "  " << ct->y /* << "  " << ct->stat << "  " << ct->radius << "  " << ct->color*/ << endl;
		p = p->next;
	}

	//4. 销毁双向链表 
	p = &(sl->node);
	cout << "销毁所有星星：" << endl;
	while (p) {
		int offset = offsetof(STAR, node);
		STAR* ct = (STAR*)((size_t)p - offset);
		printf("offset: %u ct: %p p:%p\n", offset, ct, p);
		cout << ct->x << "  " << ct->y << endl;
		p = p->next;
		delete ct;
	}

	system("pause");
	return 0;
}