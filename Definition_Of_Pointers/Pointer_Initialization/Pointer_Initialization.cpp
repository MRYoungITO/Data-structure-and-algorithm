#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int room = 2;

	int *p1 = &room;
	int *p2 = p1;//int *p2 = &room;

	printf("room 的地址:  0x%p\n", &room);

	printf("p1 的地址:  0x%p\n", &p1);
	printf("p2 的地址:  0x%p\n", &p2);

	printf("room 所占字节: %d\n", sizeof(room));
	printf("p1 所占字节: %d\n", sizeof(p1));
	printf("p2 所占字节: %d\n", sizeof(p2));

	system("pause");
	return 0;
}