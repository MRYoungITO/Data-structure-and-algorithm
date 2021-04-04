#include <stdlib.h>
#include<stdio.h>
#include<string.h>

//栈区的空间大小是有限制的，windows 上一般是1M - 2M
void demo() {
	//int a1[102400*2]; //100k*2*4 = 800K
	//int a1[102400*3]; //100k*3*4 = 1200K = 1.2M
	int* a1;
	//如果使用堆的话，64 位windows 10 系统的限制是2G
	a1 = (int*)malloc((int)(1024 * 1000 * 1000));//分配2G
	a1[0] = 0;
	printf("This is a demo.\n");
}

int main(void) {
	printf("--start--\n");
	demo();
	printf("--end--\n");
	system("pause");
	return 0;
}