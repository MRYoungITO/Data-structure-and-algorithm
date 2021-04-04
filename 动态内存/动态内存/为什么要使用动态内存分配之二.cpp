#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//通过返回动态内存的指针
int* demo(int count) {
	int* ap = NULL;

	//new delete C++ 的动态内存分配操作符c 语言是malloc
	ap = (int*)malloc(sizeof(int) * count);//参数：所需内存的字节数
	//ap = new int[count];
	for (int i = 0; i < count; i++) {
		ap[i] = 100 + i;
	}
	for (int i = 0; i < count; i++) {
		printf("*(ap+%d) = %d\n", i, *(ap + i));
	}
	return ap;
}
//通过二级指针来保存
void demo1(int count, int** pointer_p) {
	int* ap = NULL;
	*pointer_p = (int*)malloc(sizeof(int) * count);
	ap = *pointer_p;
	for (int i = 0; i < count; i++) {
		ap[i] = 100 + i;
	}
	for (int i = 0; i < count; i++) {
		printf("*(ap+%d) = %d\n", i, *(ap + i));
	}
}

int main3(void) {
	//两种方式获取被调用函数内部的内存
	int* pointer = NULL;
	int count = 10;
	//第一种，通过返回动态内存的指针
	//pointer = demo(count);
	//第二种，通过二级指针来保存
	demo1(count, &pointer);
	for (int i = 0; i < 10; i++) {
		printf("*(pointer+%d) = %d\n", i, *(pointer + i));
	}
	//用完了，要记得释放
	free(pointer); //c 语言中的释放内存函数，相当于delete
	system("pause");
	return 0;
}