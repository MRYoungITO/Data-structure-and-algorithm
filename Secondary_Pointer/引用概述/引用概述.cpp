#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

//方式一, 使用指针
void swap1(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//方式二, 使用引用
void swap2(int &a, int &b) {
	//int &c;  //不可以
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	int x = 10, y = 100;
	swap2(x, y);

	printf("x: %d, y: %d\n", x, y);

	/*
	int a = 666;
	float c = 10.0;

	int &b = a;  //b是a 的别名
	float &d = c;

	//不能直接定义没有指向的别名
	int &e = a;

	printf("a: %d, b: %d\n", a, b);

	b = 888;
	printf("a: %d, b: %d\n", a, b);

	printf("a 的地址: 0x%p, b 的地址: 0x%p\n", &a, &b);
	*/

	system("pause");
	return 0;
}