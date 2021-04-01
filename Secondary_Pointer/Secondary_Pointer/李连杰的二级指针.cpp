#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int guizi2 = 888;  //存枪的第二个柜子
	int *guizi1 = &guizi2;  //存第二个柜子地址的第一个柜子
	int **liujian = &guizi1;  //手握第一个柜子地址的刘建

	printf("刘建打开第一个柜子, 获得第二个柜子的地址: 0x%p\n", *liujian);
	printf("guizi2的地址: 0x%p\n", &guizi2);

	int *tmp;
	tmp = *liujian;

	printf("访问第二哥柜子的地址, 拿到枪: %d\n", *tmp);
	printf("刘建一步到位拿到枪: %d\n", *(*liujian));  //缩写成 **liujian

	system("pause");
	return 0;
}