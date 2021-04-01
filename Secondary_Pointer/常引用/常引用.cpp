#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a = 10;
	//int &b = a;
	//1.用变量初始化常引用
	const int &b = a;  //只能读不能写, 类似只能看不能摸

	//b = 100;  //常引用是让变量引用变成只读, 不能通过引用对变量进行修改
	printf("a: %d\n", a);

	//2.用字面量初始化常量引用
	const int c1 = 10;
	const int &c2 = 10;  //这个是在C++ 中, 编译器会对这样的定义的引用分配内存, 这算是一个特例
	int c3 = c2;

	//c2 = 100;  //不能修改

	system("pause");
	return 0;
}