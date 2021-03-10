#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main (void) {
	int year = 0;
	int month = 0;
	bool flag = false;
	int days = 0;

	cout << "Year£º";
	cin >> year;

	cout << "Month£º";
	cin >> month;

	if (year % 400 == 0) {
		flag = true;
	} else if (year % 4 == 0 && year % 100 != 0) {
		flag = true;
	} else {
		flag = false;
	}

	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		days = 31;
		break;
	case 2:
		days = flag ? 29 : 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30;
		break;
	}

	cout << year << "-" << month << "-" << days << endl;

	system("pause");
	return 0;
}