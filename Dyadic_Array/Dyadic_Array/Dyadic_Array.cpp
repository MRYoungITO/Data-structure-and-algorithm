#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

int main(void) {
	//int ages[5][25]; //定义一个二维数组
	
	//初始化
	//第一种方式, 初始化是指定每行的值
	int a[3][4] = {
		{1, 2, 3, 4},  //也可以{1,2}省略掉得列会默认是0
		{5, 6, 7, 8},
		{9, 10, 11 ,12}
	};

	//第二种方式, 初始化时从头开始, 依次序进行
	int a1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int a2[3][4] = {1};  //只初始化第一个,其他的默认是0
	
	for (int i=0;i<3; i++) {
		for (int j=0; j<4; j++) {
			cout << a[i][j] << " ";  //printf("%d", a[i][j]);  C语言写法
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}