#include <stdlib.h>
#include <iostream>

using namespace std;

//分配基础类型
/*
int main007(void) {
	//第一种分配动态内存不执行初始化
	int* p1 = new int;
	*p1 = 100;

	//第二种分配动态内存同时执行初始化
	int* p2 = new int(100);
	//第三种 malloc 返回值是 void *
	int* p3 = (int*)malloc(sizeof(int));

	free(p1);	//基础类型可以 new free	可以混搭
	delete p3;//基础类型可以 malloc delete	可以混搭
	delete p2;//free(p2);	同样效果

	system("pause");
	return 0;
}*/

//分配数组变量
int main5(void) {
	int* p1 = (int*)malloc(sizeof(int)*10);
	//p[0] - p[9]		*(p+9)
	int* p2 = new int[10];

	delete p1;		//free(p1);		可以混搭
	delete[] p2;	// free(p2);	可以混搭

	system("pause");
	return 0;
}