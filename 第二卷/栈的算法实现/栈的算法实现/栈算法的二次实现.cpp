#include <Windows.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define MaxSize 128

typedef int ElemType;

typedef struct _SqStack {
	ElemType* top;
	ElemType* base;
}SqStack;

bool InitSqStack(SqStack& S) {
	S.base = new ElemType[MaxSize];

	if (!S.base) return false;

	S.top = S.base;
	return true;
}

bool PushStack(SqStack& S, ElemType e) {
	if (S.top - S.base == MaxSize) return false;

	*(S.top++) = e;
	return true;
}

bool popStack(SqStack& S, ElemType& e) {
	if (S.top - S.base == MaxSize) return false;

	e = *(--S.top);
	return true;
}

bool GetTop1(SqStack& S, ElemType& e) {
	if (S.top != S.base) {
		e = *(S.top - 1);
		return true;
	}
	else {
		return false;
	}
}

ElemType GetTop(SqStack& S) {
	if (S.top != S.base) {
		return *(S.top - 1);
	}
	else {
		return -1;
	}
}

ElemType GetSize(SqStack& S) {
	if (!S.base) return -1;
	return (S.top - S.base);
}

bool IsEmpty(SqStack& S) {
	if (S.base == S.top) {
		return true;
	}
	else {
		return false;
	}
}
void DestoryStack(SqStack& S) {
	if (S.base) {
		delete S.base;
		S.base = NULL;
		S.top = NULL;
	}
}

int main(void) {
	int n, x;
	SqStack S;
	InitSqStack(S);
	cout << "请输入元素个数 n: " << endl;
	cin >> n;
	cout << "请依次输入 n 个元素, 依次入栈: " << endl;
	while (n--) {
		cin >> x;
		PushStack(S, x);
	}

	cout << "元素依次出栈: " << endl;
	while (!IsEmpty(S)) {
		if (GetTop1(S, x)) {
			cout << x << "\t";
		}
		popStack(S, x);
	}
	cout << endl;

	DestoryStack(S);
	system("pause");
	return 0;
}