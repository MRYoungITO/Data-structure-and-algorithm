#include <stdio.h>
#include <stdlib.h>

/*
int swap1(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
	return 0;
}
*/

int swap2(int * const _a, int * const _b) {
	int t = *_a;
	*_a = *_b;
	*_b = t;
	return 0;
}

int main(void) {
	int x =10;
	int &y = x;
	int z = 1000;
	int w = 10000;

	//y = z;  //y 是没有办法指向z的

	printf("x: %d, z: %d, w: %d\n", &x, &z, &w);




	//int &b = a;
	//b是a的别名, 请问C++编译器后面做了什么工作?


	//1. 请思考: 对同一内存空间可以取好几个名字吗?
	//int &c = a;
	//int &d = a;

	//printf("a: %d, b: %d, c: %d, d: %d\n", a, b, c, d);
	
	//2. 引用有没有自己的空间

	//结论: 引用可以定义多个, 引用有自己的空间, 那么, 引用像什么?
	//综上几点分析: 别名很像 常指针
	//int &b = a;			int * const b = &a;
	//swap1(z, w);  换成  swap2(&z, &w);	

	//swap1(z, w);
	//printf("z: %d, w: %d\n", z, w);
	swap2(&z, &w);
	printf("z: %d, w: %d\n", z, w);

	system("pause");
	return 0;
}