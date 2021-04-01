#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void boy_home(int **meipo) {
	static int boy = 23;  //函数执行结束后, 变量依然存在, 内存不会回收该变量
	*meipo = &boy;
}

int main(void) {
	//int x=10, y=100;
	//swap(&x, &y);
	//printf("x=%d, y=%d\n", x, y);
	int *meipo =  NULL;
	boy_home(&meipo);
	printf("boy: %d\n", *meipo);

	system("pause");
	return 0;
}