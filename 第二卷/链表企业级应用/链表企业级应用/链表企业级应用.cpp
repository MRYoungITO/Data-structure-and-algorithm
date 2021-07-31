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
	DbLinkNode node; //双向链表节点"挂件"
}ConnTimeout;

int main(void) {
	ConnTimeout* ct = new ConnTimeout;
	DbLinkNode* p = &(ct->node);

	cout << "请输入超时节点对应的fd: ";
	cin >> ct->fd;

	cout << "\n通过链表中的节点访问节点上承载的数据: " << endl;
	int offset = offsetof(ConnTimeout, node);

	system("pause");
	return 0;
}