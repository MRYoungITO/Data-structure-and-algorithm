#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			for (int k=0; k<10; k++) {
				if (((i*i*i+j*j*j+k*k*k) == (i*100+j*10+k*1)) && ((i*100+j*10+k*1)>100)) {
					cout << i*100+j*10+k*1 <<endl;;
				}
			}
		}
	}

	system("pause");
	return 0;
}