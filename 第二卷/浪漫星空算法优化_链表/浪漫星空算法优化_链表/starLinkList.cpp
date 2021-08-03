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
	//int data; //�ڵ��������
	struct _DoubleLinkNode* next; //��һ���ڵ��ָ����
	struct _DoubleLinkNode* prev; //��һ���ڵ��ָ����
}DbLinkNode, DbLinkList;  //LinkList Ϊָ��ṹ��LNode��ָ������

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

typedef struct {
	int x;				//���ǵ�x����
	int y;				//���ǵ�y����
	enum STATUS stat;	//״̬
	unsigned radius;	//���ǵİ뾶
	int step;			//ÿ����Ծ�ľ���
	int color;			//���ǵ���ɫ
	DbLinkNode node;	//˫������ڵ� "�Ҽ�"
}STAR;

bool InitLoopList(DbLinkList& L) { //����һ���յ�ѭ������

	L.next = NULL;	//ͷ����nextָ����ָ���Լ�
	L.prev = NULL;	//ͷ����prevָ����ָ���Լ�
	return true;
}

//β�巨 
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

	//rand() �õ��������Χ 0 - 32767 RAND_MAX 
	_star->x = rand() % SCREEN_WIDTH; // x ��Χ 0 -639 
	_star->y = rand() % (SCREEN_HEIGHT - BOTTOM_MARGIN);// y ��Χ 0 - 379 

	_star->stat = (enum STATUS)(rand() % ALL_STATUS);  //����״̬���
	_star->radius = 1 + rand() % MAX_RADIUS; //�뾶���� 1 - 3 
	_star->step = rand() % MAX_STEP + 1; //���� 1 - 5 
	rgb = 255 * _star->step / MAX_STEP; // 0 - 255 
	_star->color = RGB(rgb, rgb, rgb);
}

int main(void) {

	STAR* sl = NULL, * s = NULL;
	int n = 0;

	//1. ��ʼ��һ���յ�˫������
	sl = new STAR;
	sl->x = -1;

	InitLoopList(sl->node);
	
	//2. ʹ��β�巨
	cout << "β�巨����˫������" << endl;
	std::cout << "���������Ǹ��� n��";
	cin >> n;

	while (n > 0) {
		s = new STAR; //�����½ڵ� s 
		initStar(s);
		printf("s �ĵ�ַ:%p node: %p\n", s , &(s->node));
		DbListInsert_back(sl->node, s->node);
		n--;
	}

	//3. ��������ڵ��������
	DbLinkNode* p = NULL;
	p = &(sl->node);
	cout << "�����������ǣ�" << endl;

	while (p) {
		int offset = offsetof(STAR, node);
		STAR* ct = (STAR*)((size_t)p - offset);
		cout << ct->x << "  " << ct->y /* << "  " << ct->stat << "  " << ct->radius << "  " << ct->color*/ << endl;
		p = p->next;
	}

	//4. ����˫������ 
	p = &(sl->node);
	cout << "�����������ǣ�" << endl;
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