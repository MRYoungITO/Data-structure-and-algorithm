#include <iostream>
#include "webServer.h"

using namespace std;

bool initList(TimeoutSqList& L) {	//构造一个空的顺序表L
	L.elems = new ConnTimeout[MAX_SIZE];	//为顺序表分配MAX_SIZE个STAR元素的空间
	if (!L.elems)return false;		//考虑内存分配失败的情况

	L.length = 0;
	L.size = MAX_SIZE;
	return true;
}

bool listAppend(TimeoutSqList& L, ConnTimeout e) {			//e 表示添加元素的值
	if (L.length == L.size)return false;	//存储空间已满

	L.elems[L.length] = e;
	L.length++;								//表长增加1
	return true;
}

//bool listInsert(SqList& L, int i, struct STAR e) {
//	if (i < 0 || i >= L.length)return false;	//i 值不合法
//	if (L.length > MAX_STAR)return false;		//存储空间已满
//
//	for (int j = L.length - 1; j >= i; j--) {
//		L.elems[j + 1] = L.elems[j];	//从最后一个元素开始后移, 直到第一个元素后移
//	}
//	L.elems[i] = e;	//将新元素 e 放入第 i 个位置
//	L.length++;		//表长增加1
//	return true;
//}

bool listDelete(TimeoutSqList& L, int i) {
	if (i < 0 || i >= L.length)return false;	//不合法

	if (i == L.length - 1) {	//删除最后一个元素, 直接删除
		L.length--;
		return true;
	}

	for (int j = i; j < L.length - 1; j++) {
		L.elems[j] = L.elems[j + 1];	//被删除元素之后的元素前移
	}

	L.length--;
	return true;
}

void destroyList(TimeoutSqList& L) {
	if (L.elems)delete[]L.elems;	//释放存储空间
	L.length = 0;
	L.size = 0;
}

void listPrint(TimeoutSqList& L) {
	cout << "当前: " << L.size << ", 已保存元素个数 Length: " << L.length << endl;
	for (int i = 0; i <= L.length - 1; i++) {
		cout << "fd: " << L.elems[i].fd << ", timeout:  " << L.elems[i].timeout << endl;
	}
	cout << endl;
}