#include <Windows.h>
#include <iostream>
#include "Girl.h"
#include "Boy.h"
#include <vector>

int main(void) {
	// vector
	vector<Boy> boys;
	Boy boy1(25, "小张", 25000);
	Boy boy2(28, "小王", 35000);
	boys.push_back(boy1);
	boys.push_back(boy2);
	for (int i = 0; i < boys.size(); i++) {
		cout << boys[i].description() << endl;
	}

	system("pause");
	return 0;
}