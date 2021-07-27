#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef struct _LinkNode {
	int data;	//节点的数据域
	struct _LinkNode* next;	//节点的指针域
}LinkNode, LinkList;	//LinkList为指向结构体LNode的指针类型

bool InitLoopList(LinkList*& L) { //构造一个空的循环链表

	L = new LinkNode; //生成新结点作为头结点, 用头指针L指向头结点

	if (!L) return false;  //生成新结点作为头结点, 用头指针L指向头结点

	L->next = L;	//头结点的指针域指向自己
	L->data = -1;
	return true;
}

//尾插法
bool ListInsert_back(LinkList*& L, LinkNode* node) {
	LinkNode* last = NULL;

	if (!L || !node) return false;

	if (L == L->next) {	//头节点的指针域指向了自己, 就是空的循环的链表
		node->next = L;
		L->next = node;
	}
	else {
		last = L->next;
		while (last->next != L) last = last->next;	//定位尾节点
		last->next = node;
		node->next = L;
	}
	return true;
}

void LinkPrint(LinkList*& L) {	//循环链表的输出
	LinkList* p;
	
	if (!L || L == L->next) {
		cout << "链表为空!" << endl;
		return;
	}

	p = L->next;

	while (p != L) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}

int main(void) {
	LinkList* L, * s;
	int i = 0;

	//1. 初始化一个空的循环链表
	if (InitLoopList(L)) {
		cout << "成功初始化一个空的循环链表!\n";
	}
	else {
		exit(-1);
	}

	//2. 创建循环链表(尾插法)
	cout << "尾插法创建循环链表,插入10个元素..." << endl;
	i = 0;

	while ((++i) <= 10) {
		s = new LinkNode;	//生成新节点
		s->data = i;	//输入元素赋值给新节点的数据域
		s->next = NULL;

		if (ListInsert_back(L, s)) {
			cout << "插入成功!" << endl;
		}
		else {
			cout << "插入失败!" << endl;
		}
	}

	LinkPrint(L);

	system("pause");
	return 0;
}