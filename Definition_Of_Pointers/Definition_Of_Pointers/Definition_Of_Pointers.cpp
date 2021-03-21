#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int age;
	char ch;
	//定义了一个指针
	//指针本身也是一个变量
	//名称是p, 他是一个指针, 可以指向一个整数
	//也就是说: p的值就是一个整数的地址!  !  !
	int *p;
	char *c;

	//指针p 指向了age
	//p的值, 就是age的地址
	p = &age;
	c = &ch;
	scanf_s("%d", p);

	printf("age:%d\n", age);

	system("pause");
	return 0;
}