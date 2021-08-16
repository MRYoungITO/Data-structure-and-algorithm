#include <Windows.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define MaxSize 128 //Ԥ�ȷ���ռ䣬�����ֵ����ʵ����ҪԤ��ȷ��

typedef int ElemType;

typedef struct _SqStack {
	ElemType* base;  //ջ��ָ��
	ElemType* top;  //ջ��ָ��
}SqStack;

bool InitStack(SqStack& S) {  //����һ����ջS

	S.base = new ElemType[MaxSize];  //Ϊ˳��ջ����һ���������ΪMaxsize�Ŀռ�

	if (!S.base) { //�ռ����ʧ��
		return false;
	}
	S.top = S.base; //top ��ʼΪbase����ջ
	return true;
}

bool PushStack(SqStack& S, ElemType e) {  // ����Ԫ��e Ϊ�µ�ջ��Ԫ��

	if (S.top - S.base == MaxSize) {  //ջ��
		return false;
	}

	*(S.top++) = e;  //Ԫ��e ѹ��ջ����Ȼ��ջ��ָ���1���ȼ���*S.top=e; S.top++;

	return true;
}

bool PopStack(SqStack& S, ElemType& e)  //ɾ��S ��ջ��Ԫ�أ��ݴ��ڱ���e��
{
	if (S.base == S.top) {  //ջ��
		return false;
	}

	e = *(--S.top);  //ջ��ָ���1����ջ��Ԫ�ظ���e

	return true;
}

//���ŵİ汾
bool GetTop1(SqStack& S, ElemType& e) {  //����S ��ջ��Ԫ�أ�ջ��ָ�벻��

	if (S.top != S.base) {  //ջ�ǿ�
		e = *(S.top - 1);  //����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
		return true;
	}
	else {
		return false;
	}
}

ElemType GetTop(SqStack& S) {  //����S ��ջ��Ԫ�أ�ջ��ָ�벻��

	if (S.top != S.base) {  //ջ�ǿ�
		return *(S.top - 1);  //����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
	}
	else {
		return -1;
	}
}

int GetSize(SqStack& S) {  //����ջ��Ԫ�ظ���
	return (S.top - S.base);
}

bool IsEmpty(SqStack& S) {  //�ж�ջ�Ƿ�Ϊ��
	if (S.top == S.base) {
		return true;
	}
	else {
		return false;
	}
}

void DestoryStack(SqStack& S) {
	if (S.base) {
		free(S.base);
		S.base = NULL;
		S.top = NULL;
	}
}

int main(void) {
	int n, x;
	SqStack S;
	InitStack(S);  //��ʼ��һ��˳��ջS
	cout << "������Ԫ�ظ���n��" << endl;
	cin >> n;
	cout << "����������n ��Ԫ�أ�������ջ��" << endl;
	while (n--) {
		cin >> x;  //����Ԫ��
		PushStack(S, x);
	}

	cout << "Ԫ�����γ�ջ��" << endl;
	while (!IsEmpty(S)) {  //���ջ���գ������γ�ջ
		cout << GetTop(S) << "\t";  //���ջ��Ԫ��
		PopStack(S, x);  //ջ��Ԫ�س�ջ
	}
	cout << endl;

	DestoryStack(S);
	system("pause");
	return 0;
}