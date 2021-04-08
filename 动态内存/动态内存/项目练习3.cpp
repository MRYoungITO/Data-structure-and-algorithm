#include<iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(void) {
	int* p;
	int row, col;
	int i, j, k = 1;
	cout << "Input number of row: " << endl;
	cin >> row;
	cout << "Input number of colum: " << endl;
	cin >> col;
	p = new int[row * col];
	if(!p) {
		cout << "Not allocate memory ! " << endl;
		exit(1);
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			p[i * col + j] = k++;//根据行列下标，计算下表值
		}
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			cout << p[i * col +j] << "\t";//根据行列下标，计算下表值
		}	
		cout << endl;
	}
	delete[] p;

	system("pause");
	return 0;
}