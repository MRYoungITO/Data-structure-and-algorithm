#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	int rows = 0;
	int col = 0;

	cout << "请输入行数：";
	cin >> rows;

	cout << "请输入每行需要打印的列数：";
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