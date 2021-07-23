#include <iostream>
#include "webServer.h"

using namespace std;

bool initList(TimeoutSqList& L) {	//����һ���յ�˳���L
	L.elems = new ConnTimeout[MAX_SIZE];	//Ϊ˳������MAX_SIZE��STARԪ�صĿռ�
	if (!L.elems)return false;		//�����ڴ����ʧ�ܵ����

	L.length = 0;
	L.size = MAX_SIZE;
	return true;
}

bool listAppend(TimeoutSqList& L, ConnTimeout e) {			//e ��ʾ���Ԫ�ص�ֵ
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

bool listDelete(TimeoutSqList& L, int i) {
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

void destroyList(TimeoutSqList& L) {
	if (L.elems)delete[]L.elems;	//�ͷŴ洢�ռ�
	L.length = 0;
	L.size = 0;
}

void listPrint(TimeoutSqList& L) {
	cout << "��ǰ: " << L.size << ", �ѱ���Ԫ�ظ��� Length: " << L.length << endl;
	for (int i = 0; i <= L.length - 1; i++) {
		cout << "fd: " << L.elems[i].fd << ", timeout:  " << L.elems[i].timeout << endl;
	}
	cout << endl;
}