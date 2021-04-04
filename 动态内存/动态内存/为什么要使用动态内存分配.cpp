#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main2(void) {
	int farmer[10] = { 20,22,25,19,18,23,17,28,30,35 };
	int num = 0;
	int* salary = NULL;

	do {
		printf("需要雇佣的农民数量: \n");
		scanf_s("%d", &num);
	} while (num <= 10);	//提示用户重新输入

	//后面新增的都是18
	salary = new int[num];
	//第一种, 逐个复制
	/*for (int i = 0; i < sizeof(farmer) / sizeof(int); i++) {
		*(salary + i) = *(farmer + i);
	}*/

	//第二种, 内存拷贝
	memcpy(salary, farmer, sizeof(farmer));

	for (int i = sizeof(farmer) / sizeof(int); i < num; i++) {
		*(salary + i) = 18;		//salary[i]=18;
	}

	for (int i = 0; i < num; i++) {
		printf("第%d个农民的薪资: %d\n", i + 1, salary[i]);
	}

	system("pause");
	return 0;
}