#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

/*
*先向新文件写入: "123456789"
* 然后再在第4个字符位置写入"ABC"
*/

int main(void) {
	ofstream outfile;

	outfile.open("test.txt");
	if (!outfile.is_open()) {
		return 1;
	}

	outfile << "123456789";
	outfile.seekp(4, outfile.beg);
	outfile << "ABC";

	outfile.close();
	system("pause");
	return 0;
}

/*
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

	cout << getSize("文件的随机读写.cpp") << endl;

	system("pause");
	return 0;
}*/


/*
int main(void) {

	ifstream infile;
	string line;

	infile.open("文件的随机读写.cpp");
	if (!infile.is_open()) {
	return 1;
	}

	//seekg用法, 文件内容尾部最后50位数据
	
	infile.seekg(-50, infile.end);
	while (!infile.eof()) {
		getline(infile, line);
		cout << line << endl;
	}

	infile.close();
	system("pause");
	return 0;
}*/