#include <iostream>

using namespace std;

void copy_arr(double target1[], double source[], int len) {
	for (int i = 0; i < len; i++) {
		target1[i] = source[i];
	}
}

void copy_ptr(double* target2, double* source, int len) {
	
	for (int i = 0; i < len; i++) {
		*(target2)++ = *(source+i);
	}
}


void copy_ptrs(double* target3, double* source_start, double* source_end ) {
	for (; source_start < source_end; source_start++) {
		*target3 = *source_start;
		*target3++;
	}
}
int main5(void) {
	double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double target1[5];
	double target2[5];
	double target3[5];

	copy_arr(target1, source, 5);
	cout << "target1: ";
	for (int i = 0; i < sizeof(source) / sizeof(source[0]); i++) {
		cout << target1[i] << " ";
	}
	cout << endl;

	copy_ptr(target2, source, 5);
	cout << "target2: ";
	for (int i = 0; i < sizeof(source) / sizeof(source[0]); i++) {
		cout << target2[i] << " ";
	}
	cout << endl;

	copy_ptrs(target3, source, source+5);
	cout << "target3: ";
	for (int i = 0; i < sizeof(source) / sizeof(source[0]); i++) {
		cout << target3[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}