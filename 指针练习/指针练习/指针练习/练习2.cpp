/*******************************************************************************************
*有一个整形数组, a[3]={7,2,5}, 要求使用指针实现数组成员右小到大的顺序排列
*即结果为: a[3]={2,5,7};
********************************************************************************************/

#include <iostream>

using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main2(void) {
	int a[3] = { 7,2,5 };
	if (*a > *(a + 1)) {
		swap(a, a + 1);
	}
	if (*(a + 2) < *(a + 1)) {
		swap(a + 1, a + 2);
		if (*a > *(a + 1)) {
			swap(a, a + 1);
		}
	}
	cout << "a[3]={";
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
		cout << " " << a[i] << " ";
	}
	cout << "}" << endl;

	system("pause");
	return 0;
}
/*
int compare_int(const void* a, const void* b) {
	int* a1 = (int*)a;
	int* b1 = (int*)b;

	return *a1 - *b1;
}
*/

/*
int main(void) {
	int a[3] = {7, 2, 5};
	qsort(a,sizeof(a)/sizeof(int),sizeof(int),&compare_int);
	cout << "a[3] = {";
	for (int i = 0; i < 3; i++) {
		cout << " " << a[i];
	}
	cout << "}" << endl;

	system("pause");
	return 0;
}
*/
