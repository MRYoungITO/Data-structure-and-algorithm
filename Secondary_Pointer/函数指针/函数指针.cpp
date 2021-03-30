#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_int(const void *a, const void *b) {
	//printf("调用compare_int 啦, 你好骚气哦!\n");
	int *a1 = (int *) a;
	int *b1 = (int *) b;
	//printf("a 的地址: 0x%p, b 的地址: 0x%p\n", &a, &b);

	return *a1 - *b1;
}

int compare_char(const void *a, const void *b) {
	//printf("调用compare_char 啦, 你好骚气哦!\n");
	char c1 = *((char *) a);
	char c2 = *((char *) b);
	
	if(c1>= 'A' && c1<='Z') c1+=32;
	if(c2>= 'A' && c2<='Z') c2+=32;

	return c1 - c2;
}

int main(void) {
	int x = 10;
	int y = 20;

	//函数有没有地址?
	//printf("compare_int 的地址: 0x%p\n", &compare_int);
	//compare_int(&x, &y);

	//指向函数指针的定义 把函数声明移过来, 把函数名改成 (*函数指针名)
	int (*fp)(const void *a, const void *b); // f=>function函数的意思
	
	/*贝尔实验室的C和UNIX的开发者财通第一种形式, 而伯克利的UNIX推广者却采用第二种方式
	ANSI C 兼容了两种方式*/
	fp = &compare_int;
	(*fp)(&x, &y);  //第一种, 按普通指针解引的方式进行调用, (*fp) 等同于compare_int
	//fp(&x, &y);  //第二种, 直接调用
	//int sub = (*fp)(&x, &y);
	//printf("%d\n", sub);

	//qsort 对整形数组进行排序
	int arr[] = {2, 10, 30, 1, 11, 8, 7, 111, 520};
	qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), &compare_int);

	for(int i=0; i<sizeof(arr)/sizeof(int); i++) {
		printf(" %d", arr[i]);
	}

	printf("\n");

	//qsort 可以对任何类型的数组进行排序
	char arr1[] = {"abcdefghiABCDEFGHI"};
	qsort(arr1, sizeof(arr1)/sizeof(char)-1, sizeof(char), &compare_char);

	for(int i=0; i<sizeof(arr1)/sizeof(char)-1; i++) {
		printf(" %c", arr1[i]);
	}

	printf("\n");

	system("pause");
	return 0;
}