#include <iostream>
#include <Windows.h>

using namespace std;

typedef struct _LinkNode {
	int data;	//����������
	struct _LinkNode* next;	//����ָ����
}LinkNode, LinkList; //����ڵ㡢����		LinkListΪָ��ṹ��LinkNode��ָ������

bool InitList(LinkList*& L) {
	L = new LinkNode;
	if (!L)return false;	//���ɽڵ�ʧ��

	L->next = NULL;
	return true;
}

//ǰ�巨
bool listInsert_front(LinkList*& L, LinkNode* node) {
	if (!L || !node)return false;

	node->next = L->next;
	
}


int main(void) {

	LinkList* L = NULL;

	system("pause");
	return 0;
}