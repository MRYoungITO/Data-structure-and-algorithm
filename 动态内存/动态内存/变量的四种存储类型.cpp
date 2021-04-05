#include <stdio.h>
#include <iostream>
#include "static_test.h"

using namespace std; 

extern int extern_value;
static int yahuan_xiaoli = 24;	//全局静态变量
//int yahuan_extern = 30;

//寄存器变量
void register_demo() {
	register int j = 0;
	printf("j: %d\n", j);
	printf("&j: 0x%p\n", &j);
	//C++ 的 register 关键字已经优化, 如果我们打印他的地址, 他就变成了普通的auto 变量
	for (register int i = 0; i < 100; i++) {
		//...
	}

	{
		int k = 100;
		k += j;
	}
	printf("register_demo: %d\n", yahuan_xiaoli);
}

//静态变量
void static_demo() {
	static int girl = 18;	//局部静态变量, 只初始化一次
	int yahuan = 17;

	++girl;
	++yahuan;
	printf("girl: %d, yahuan: %d\n", girl, yahuan);
}

//外部变量
void extern_demo() {
	extern_value++;
	printf("extern_value: %d\n", extern_value);
}

int main7(void) {
	int i = 0;	//C语言的auto 不会报错, C++ auto 已经升级啦
	//register_demo();
	//static_demo();
	//static_demo();
	extern_demo();
	//printf("register_demo: %d\n", yahuan_xiaoli);
	test_extern_static();

	system("pause");
	return 0;
}