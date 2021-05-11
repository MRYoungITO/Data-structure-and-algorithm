#include <Windows.h>
#include <iostream>
#include "Father.h"
#include "Son.h"

int main(void) {
	Father wjl("王健林", 68);
	Son wsc("王思聪", 32, "电竞");

	cout << wjl.description() << endl;
	cout << wsc.description() << endl;

	system("pause");
	return 0;
}