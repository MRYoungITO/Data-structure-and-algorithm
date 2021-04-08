#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main12(void) {
	string str1 = "Never quit and never stop";
	string str2 = "ÓÀ²»·ÅÆú£¬ÓÀ²»Í£Ö¹";
	string str3 = "";
	str3 = str1 + str2;
	
	char* p = new char[str3.length()];
	for (int i = 0; i < str3.length(); i++) {
		*(p + i) = str3[i];
	}
	for (int i = 0; i < str3.length(); i++) {
		cout << p[i];
	}
	cout << endl;
	delete[] p;

	system("pause");
	return 0;
}