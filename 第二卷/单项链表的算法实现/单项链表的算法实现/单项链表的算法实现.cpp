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
	L->data = -1;
	return true;
}

//ǰ�巨
bool listInsert_front(LinkList*& L, LinkNode* node) {
	if (!L || !node)return false;

	node->next = L->next;
	L->next = node;
	return true;
}

//β�巨
bool listInsert_back(LinkList*& L, LinkNode* node) {
	LinkNode* last = NULL;

	if (!L || !node)return false;

	last = L;

	while (last->next)last = last->next;

	node->next = NULL;
	last->next = node;
	return true;
}

//ָ��λ�ò���
bool linkInsert(LinkList*& L, int i, int& e) {
	if (!L)return false;

	int j = 0;	//�趨�Խڵ���м����ı���
	LinkNode* p, * s;

	p = L;

	while (p && j < i - 1) {//����λ�� Ϊi-1�Ľ��, pָ��ý��
		p = p->next;
		j++;
	}

	if (!p || j > i - 1) {
		return false;
	}

	s = new LinkNode;	//�����½ڵ�
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

void LinkPrint(LinkList*& L) {
	LinkNode* p = NULL;	//������ʱ�Ľ��ָ�� p, Ϊ�˱���L�е�����ָ��

	if (!L) {
		cout << "����Ϊ��. " << endl;
		return;
	}

	p = L->next;

	while (p) {
		cout << p->data << "\t";
		p = p->next;
	}

	cout << endl;
}

bool Link_GetElem(LinkList*& L, int i, int& e) {
	 
	//�ڴ�ͷ�ڵ�ĵ�����L�в��ҵ�i��Ԫ��
	//��e��¼L�е�i��������Ԫ�ص�ֵ

	int index;
	LinkNode* p;

	if (!L || !L->next)return false;

	p = L->next;
	index = 1;

	while (p && index < i) {//˳�������ɨ��, ֱ��ָ���i��Ԫ�ػ�Ϊ��		
		p = p->next;		//pָ����һ�����
		index++;			//������index��Ӧ��1
	}

	if (!p || index > i) {//iֵ���Ϸ�, i>n��i<=0
		return false;
	}

	if (!p)return false; //���޴�ֵ

	e = p->data;
	return true;
}

bool Link_FindElem(LinkList*& L, int e, int& index) {	//��ֵ����

	//�ڴ�ͷ���ĵ�����L�в���ֵΪe��Ԫ��
	LinkNode* p;
	p = L->next;
	index = 1;

	if (!L || !L->next) {
		index = 0;
		return false;
	}

	while (p && p->data != e) {
		p = p->next;
		index++;
	}

	if (!p) {
		index = 0;
		return false;  //���޴�ֵ
	}

	return true;
}

bool LinkDelete(LinkList*& L, int i) {	//�������ɾ��

	LinkNode* p, * q;

	int index = 0;
	p = L;

	if (!L || !L->next) {
		return false;
	}

	while ((p->next) && (index < i - 1)) {
		p = p->next;
		index++;
	}

	if (!(p->next) || (index > i - 1))return false;	//��i>n��i<1ʱ, ɾ��λ�ò�����

	q = p->next;		//��ʱ���汻ɾ���ĵ�ַ�Ա��ͷſռ�
	p->next = q->next;	//�ı�ɾ�����ǰ������ָ����
	delete q;			//�ͷű�ɾ�����Ŀռ�
	return true;
}

void LinkDestroy(LinkList*& L) {  //�����������

	//������ʱ�ڵ�pָ��ͷ�ڵ�
	LinkNode* p = L;
	cout << "��������!" << endl;

	while (p) {
		L = L->next;  //Lָ����һ���ڵ�
		cout << "ɾ��Ԫ��: " << p->data << endl;
		delete p;	  //ɾ����ǰ�ڵ�
		p = L;		  //p������һ���ڵ�
	}
}

int main(void) {
	LinkList* L = NULL;
	LinkNode* s = NULL;

	//1. ��ʼ��һ���յ�����
	InitList(L);

	//2. ʹ��ǰ�巨��������
	//int n;
	//
	//cout << "ǰ�巨����������" << endl;
	//cout << "������Ԫ�ظ���n: ";
	//cin >> n;
	//cout << "\n��һ������n��Ԫ��: " << endl;

	//while (n > 0) {
	//	s = new LinkNode;	//�����½ڵ� s
	//	if (!s)break;
	//	cin >> s->data;
	//	listInsert_front(L, s);
	//	
	//	n--;
	//}

	//3. ʹ�ú�巨��������
	//int n;

	//cout << "β�巨����������" << endl;
	//cout << "������Ԫ�ظ���n: ";
	//cin >> n;
	//cout << "\n����������n��Ԫ��: " << endl;

	//while (n > 0) {
	//	s = new LinkNode;	//�����½ڵ� s
	//	if (!s)break;
	//	cin >> s->data;
	//	listInsert_back(L, s);

	//	n--;
	//}

	//4. ����������
	LinkPrint(L);

	//5. ����λ�ò���Ԫ��
	for (int j = 0; j < 3; j++) {
		int i, x;
		cout << "����������λ�ú�Ԫ��(�ÿո����): ";
		cin >> i;
		cin >> x;

		if (linkInsert(L, i, x)) {
			cout << "����ɹ�.\n\n";
		}
		else {
			cout << "����ʧ��.\n\n";
		}
		cout << endl;

		LinkPrint(L);
	}

	//6. ���������λ�û�ȡԪ��
	int element = 0;
	if (Link_GetElem(L, 2, element)) {
		cout << "��ȡ�ڶ���Ԫ�سɹ�, ֵ: " << element << endl;
	}
	else {
		cout << "��ȡ�ڶ���Ԫ��ʧ��!" << endl;
	}

	/*if (Link_GetElem(L, 4, element)) {
		cout << "��ȡ���ĸ�Ԫ�سɹ�, ֵ: " << element << endl;
	}
	else {
		cout << "��ȡ���ĸ�Ԫ��ʧ��!" << endl;
	}*/

	//7. ���������ֵ��ѯԪ�����ڵ�λ��
	int index = 0;
	if (Link_FindElem(L, 10, index)) {
		cout << "����Ԫ��10����, ����λ��: " << index << endl;
	}
	else {
		cout << "������Ԫ�� 10." << endl;
	}

	//8. ������ɾ��Ԫ��
	if (LinkDelete(L, 2)) {
		cout << "ɾ����2��Ԫ�سɹ�!" << endl;
		LinkPrint(L);
	}
	else {
		cout << "ɾ����2��Ԫ��ʧ��!" << endl;
	}

	//9. ���ٵ�����
	LinkDestroy(L);
	system("pause");
	return 0;
}