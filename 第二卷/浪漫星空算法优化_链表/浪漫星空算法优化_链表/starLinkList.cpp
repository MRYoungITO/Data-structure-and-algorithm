#include <iostream>
#include "starLinkList.h"

using namespace std;

bool InitLoopList(DbLinkList& L) { //����һ���յ�ѭ������

	L.next = NULL;	//ͷ����nextָ����ָ���Լ�
	L.prev = NULL;	//ͷ����prevָ����ָ���Լ�
	return true;
}

bool listAppend(SqList& L, struct STAR e) {			//e ��ʾ���Ԫ�ص�ֵ
	if (L.length == L.size)return false;	//�洢�ռ�����

	L.elems[L.length] = e;
	L.length++;								//������1
	return true;
}

//bool listInsert(SqList& L, int i, struct STAR e) {
//	if (i < 0 || i >= L.length)return false;	//i ֵ���Ϸ�
//	if (L.length > MAX_STAR)return false;		//�洢�ռ�����
//
//	for (int j = L.length - 1; j >= i; j--) {
//		L.elems[j + 1] = L.elems[j];	//�����һ��Ԫ�ؿ�ʼ����, ֱ����һ��Ԫ�غ���
//	}
//	L.elems[i] = e;	//����Ԫ�� e ����� i ��λ��
//	L.length++;		//������1
//	return true;
//}

bool listDelete(SqList& L, int i) {
	if (i < 0 || i >= L.length)return false;	//���Ϸ�

	if (i == L.length - 1) {	//ɾ�����һ��Ԫ��, ֱ��ɾ��
		L.length--;
		return true;
	}

	for (int j = i; j < L.length - 1; j++) {
		L.elems[j] = L.elems[j + 1];	//��ɾ��Ԫ��֮���Ԫ��ǰ��
	}

	L.length--;
	return true;
}

void destroyList(SqList& L) {
	if (L.elems)delete[]L.elems;	//�ͷŴ洢�ռ�
	L.length = 0;
	L.size = 0;
}

void listPrint(SqList& L) {
	cout << "˳���洢�ռ�size: " << L.size << ", �ѱ���Ԫ�ظ��� Length: " << L.length << endl;
	for (int i = 0; i <= L.length - 1; i++) {
		cout << "��" << i + 1 << "������: x = " << L.elems[i].x << ", y = " << L.elems[i].y << ", radius = " << L.elems[i].radius << endl;
	}
	cout << endl;
}