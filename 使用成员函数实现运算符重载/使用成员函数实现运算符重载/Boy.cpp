#include <sstream>
#include "Boy.h"

int Boy::LAST_ID = 0;

Boy::Boy(const char* name, int age, int salary, int darkHorse)
{
	if (!name) {
		name = "未命名";
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->age = age;
	this->salary = salary;
	this->darkHouse = darkHorse;
	this->id = ++LAST_ID;
}

Boy::~Boy()
{
	if (name) {
		delete name;
	}
}

string Boy::description()
{
	stringstream ret;
	ret << "ID:" << id << "\t姓名:" << name << "\t年龄:" << age
		<< "\t薪资:" << salary << "\t黑马系数:" << darkHouse;
	return ret.str();
}

Boy& Boy::operator=(const Boy& boy)
{
	if (name) {
		delete name;  //释放原来的内存
	}
	name = new char[strlen(boy.name) + 1];
	strcpy_s(name, strlen(boy.name) + 1, boy.name);

	this->age = boy.age;
	this->salary = boy.salary;
	this->darkHouse = boy.darkHouse;
	//  this->id = boy.id;  // 根据需求来确定是否要拷贝id
	return *this;
}

bool Boy::operator>(const Boy& boy)
{
	// 设置一个比较规则
	// 薪资 * 黑马系数 + (100-年龄) * 1000
	if (this->power() > boy.power()) {
		return true;
	}
	else {
		return false;
	}
}

bool Boy::operator<(const Boy& boy)
{
	if (this->power() < boy.power()) {
		return true;
	}
	else {
		return false;
	}
}

bool Boy::operator==(const Boy& boy)
{
	if (this->power() == boy.power()) {
		return true;
	}
	else {
		return false;
	}
}

int Boy::power() const
{
	// 薪资 * 黑马系数 + (100-年龄) * 1000
	int ret = salary * darkHouse + (100 - age) * 1000;
	return ret;
}
