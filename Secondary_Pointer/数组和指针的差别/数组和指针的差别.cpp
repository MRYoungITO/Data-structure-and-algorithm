#include <stdio.h>
#include <stdlib.h>

/*----------------<一维数组传参>----------------*/

/*方式一：形参不指定数组大小
	用数组的形式传递参数, 不需要制定参数的大小,
	因为在一维数组传参时, 形参不会真是的创建数组,
	传的只是数组首元素的地址
*/

void method_1(int arr[], int len) {
	for(int i=0; i<len; i++) {
		printf(" arr[%d]=%d\n", i, arr[i]);
	}
}

//方式二：指定数组大小
void mothod_2(int arr[10]) {
	for(int i=0; i<10; i++) {
		printf(" arr[%d]=%d\n", i, arr[i]);
	}
}

//方式三：一维数组传参退化, 用指针进行接收, 传的是数组首元素的地址
void method_3(int *arr, int len) {
	for(int i=0; i<len; i++) {
		printf(" arr[%d]=%d\n", i, arr[i]);
	}
}

/*int main(void) {
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	method_1(arr, 10);
	printf("------华丽的分割线------\n");
	mothod_2(arr);
	printf("------华丽的分割线------\n");
	method_3(arr, 10);

	system("pause");
	return 0;
}*/

/*-----------------<指针数组传参>---------------*/

//方式一：指针数组传参, 声明成指针数组, 不指定数组大小
void method_4(int *arr[], int len) {
	for(int i=0; i<len; i++) {
		printf(" arr[%d]=%d\n", i, *(arr[i]));
	}
}

//方式二：指针数组传参, 声明成指针数组, 指定数组大小
void method_5(int *arr[10]) {
	for(int i=0; i<10; i++) {
		printf(" arr[%d]=%d\n", i, *(arr[i]));
	}
}

//方式三：二维指针传参
//传过去是指针数组的数组名, 代表首元素地址,而数组的首元素又是一个指针
//就表示二级指针, 用二级指针接收
void method_6(int **arr, int len) {
	for(int i=0; i<len; i++) {
		printf(" arr[%d]=%d\n", i, *(*(arr+i)));
	}
}

int main(void) {
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *arr_p[10] = {0};
	for(int i=0; i<10; i++) {
		arr_p[i] = &arr[i];
	}
	method_4(arr_p, 10);
	printf("-----------华丽的分割线-----------\n");
	method_5(arr_p);
	printf("-----------华丽的分割线-----------\n");
	method_6(arr_p, 10);

	system("pause");
	return 0;
}