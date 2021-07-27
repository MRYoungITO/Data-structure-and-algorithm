#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef struct _LinkNode {
	int data;	//�ڵ��������
	struct _LinkNode* next;	//�ڵ��ָ����
}LinkNode, LinkList;	//LinkListΪָ��ṹ��LNode��ָ������

bool InitLoopList(LinkList*& L) { //����һ���յ�ѭ������

	L = new LinkNode; //�����½����Ϊͷ���, ��ͷָ��Lָ��ͷ���

	if (!L) return false;  //�����½����Ϊͷ���, ��ͷָ��Lָ��ͷ���

	L->next = L;	//ͷ����ָ����ָ���Լ�
	L->data = -1;
	return true;
}

//β�巨
bool ListInsert_back(LinkList*& L, LinkNode* node) {
	LinkNode* last = NULL;

	if (!L || !node) return false;

	if (L == L->next) {	//ͷ�ڵ��ָ����ָ�����Լ�, ���ǿյ�ѭ��������
		node->next = L;
		L->next = node;
	}
	else {
		last = L->next;
		while (last->next != L) last = last->next;	//��λβ�ڵ�
		last->next = node;
		node->next = L;
	}
	return true;
}

void LinkPrint(LinkList*& L) {	//ѭ����������
	LinkList* p;
	
	if (!L || L == L->next) {
		cout << "����Ϊ��!" << endl;
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

	//1. ��ʼ��һ���յ�ѭ������
	if (InitLoopList(L)) {
		cout << "�ɹ���ʼ��һ���յ�ѭ������!\n";
	}
	else {
		exit(-1);
	}

	//2. ����ѭ������(β�巨)
	cout << "β�巨����ѭ������,����10��Ԫ��..." << endl;
	i = 0;

	while ((++i) <= 10) {
		s = new LinkNode;	//�����½ڵ�
		s->data = i;	//����Ԫ�ظ�ֵ���½ڵ��������
		s->next = NULL;

		if (ListInsert_back(L, s)) {
			cout << "����ɹ�!" << endl;
		}
		else {
			cout << "����ʧ��!" << endl;
		}
	}

	LinkPrint(L);

	system("pause");
	return 0;
}