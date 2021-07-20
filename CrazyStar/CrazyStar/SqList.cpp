#include <iostream>
#include <Windows.h>
using namespace std;

#define MAX_SIZE 100

//typedef struct _SqList SqList;
//
//struct _SqList {
//	int* elems;		//˳���Ļ���ַ
//	int length;		//˳���ĳ���(Ԫ�ظ���)
//	int size;		//˳����ܵĿռ��С
//};

typedef struct {
	int* elems;		//˳���Ļ���ַ
	int length;		//˳���ĳ���(Ԫ�ظ���)
	int size;		//˳����ܵĿռ��С
} SqList;

bool initList(SqList& L) {	//����һ���յ�˳���L
	L.elems = new int[MAX_SIZE];	//Ϊ˳������MAX_SIZE��intԪ�صĿռ�
	if (!L.elems)return false;		//�����ڴ����ʧ�ܵ����

	L.length = 0;
	L.size = MAX_SIZE;
	return true;
}

bool listAppend(SqList& L, int e) {			//e ��ʾ���Ԫ�ص�ֵ
	if (L.length == L.size)return false;	//�洢�ռ�����

	L.elems[L.length] = e;
	L.length++;								//������1
	return true;
}

bool listInsert(SqList& L, int i, int e) {
	if (i < 0 || i >= L.length)return false;	//i ֵ���Ϸ�
	if (L.length > MAX_SIZE)return false;		//�洢�ռ�����

	for (int j = L.length - 1; j >= i; j--) {
		L.elems[j + 1] = L.elems[j];	//�����һ��Ԫ�ؿ�ʼ����, ֱ����һ��Ԫ�غ���
	}
	L.elems[i] = e;	//����Ԫ�� e ����� i ��λ��
	L.length++;		//������1
	return true;
}

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
		cout << L.elems[i] << " ";
	}
	cout << endl;
}

int main(void) {
	SqList list;
	int i, e;

	cout << "˳���ĳ�ʼ��..." << endl;

	//1. ��ʼ��
	if (initList(list)) {
		cout << "˳����ʼ���ɹ�" << endl;
	}

	listPrint(list);

	//2. ���Ԫ��
	int count = 0;
	cout << "������Ҫ��ӵ�Ԫ�ظ���: ";
	cin >> count;

	for (i = 0; i < count; i++) {
		cout << "\n������Ҫ��ӵ�Ԫ��e:";
		cin >> e;

		if (listAppend(list, e)) {
			cout << "��ӳɹ�!" << endl;
		}
		else {
			cout << "���ʧ��!" << endl;
		}
	}
	
	listPrint(list);

	//3. ����Ԫ��
	cout << "������Ҫ�����λ�ú�Ҫ�����Ԫ������: ";
	cin >> i >> e;

	if (listInsert(list, i, e)) {
		cout << "����ɹ�!" << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}

	listPrint(list);

	//4. ɾ��Ԫ��
	cout << "������Ҫɾ����λ��i: ";
	cin >> i;
	if (listDelete(list, i)) {
		cout << "ɾ���ɹ�!" << endl;
	}
	else {
		cout << "ɾ��ʧ��!" << endl;
	}

	listPrint(list);

	//5. ����
	destroyList(list);

	system("pause");
	return 0;
}