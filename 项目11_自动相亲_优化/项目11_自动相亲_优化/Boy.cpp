#include "Boy.h"
#include "Girl.h"
#include <sstream>
#include <iostream>

#define SALARY_FACTOR 0.006

Boy::Boy() {
	age = 0;
	name = "";
	salary = 0;
}

Boy::Boy(int age, string name, int salary) : Single(age, name) {
	//this->age = age;
	//this->name = name;
	this->salary = salary;
}

Boy::~Boy() {

}

/*
int Boy::getAge() const {
	return age;
}

string Boy::getName() const {
	return name;
}
*/

int Boy::getSalary() const {
	return salary;
}

bool Boy::satisfied(const Girl& girls) const {
	int yanzhi = salary * SALARY_FACTOR;
	if (yanzhi > 100) {
		yanzhi = 100;
	}
	if (girls.getYanzhi() >= yanzhi) {
		return true;
	}
	else {
		return false;
	}
}

string Boy::description() const {
	stringstream ret;
	ret << name << "-男-(" << salary << ")-年龄(" << age << ") ";
	return ret.str();
}

void Boy::inputBoys(vector<Boy>& boys) {
	int age;
	string name;
	int salary;

	int n = 1;
	while (1) {
		cout << "请输入第" << n << "位小哥哥的年龄【输入0结束】: ";
		cin >> age;
		if (age == 0) {
			break;
		}
		cout << "请输入第" << n << "位小哥哥的姓名: ";
		cin >> name;
		cout << "请输入第" << n << "位小哥哥的薪资: ";
		cin >> salary;

		boys.push_back(Boy(age, name, salary));
		n++;
	}
}