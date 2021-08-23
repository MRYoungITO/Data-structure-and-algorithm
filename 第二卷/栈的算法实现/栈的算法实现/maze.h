#pragma once
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct _Position { //迷宫坐标
	int _x;
	int _y;
}Position;

#define MaxSize 128 //预先分配空间，这个数值根据实际需要预估确定

typedef Position ElemType;

typedef struct _SqStack {
	ElemType* base; //栈底指针
	ElemType* top; //栈顶指针
}SqStack;

bool InitStack(SqStack& S) { //构造一个空栈S

	S.base = new ElemType[MaxSize]; //为顺序栈分配一个最大容量为Maxsize的空间
	if (!S.base) { //空间分配失败
		return false;
	}
	S.top = S.base; //top 初始为base，空栈
	return true;
}

bool PushStack(SqStack& S, ElemType e) { // 插入元素e 为新的栈顶元素

	if (S.top - S.base == MaxSize) { //栈满
		return false;
	}

	*(S.top++) = e; //元素e 压入栈顶，然后栈顶指针加1，等价于*S.top=e; S.top++;

	return true;
}

bool PopStack(SqStack& S, ElemType& e) { //删除S 的栈顶元素，暂存在变量e中

	if (S.base == S.top) { //栈空
		return false;
	}
	e = *(--S.top); //栈顶指针减1，将栈顶元素赋给e
	return true;
}

ElemType* GetTop(SqStack& S) { //返回S 的栈顶元素，栈顶指针不变

	if (S.top != S.base) { //栈非空
		return S.top - 1; //返回栈顶元素的值，栈顶指针不变
	}
	else {
		return NULL;
	}
}

int GetSize(SqStack& S) { //返回栈中元素个数
	return (S.top - S.base);
}

bool IsEmpty(SqStack& S) { //判断栈是否为空
	if (S.top == S.base) {
		return true;
	}
	else {
		return false;
	}
}

void DestoryStack(SqStack& S) { //销毁栈
	if (S.base) {
		free(S.base);
		S.base = NULL;
		S.top = NULL;
	}
}