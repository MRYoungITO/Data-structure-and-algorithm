#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main (void) {
	string pwd;

	while (1) {
		cout << "Please input your password: ";
		cin >> pwd;

		if (pwd == "000123") {
			break;
		} else {
			cout << "Name or password error." << endl;
		}
	}

	cout << "login sucess" << endl;
	cout << "1.Register" << endl;
	cout << "2.Manage" << endl;
	cout << "3.Inquiry" << endl;
	cout << "4.Delete" << endl;

	system("pause");
	return 0;
}