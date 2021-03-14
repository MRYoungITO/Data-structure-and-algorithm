#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main(void) {
	string str;
	int p = 1;
	int s = 0;
	
	cout << "请输入一个二进制数：";
	cin >> str;

	for(int i=str.length()-1; i>=0; i--) {
		int x = str[i] - '0';  //'0' - '0'= 0    '1' - '0' = 1
		s += x * p;
		p *= 2;
	}

	cout << s << endl;

	system("pause");
	return  0;
}