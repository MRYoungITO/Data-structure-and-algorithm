#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	int rows;
	
	cout << "ÇëÊäÈëÐÐÊý£º";
	cin >> rows;

	for (int i=1; i<=rows; i++) {
		for (int j=0; j<rows-i; j++) {
			cout << ' ';
		}
		for (int k=0; k<(2*i-1); k++) {
			cout << '*';
		}
	cout << endl;
	}

	system("pause");
	return 0;
}