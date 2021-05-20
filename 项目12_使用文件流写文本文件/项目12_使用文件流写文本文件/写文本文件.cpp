#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

int writeFile(void) {
	string name;
	int age;
	ofstream outfile;
	outfile.open("user.txt", ios::out | ios::trunc);

	while (1) {
		cout << "请输入姓名[ctrl+z退出]: ";
		cin >> name;
		if (cin.eof()) {
			break;
		}
		outfile << name << "\t";
		cout << "请输入年龄: ";
		cin >> age;
		outfile << age << endl;
	}
	outfile.close();

	system("pause");
	return 0;
}