#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main (void) {
	int count = 0;

	for (int i=0; i <24; i++){
		for (int j=0; j<60; j++) {
			for (int k=0; k<60; k++) {
				count++;
				cout << i << ":" << j << ":" << k << "This is the " << count << " times I miss you!" << endl;
				Sleep(1000);  //Sleep 1000 milliseconds
			}
		}
	}

	system("pause");
	return 0;
}