#include <iostream>
#include <Windows.h>
using namespace std;

#define MAX_SIZE 100

//typedef struct _SqList SqList;
//
//struct _SqList {
//	int* elems;		//顺序表的基地址
//	int length;		//顺序表的长度(元素个数)
//	int size;		//顺序表总的空间大小
//};

typedef struct {
	int* elems;		//顺序表的基地址
	int length;		//顺序表的长度(元素个数)
	int size;		//顺序表总的空间大小
} SqList;

bool initList(SqList& L) {	//构造一个空的顺序表L
	L.elems = new int[MAX_SIZE];	//为顺序表分配MAX_SIZE个int元素的空间
	if (!L.elems)return false;		//考虑内存分配失败的情况

	L.length = 0;
	L.size = MAX_SIZE;
	return true;
}

bool listAppend(SqList& L, int e) {			//e 表示添加元素的值
	if (L.length == L.size)return false;	//存储空间已满

	L.elems[L.length] = e;
	L.length++;								//表长增加1
	return true;
}

bool listInsert(SqList& L, int i, int e) {
	if (i < 0 || i >= L.length)return false;	//i 值不合法
	if (L.length > MAX_SIZE)return false;		//存储空间已满

	for (int j = L.length - 1; j >= i; j--) {
		L.elems[j + 1] = L.elems[j];	//从最后一个元素开始后移, 直到第一个元素后移
	}
	L.elems[i] = e;	//将新元素 e 放入第 i 个位置
	L.length++;		//表长增加1
	return true;
}

bool listDelete(SqList& L, int i) {
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

void listPrint(SqList& L) {
	cout << "顺序表存储空间size: " << L.size << ", 已保存元素个数 Length: " << L.length << endl;
	for (int i = 0; i <= L.length - 1; i++) {
		cout << L.elems[i] << " ";
	}
	cout << endl;
}

int main(void) {
	SqList list;
	int i, e;

	cout << "顺序表的初始化..." << endl;

	//1. 初始化
	if (initList(list)) {
		cout << "顺序表初始化成功" << endl;
	}

	listPrint(list);

	//2. 添加元素
	int count = 0;
	cout << "请输入要添加的元素个数: ";
	cin >> count;

	for (i = 0; i < count; i++) {
		cout << "\n请输入要添加的元素e:";
		cin >> e;

		if (listAppend(list, e)) {
			cout << "添加成功!" << endl;
		}
		else {
			cout << "添加失败!" << endl;
		}
	}
	
	listPrint(list);

	//3. 插入元素
	cout << "请输入要插入的位置和要插入的元素数据: ";
	cin >> i >> e;

	if (listInsert(list, i, e)) {
		cout << "插入成功!" << endl;
	}
	else {
		cout << "插入失败" << endl;
	}

	listPrint(list);

	//4. 删除元素
	cout << "请输入要删除的位置i: ";
	cin >> i;
	if (listDelete(list, i)) {
		cout << "删除成功!" << endl;
	}
	else {
		cout << "删除失败!" << endl;
	}

	listPrint(list);

	system("pause");
	return 0;
}