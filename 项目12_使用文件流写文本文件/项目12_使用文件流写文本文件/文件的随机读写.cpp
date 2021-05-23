#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// 定义一个函数, 返回指定文件的大小
long long getSize(const char* fileName) {
	ifstream infile;
	infile.open(fileName);
	if (!infile.is_open()) {
		return 0;
	}
	infile.seekg(0, infile.end);
	long long ret = infile.tellg();
	infile.close();
	return ret;
}

int main(void) {
	//ifstream infile;
	//string line;
	/*
	infile.open("文件的随机读写.cpp");
	if (!infile.is_open()) {
		return 1;
	}*/
	cout << getSize("文件的随机读写.cpp") << endl;

	//seekg用法, 文件内容尾部最后50位数据
	/*
	infile.seekg(-50, infile.end);
	while (!infile.eof()) {
		getline(infile, line);
		cout << line << endl;
	}*/

	//infile.close();
	system("pause");
	return 0;
}