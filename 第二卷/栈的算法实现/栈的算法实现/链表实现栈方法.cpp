#include <Windows.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define MaxSize 128

typedef int ElemType;

typedef struct _SqStack {
	ElemType* top;
	ElemType* base;
	int data;
	struct _SqStack* next;
}SqStack, LinkStackL, LinkStackN;

bool InitSqStack(LinkStackL*& L) {
	L = new LinkStackN;

	if (!L) return false;

	L->next = NULL;
	return true;
}

bool PushStack(LinkStackL*& L, LinkStackN* e) {
	LinkStackN* last = NULL;

	if (!L || !e) return false;

	last = L;

	while (last->next) last = last->next;

	e->next = NULL;
	last->next = e;
	return true;
}

bool popStack(LinkStackL*& L, LinkStackN* e) {
	LinkStackN* last = NULL;

	if (!L || !e) return false;

	last->next = L;


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