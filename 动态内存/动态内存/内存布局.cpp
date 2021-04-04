#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Windows.h>

using namespace std;

int laoyezi = 58;
//int girl = 17;

//1. 栈的内存
void say_hello(const char* msg) {  //函数的参数和局部变量存放在栈区
	//int x, y, z;
	if (msg) {
		printf("Hello %s!\n", msg);
	}
	else {
		printf("Who are u?\n");
	}
	printf("老爷子今年: %d岁\n", laoyezi);
}

void gui_fang(int jiaren) {
	static int girl = 17;
	if (girl == 17) {
		girl = 18;
	}
	else {
		girl = 16;
	}
	printf("小姐今年: %d岁\n", girl);
}

int main1(void) {
	int num = 100;
	int* salary = NULL;

	//4.字符常量
	const char* p = "童养媳";
	const char* p1 = "童养媳";

	printf("p:0x%p, 0x%p\n", p, p1);
	system("pause");
	exit(0);

	//3. 全局变量/静态变量
	printf("老爷子今年: %d岁\n", laoyezi);
	gui_fang(0);
	gui_fang(0);
	//printf("小姐今年: %d岁\n", girl);

	//salary = new int(666);

	//2. 堆, 动态内存分配
	salary = new int;		//在堆区分配动态内存
	*salary = 100;
	printf("salary: %d\n", *salary);
	delete salary;		//程序执行结束时, 回收动态内存
	system("pause");
	exit(0);
	do {
		printf("需要雇佣的农民数量: \n");
		scanf_s("%d", &num);
	} while (num < 0);	//提示用户重新输入
	
	salary = new int[num];
	for (int i = 0; i < num; i++) {
		*(salary + i) = i + 1;
	}

	for (int i = 0; i < num; i++) {
		printf("\n第%d个农民的薪资: %d\n", i+1, salary[i]);
	}

	printf("\n--------------OVER--------------\n\n");
	delete[] salary;
	//切记, delete后的动态内存, 禁止访问
	/*for (int i = 0; i < num; i++) {
		printf("\n第%d个农民的薪资: %d\n", i + 1, salary[i]);
	}*/

	//say_hello("骚年们!!");
	system("pause");
	return 0;
}