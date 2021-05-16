#include <Windows.h>
#include <iostream>
#include "WirelessTel.h"


int main(void) {
	WirelessTel phone;
	phone.setNumber("12345678900");
	cout << phone.getNumber() << endl;

	system("pause");
	return 0;
}