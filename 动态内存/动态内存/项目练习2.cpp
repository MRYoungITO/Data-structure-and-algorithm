#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main13(void) {
	string str1 = "";
	string str2 = "";
	string str3 = "";
	cout << "请输入文字: ";
	getline(cin, str1);
	char* p = new char[1024];
	for (int i = 0; i < str1.length(); i++) {
		*(p + i) = str1[i];
	}
	cout << "请再次输入文字: ";
	getline(cin, str2);
	for (int i = 0; i < str2.length(); i++) {
		*(p + str1.length() + i) = str2[i];
	}
	cout << "请输入最后一段文字: ";
	getline(cin, str3);
	for (int i = 0; i < str3.length(); i++) {
		*(p + str1.length() + str2.length() + i) = str3[i];
	}
	for (int i = 0; i < str3.length()+str2.length()+str1.length(); i++) {
		cout << p[i];
	}
	cout << endl;
	delete[] p;

	system("pause");
	return 0;
}