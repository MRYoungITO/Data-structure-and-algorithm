#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int guizi1 = 888;
	int *guizi2 = &guizi1;		//普通指针
	int **guizi3 = &guizi2;		//二级指向一级
	int ***guizi4 = &guizi3;	//三级指向二级
	int ****guizi5 = &guizi4;	//四级指向三级

	printf("柜子2拿枪: %d\n", *guizi2);
	printf("柜子3拿枪: %d\n", **guizi3);
	printf("柜子4拿枪: %d\n", ***guizi4);
	printf("柜子5拿枪: %d\n", ****guizi5);

	system("pause");
	return 0;
}
