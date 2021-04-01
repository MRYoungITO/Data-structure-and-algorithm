#include <stdio.h>
#include <stdlib.h>

void print_months1(int days[], int months) {
	for(int index = 0; index<months; index++){
		//数组表示法
		printf("Month %2d has %d days.\n", index+1, days[index]);
	}
}

void print_months2(int *days, int months) {
	for(int index = 0; index<months; index++){
		//指针表示法
		printf("Month %2d has %d days.\n", index+1, *(days+index));
	}
}

int main(void) {
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	/*
	for(int index = 0; index<12; index++){
		//数组表示法
		//printf("Month %2d has %d days.\n", index+1, days[index]);

		//指针表示法
		//printf("Month %2d has %d days.\n", index+1, *(days+index));
	}*/
	print_months1(days, 12);
	printf("--------------------\n");
	print_months2(days, 12);

	system("pause");
	return 0;
}