#include <fstream>
#include <iostream>
#include <string>
#include "Database.h"

#define BOYS_FILE "boys.txt"
#define GIRLS_FILE "girls.txt"

Database::Database()
{

}

void Database::init()
{
	// 从之前已经保存的文件中, 读取用户信息, 
	// 用来初始化内部数据boys和girls
	initBoysFromFile();
	initGirlsFromFile();
}

void Database::autoPair()
{
	cout << endl << "自动配对结果: " << endl;
	string line(100, '-');
	cout << line << endl;

	for (int i = 0; i < boys.size(); i++) {
		for (int j = 0; j < girls.size(); j++) {
			if (boys[i].satisfied(girls[j]) &&
				girls[j].satisfied(boys[i])) {
				cout << boys[i].description() << endl;
				cout << girls[j].description() << endl;
				cout << line << endl;
			}
		}
	}
}

void Database::print()
{
	cout << "男嘉宾信息: \n";
	for (int i = 0; i < boys.size(); i++) {
		cout << boys[i].description() << endl;
	}

	cout << "\n女嘉宾信息: \n";
	for (int i = 0; i < girls.size(); i++) {
		cout << girls[i].description() << endl;
	}
}

void Database::addOne(Boy& boy)
{

}

void Database::initBoysFromFile()
{
	// 打开文件  读文件内容  初始化boys
	ifstream stream;
	stream.open(BOYS_FILE);
	if (!stream.is_open()) {
		// 最开始时, 没有文件!
		// 假设有这个需求:
		// 最开始没有文件时, 让用户输入基础用户数据
		cout << "===输入基础用户【男嘉宾】数据===" << endl;
		Boy::inputBoys(this->boys);
		saveBoys();
		stream.close();
		return;
	}

	// boys.txt 打开成功
	while (1) {
		string line;
		char name[64] = "";
		int salary;
		int age;

		getline(stream, line);
		if (stream.eof()) {
			break;
		}
		// 解析读到的一行数据line
		//to do.
		// 文件的格式:   性别:男\t\t\t姓名:Rock\t\t\t薪资:35000\t\t\t年龄:39

		int ret = sscanf_s(line.c_str(), "性别:男 姓名:%s 薪资:%d 年龄:%d",
			name, sizeof(name), &salary, &age);
		if (ret <= 0) {
			cout << "男嘉宾数据库格式匹配失败" << endl;
			exit(1);
		}

		// 使用读到的一个单身男信息, 构建一个Boy对象, 并添加到boys
		boys.push_back(Boy(age, string(name), salary));
	}
}

void Database::initGirlsFromFile()
{
	// 打开文件  读文件内容  初始化boys

	ifstream stream;
	stream.open(GIRLS_FILE);
	if (!stream.is_open()) {
		// 最开始时, 没有文件!
		// 假设有这个需求:
		// 最开始没有文件时, 让用户输入基础用户数据
		cout << "===输入基础用户【女嘉宾】数据===" << endl;
		Girl::inputGirls(this->girls);
		saveGirls();
		stream.close();
		return;
	}

	// girls.txt 打开成功
	while (1) {
		string line;
		char name[64] = "";
		int yanzhi;
		int age;

		getline(stream, line);
		if (stream.eof()) {
			break;
		}
		// 解析读到的一行数据line
		//to do.
		// 文件的格式:   性别:女\t\t\t姓名:无名\t\t\t颜值:90\t\t\t年龄:25

		int ret = sscanf_s(line.c_str(), "性别:女 姓名:%s 颜值:%d 年龄:%d",
			name, sizeof(name), &yanzhi, &age);
		if (ret <= 0) {
			cout << "女嘉宾数据库格式匹配失败" << endl;
			exit(1);
		}

		// 使用读到的一个单身男信息, 构建一个Boy对象, 并添加到boys
		girls.push_back(Girl(age, string(name), yanzhi));
	}
}

void Database::saveBoys()
{
	// 把boys中的所有单身男信息写入文件
	ofstream stream;
	stream.open(BOYS_FILE);
	if (!stream.is_open()) {
		cout << BOYS_FILE << "写入失败" << endl;
		exit(1);
	}
	for (int i = 0; i < boys.size(); i++) {
		stream << boys[i].description() << endl;
	}
	stream.close();
}

void Database::saveGirls()
{
	// 把girls中的所有单身男信息写入文件
	ofstream stream;
	stream.open(GIRLS_FILE);
	if (!stream.is_open()) {
		cout << GIRLS_FILE << "写入失败" << endl;
		exit(1);
	}
	for (int i = 0; i < girls.size(); i++) {
		stream << girls[i].description() << endl;
	}
	stream.close();
}
