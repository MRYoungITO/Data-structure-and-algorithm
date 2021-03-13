#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

int main(void) {
	int rows = 9;
	int width = 0;

	for (int i=1; i<=rows; i++) {
		for (int j=1; j<=i; j++) {
			width = (j == 1) ? 1 : 2;
			cout << j << "*" << i << "=" << setw(width) << std::left << i*j << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}