#include <iostream>
#include <Windows.h>

using namespace std;

void scorePrint(int score[ ], int n) {  //形参本质上是一个指针
	for (int i=0; i<n; i++) {
		cout << "第" << i+1 << "门课程的成绩:  " << score[i] << endl;
	}
}

//把每门课程的成绩,加5分
void scoreAdd(int score[ ], int n, int val=5) {
	for (int i=0; i<n; i++) {
		score[i] += val;
	}
}
 
void test(int a, int b, int c) {
	a += 5;
	b += 5;
	c += 5;
}

int main(void) {
	//				  0x8000
	//						v
	int score[3] = {60, 70, 80};
	//cout  << sizeof(score) << endl;  //12
	scorePrint(score, 3);

	//  把数组作为函数的参数时,这个函数中可以修改这个数组的值
	scoreAdd(score, 3);

	scorePrint(score, 3);

	system("pause");
}