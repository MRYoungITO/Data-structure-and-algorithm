#include <iostream>
#include <Windows.h>

using namespace std;

int fab(int n) {
	if (n ==1 || n == 2) {
		return 1;
	}

	return fab(n-1) + fab(n-2);
}

int main(void) {
	int n;
	cout << "ÇëÊäÈëĞòºÅ:  ";
	cin >> n;

	cout << fab(n) << endl;

	system("pause");
	return 0;
}