#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

typedef struct _DoubleLinkNode {
	//int data; //节点的数据域
	struct _DoubleLinkNode* next; //下一个节点的指针域
	struct _DoubleLinkNode* prev; //上一个节点的指针域
}DbLinkNode, DbLinkList;  //LinkList 为指向结构体LNode的指针类型

typedef struct {
	int fd;
	time_t timeout;  //适用超时时刻的时间戳表示
	DbLinkNode node; //双向链表节点 "挂件"
}ConnTimeout;

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

int main(void) {
	ConnTimeout* cl = NULL, * s = NULL;;
	STAR* sl = NULL;
	int n = 0;

	//1. 初始化一个空的双向链表
	cl = new ConnTimeout;
	cl->fd = -1;

	sl = new STAR;
	sl->x = -1;
	
	InitLoopList(cl->node);
	InitLoopList(sl->node);

	//2. 使用尾插法
	cout << "尾插法创建双向链表" << endl; 
	std::cout << "请输入元素个数 n："; 
	cin >> n; 
	cout << "\n 请依次输入 n 个元素的文件句柄：" << endl;

	while (n > 0) {
		s = new ConnTimeout; //生成新节点 s 
		cin >> s->fd;
		printf("s 的地址:%p node: %p\n", s, &(s->node));
		DbListInsert_back(cl->node, s->node);
		n--;
	}

	//3. 根据链表节点访问数据
	DbLinkNode* p = NULL;
	p = &(cl->node); 
	cout << "遍历连接超时链表中的节点：" << endl;

	while (p) {
		int offset = offsetof(ConnTimeout, node);
		ConnTimeout* ct = (ConnTimeout*)((size_t)p - offset);
		cout << ct->fd << endl;
		p = p->next;
	}

	//4. 销毁双向链表 
	p = &(cl->node); 
	cout<<"销毁连接超时链表中的节点："<<endl; 
	while (p) {
		int offset = offsetof(ConnTimeout, node);
		ConnTimeout* ct = (ConnTimeout*)((size_t)p - offset);
		printf("offset: %u ct: %p p:%p\n", offset, ct, p);
		cout << ct->fd << endl;
		p = p->next;
		delete ct;
	}
	
	system("pause"); 
	return 0; 
}

	/*
	* 通过节点访问到节点承载的数据
	ConnTimeout* ct = new ConnTimeout;
	DbLinkNode* p = &(ct->node);

	cout << "请输入超时节点对应的fd: ";
	cin >> ct->fd;

	cout << "\n通过链表中的节点访问节点上承载的数据: " << endl;
	int offset = offsetof(ConnTimeout, node);

	ConnTimeout* tmp = (ConnTimeout*)((size_t)p - offset);
	printf("offset: %d\n", offset);
	printf("通过链表节点node访问到的数据: %d\n", tmp->fd);
	*/
//
//	system("pause");
//	return 0;
//}