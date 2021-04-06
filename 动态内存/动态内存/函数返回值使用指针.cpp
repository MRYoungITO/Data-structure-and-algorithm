#include <iostream>
#include <stdlib.h>

using namespace std;

int* add(int x, int y) {
	int sum = x + y;
	return &sum;
}

//返回动态内存分配的地址
int* add1(int x, int y) {
	int* sum = NULL;
	sum = new int;
	*sum = x + y;
	return sum;
}

//返回局部静态变量的地址
int* add2(int x, int y) {
	static int sum = 0;
	printf("sum: %d\n", sum);
	sum = x + y;
	return &sum;
}

int main(void) {
	int a = 3, b = 5;
	int* sum = NULL;
	//cout << add(a, b) << endl;
	//sum = add(a, b);	//不能使用外部函数局部变量的地址		bad(禁止的)

	//接收外部函数动态内存分配的地址		ok
	//sum = add1(a, b);
	//cout << *sum << endl;
	//delete sum;

	//接收外部函数局部静态变量的地址		ok
	sum = add2(a, b);
	cout << *sum << endl;
	*sum = 88888;
	add2(a, b);

	system("pause");
	return 0;
}