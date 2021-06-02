#pragma once
#include <string>
#include <iostream>

#define AGE_KEY "age"
#define SALARY_KEY "salary"
#define DARK_HORSE_KEY "darkHorse"
#define POWER_KEY "power"

// 枚举类型表示
typedef enum {
	AGE,
	SALARY,
	DARK_HORSE,
	POWER
}BOY_KEY_TYPE;

using namespace std;

class Boy
{
public:
	Boy(const char* name, int age, int salary,
		int darkHorse);
	~Boy();

	Boy(int salary);
	Boy(const char* name);

	string description();

	

	// 重载赋值运算符
	Boy& operator=(const Boy& boy);  //函数返回类型是 & 类型, 参数中加const保护实际参数不会被修改

	bool operator>(const Boy& boy);
	bool operator<(const Boy& boy);
	bool operator==(const Boy& boy);

	// 类型运算符重载, 不需要返回类型
	operator int() const;
	operator char* () const;

	// 实现下标运算符的重载
	int operator[](string index) const;
	int operator[](int index) const;

	//ostream& operator<<(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Boy& boy);
	friend istream& operator>>(istream& is, Boy& boy);

private:
	char* name;
	int age;
	int salary;
	int darkHouse;  // 黑马值, 表示潜力系数
	unsigned int id;  //编号
	static int LAST_ID;

	int power() const;  // 综合能力值
};

ostream& operator<<(ostream& os, const Boy& boy);
istream& operator>>(istream& is, Boy& boy);