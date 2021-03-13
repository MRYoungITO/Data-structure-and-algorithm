#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	int rows = 0;
	int col = 0;

	cout << "Please enter the rows: ";
	cin >> rows;

	cout << "Enter the number of columns to print per row";
	cin >> col;

	for (int i=0; i<rows; i++) {
		for (int j=0; j<col; j++) {
			cout << '*';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}