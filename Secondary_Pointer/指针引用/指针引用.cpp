#include <stdio.h>
#include <stdlib.h>

void boy_home(int **meipo) {
	static int boy = 23;
	*meipo = &boy;
}

void boy_home1(int * &meipo) {
	static int boy = 23;
	meipo = &boy;
}

int main(void) {
	/*
	int x = 666;
	int *p = &x;

	int * &q = p;  //÷∏’Î“˝”√

	printf("*p: %d, *q: %d\n",*p,*q);
	*/

	int *meipo = NULL;
	boy_home1(meipo);
	printf("boy: %d\n", *meipo);

	system("pause");
	return 0;
}