#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

int main(void) {
	ifstream infile;
	string line;
	char name[32];
	int age;

	infile.open("user.txt");
	if (!infile.is_open()) {
		cout << "文件打开失败";
		return 1;
	}

	while (1) {
		getline(infile, line);
		if (infile.eof()) {
			break;
		}
		sscanf_s(line.c_str(), "姓名:%s 年龄:%d", name, sizeof(name), &age);
		cout << "姓名:" << name << "\t\t\t年龄:" << age << endl;
	}

	infile.close();
	system("pause");
	return 0;
}