#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int demo1() {
	/*static*/ int i = 0;
	
	//printf("i 的地址: %p, i=%d\n", &i, i);

	return i;
}

int& demo(int** addr) {
	/*static*/ int i = 666;
	*addr = &i;
	printf("i 的地址: %p, i=%d\n", &i, i);
	return i;
}

int& demo_static(int** addr) {
	static int i = 666;
	*addr = &i;
	printf("i 的地址: %p, i=%d\n", &i, i);
	return i;
}

//3. 函数返回形参(普通参数)当引用
int& demo3(int var) {
	var = 666;
	return var;
}

//4. 函数返回形参(引用)当引用
int& demo4(int& var) {
	var = 666;
	return var;
}

int main(void) {
	int* addr = NULL;
	int ret = demo(&addr);

	//第一种情况 函数返回局部变量引用不能成为其他引用的初始值
	//int& i1 = demo(&addr);
	/*int i1 = 888;
	printf("addr: %p, i1=%d\n", addr, i1);*/

	//demo(&addr);
	/*demo1();
	printf("addr: %p, i1=%d\n", addr, i1);*/

	//第二种情况 函数返回局部变量不能作为左值
	/*demo(&addr) = 888;
	printf("addr: %p, value: %d\n", addr, *addr);
	demo1();
	printf("addr: %p, value: %d\n", addr, *addr);*/

	//第三种情况 返回静态变量和全局变量可以成为左值或是其他引用的初始值
	//demo_static(&addr) = 888;
	int& i1 = demo_static(&addr);
	i1 = 888;
	printf("1. addr: %p, value: %d\n", addr, *addr);
	demo1();
	printf("2. addr: %p, value: %d\n", addr, *addr);
	demo_static(&addr); 
	
	system("pause");
	return 0;
}