#include <iostream>
#include "webServer.h"

using namespace std;

bool initSqList(TimeoutSqList& L) {
	L.elems = new ConnTimeout[MAX_SIZE];
	if (!L.elems)return false;

	L.length = 0;
	L.size = MAX_SIZE;
	return true;
}

bool listAppend(TimeoutSqList& L, ConnTimeout e) {
	if (L.length == L.size)return false;

	L.elems[L.length] = e;
	L.length++;
	return true;
}

//bool listInsert(TimeoutSqList& L, int i, ConnTimeout e) {
//	if (i < 0 || i >= L.length)return false;
//	if (L.length > MAX_SIZE)return false;
//
//	for (int j = L.length - 1; j >= i; j--) {
//		L.elems[j + 1] = L.elems[j];
//	}
//	L.elems[L.length] = e;
//	L.length++;
//	return true;
//}

bool listDelete(TimeoutSqList& L, int i) {
	if (i < 0 || i >= L.length)return false;

	if (i == L.length - 1) {
		L.length--;
		return true;
	}

	for (int j = i; j < L.length - 1; j++) {
		L.elems[j] = L.elems[j + 1];
	}

	L.length--;
	return true;
}

void destroyList(TimeoutSqList& L) {
	if (L.elems)delete[] L.elems;
	L.length = 0;
	L.size = 0;
}

void listPrint(TimeoutSqList& L) {
	cout << "当前：" << L.size << ", 已保存元素个数 Length:	" << L.length << endl;
	for (int i = 0; i <= L.length - 1; i++) {
		cout << "fd: " << L.elems[i].fd << ", timeout: " << L.elems[i].timeout << endl;
	}
	cout << endl;
}