#pragma once
#include <string>
using namespace std;
class Boy
{
public:
	Boy(const char* name = NULL, int age = 0, int salary = 0, 
		int darkHorse = 0);
	~Boy();

	string description();
	
	// 重载赋值运算符
	Boy& operator=(const Boy& boy);  //函数返回类型是 & 类型, 参数中加const保护实际参数不会被修改
private:
	char* name;
	int age;
	int salary;
	int darkHouse;  // 黑马值, 表示潜力系数
	unsigned int id;  //编号
	static int LAST_ID;
};

