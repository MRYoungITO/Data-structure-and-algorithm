#include <sstream>
#include <iostream>
#include <iomanip>
#include "Girl.h"
#include "Boy.h"

#define YANZHI_FACTOR 100

Girl::Girl() {

}

Girl::Girl(int age, string name, int yanZhi) :Single(name, age) {
	//this->age = age;
	//this->name = name;
	this->yanZhi = yanZhi;
}

Girl::~Girl() {

}

/*
int Girl::getAge() const {
return age;
}
string Girl::getName() const {
return name;
}
*/

int Girl::getYanZhi() const {
	return yanZhi;
}

bool Girl::satisfied(const Boy& s) const {
	if (s.getSalary() >= yanZhi * YANZHI_FACTOR) {
		return true;
	}
	else {
		return false;
	}
}

string Girl::description() const {
	// 规范一下字符串格式:
	//性别:女\t\t\t姓名:无名\t\t\t颜值:90\t\t\t年龄:25

	stringstream ret;
	//ret << name << "-女-颜值(" << yanZhi << ")-年龄(" << age << ")";
	//ret << getName() << "-女-颜值(" << yanZhi << ")-年龄(" << getAge() << ")"; 
	ret << "性别:女"
		<< "\t\t\t姓名:" << name
		<< "\t\t\t颜值:" << setw(3) << setiosflags(ios::left) << yanZhi
		<< "\t\t\t年龄:" << age;
	return ret.str();
}

void Girl::inputGirls(vector<Girl>& girls) {
	int age;
	string name;
	int yanZhi;
	int n = 1;
	while (1) {
		cout << "请输入第" << n << "位小姐姐的年龄【输入0结束】：";
		cin >> age;
		if (age == 0) {
			break;
		}
		cout << "请输入第" << n << "位小姐姐的姓名：";
		cin >> name;
		cout << "请输入第" << n << "位小姐姐的颜值：";
		cin >> yanZhi;
		n++;
		girls.push_back(Girl(age, name, yanZhi));
	}
}

void Girl::inputGirl(Girl& girl)
{
	int age;
	string name;
	int yanZhi;

	cout << "请输入小姐姐的年龄：";
	cin >> age;

	cout << "请输入小姐姐的姓名：";
	cin >> name;

	cout << "请输入小姐姐的颜值：";
	cin >> yanZhi;

	girl = Girl(age, name, yanZhi);
}

bool Girl::operator>(const Girl& girl)
{
	return yanZhi > girl.yanZhi;
}

ostream& operator<<(ostream& os, const Girl& girl)
{
	os << "性别:女"
		<< "\t\t\t姓名:" << girl.name
		<< "\t\t\t颜值:" << setw(3) << setiosflags(ios::left) << girl.yanZhi
		<< "\t\t\t年龄:" << girl.age;
	return os;
}
