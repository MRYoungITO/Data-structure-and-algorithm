#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

typedef struct _DoubleLinkNode {
	//int data; //�ڵ��������
	struct _DoubleLinkNode* next; //��һ���ڵ��ָ����
	struct _DoubleLinkNode* prev; //��һ���ڵ��ָ����
}DbLinkNode, DbLinkList;  //LinkList Ϊָ��ṹ��LNode��ָ������

typedef struct {
	int fd;
	time_t timeout;  //���ó�ʱʱ�̵�ʱ�����ʾ
	DbLinkNode node; //˫������ڵ�"�Ҽ�"
}ConnTimeout;

int main(void) {
	ConnTimeout* ct = new ConnTimeout;
	DbLinkNode* p = &(ct->node);

	cout << "�����볬ʱ�ڵ��Ӧ��fd: ";
	cin >> ct->fd;

	cout << "\nͨ�������еĽڵ���ʽڵ��ϳ��ص�����: " << endl;
	int offset = offsetof(ConnTimeout, node);

	system("pause");
	return 0;
}