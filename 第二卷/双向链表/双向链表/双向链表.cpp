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

bool Joseph(LinkList*& L, int interval) {

	LinkNode* p, * q;
	int i = 0, j = 0;
	int times = 0, num = 0;

	p = L;
	if (!L || p->next == L) {
		cout << "����Ϊ��!" << endl;
		return false;
	}

	if (interval < 1) {
		cout << "������̭�����С��1!" << endl;
		return false;
	}

	do {
		i += interval;

		//���ҵ�һ�����, pָ��ýڵ����һ�����
		while (p->next) {
			if (p->next != L)j++;
			if (j >= i)break;
			p = p->next;
		}

		times++;

		q = p->next;	//��ʱ���汻ɾ���ĵ�ַ�Ա��ͷſռ�
		num = q->data;
		if (times == 5) cout << "��5����Ȧ�ı����: " << num << endl;
		printf("cur: %d  last: %d  next: %d\n", q->data, p->data, q->next->data);

		p->next = q->next;
		delete q;	//�ͷű�ɾ������λ��

		LinkPrint(L);
	} while (L->next != L);	//����Ϊ��, ��������

	cout << "���һ����Ȧ�ı����: " << num << endl;

	return true;
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

	cout << "β�巨����ѭ������������: \n";
	LinkPrint(L);

	//3. ���Լɪ������
	Joseph(L, 9);

	system("pause");
	return 0;
}