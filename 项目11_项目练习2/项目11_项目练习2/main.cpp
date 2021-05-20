#include <Windows.h>
#include <iostream>
#include "ODU.h"
#include "ODU330.h"

int main(void) {
	ODU odu1;
	odu1.setBandwidth(500);
	odu1.setTxFreq(114000);
	odu1.setTxPower(45);
	cout << odu1.description() << endl;

	ODU330 odu2;
	odu2.setBandwidth(600);
	odu2.setTxFreq(119000);
	odu2.setTxPower(48);
	odu2.setWarnThreshold(0.0001);
	cout << odu2.description() << endl;


	system("pause");
	return 0;
}