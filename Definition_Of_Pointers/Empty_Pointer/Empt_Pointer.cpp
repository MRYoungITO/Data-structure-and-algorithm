#include <stdio.h>
#include <stdlib.h>

int main(void){
	int room1 = 666;
	int room2 = 888;

	int girl;
	
	//int *select = 0;  //空指针,就是值为0的指针
	int *select = NULL;  //<-强烈推荐这种方式
	scanf_s("%d", &girl);
	
	if(girl == 666){
		select = &room1;
	}else if(girl == 888){
		select = &room2;
	}

	//printf("select:  0x%p,  room1:  0x%p,  room2:  0x%p\n", select, &room1, &room2);
	if(select == 0) {
		printf("没有选择任何房间!\n");
	} else {
		printf("选择的房间是： %d\n", *select);
	}

	system("pause");
	return 0;
}