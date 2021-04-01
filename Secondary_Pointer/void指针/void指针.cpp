#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};
	char ch = 'a';
	void *p = arr;  //定义了一个void * 类型的指针

	//p++;  //void * 指针不允许进行算术运算

	p = &ch;  //其他类型可以自动转换成void * 指针

	//printf("数组第一个元素: %d\n", *p);
	printf(" p: 0x%p, ch: 0x%p\n", p, &ch);

	char *p1 = (char *)p;

	//强制类型转化
	printf("p1指向的字符是: %c\n", *p1);

	system("pause");
	return 0;
}