#include <iostream>
#include <Windows.h>

using namespace std;

typedef struct _LinkNode {
	int data;	//结点的数据域
	struct _LinkNode* next;	//结点的指针域
}LinkNode, LinkList; //链表节点、链表		LinkList为指向结构体LinkNode的指针类型

bool InitList(LinkList*& L) {
	L = new LinkNode;
	if (!L)return false;	//生成节点失败

	L->next = NULL;
	return true;
}

//前插法
bool listInsert_front(LinkList*& L, LinkNode* node) {
	if (!L || !node)return false;

	node->next = L->next;
	
}


int main(void) {

	LinkList* L = NULL;

	system("pause");
	return 0;
}