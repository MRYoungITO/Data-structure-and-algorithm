#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main(void) {
	string str;
	int i;
	int j;
	char tmp;
	
	cout << "ÇëÊäÒ»¸ö×Ö·û´®£º" << endl;
	cin >> str;
	
	i = 0;
	j =str.length() - 1;
	while(i<j) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}

	cout  << str << endl;

	system("pause");
	return 0;
}