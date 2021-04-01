#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int room = 2;
	int room1 = 3;  //3p

	int *p1 = &room;
	int *p2 = p1;  //int *p2 = &room;

	//1.访问(读、写)指针变量本身的值, 和其他普通变量的访问方式相同

	int *p3 = p1;

	printf("room 的地址:  0x%p\n", &room);
	printf("p1的值是:  0x%p,  p2的值是:  0x%p\n", p1, p2);
	printf("p3的值是:  0x%p\n", p3);

	p3 = &room1;

	printf("p3的值是:  0x%p,  room1的地址:  0x%p\n", p3, &room1);

	//以16进制打印地址,把地址当成无符号数来处理
	printf("p1的值是:  0x%p\n", p1);  //方法1
	printf("p1的值是:  0x%x\n", p1);	//方法2
	printf("p1的值是:  0x%X\n", p1);	//方法3

	int *girl = &room;   

	//room = 3;

	int x = 0;;
	x = *girl;  //*是一个特殊的运算符, *girl表示读取指针girl所指向的变量的值 (间接访问), &girl想当于room

	printf("x:  %d\n", x);

	*girl = 4;
	printf("room:  %d, *girl:  %d\n", room, *girl);

	system("pause");
	return 0;
}