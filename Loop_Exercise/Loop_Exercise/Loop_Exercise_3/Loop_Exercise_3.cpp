#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	int rows = 0;
	
	cout << "Please enter the rows: ";
	cin >> rows;

	for (int i=0; i<rows; i++) {
		for (int j=rows; j>i; j--) {
			cout << '*';
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}