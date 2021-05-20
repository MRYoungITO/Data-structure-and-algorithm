#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;

int main(void) {
	ifstream inFile;
	string name;
	int age;

	// 以读的方式打开文件
	inFile.open("user.txt");
	while (1) {
		// 读姓名
		inFile >> name;
		if (inFile.eof()) {
			break;
		}
		cout << name << "\t";

		// 读年龄
		inFile >> age;
		cout << age << endl;
	}

	inFile.close();
	system("pause");
	return 0;
}