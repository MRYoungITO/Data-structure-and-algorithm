#include "Boy.h"
#include "Girl.h"
#include <sstream>

#define SALARY_FACTOR 0.006

Boy::Boy() {
	age = 0;
	name = "";
	salary = 0;
}

Boy::Boy(int age, string name, int salary) {
	this->age = age;
	this->name = name;
	this->salary = salary;
}

Boy::~Boy() {

}

int Boy::getAge() const {
	return age;
}

string Boy::getName() const {
	return name;
}

int Boy::getSalary() const {
	return salary;
}

string Boy::description() const {
	stringstream ret;
	ret << name << "-ÄÐ-(" << salary << ")-ÄêÁä(" << age << ")";
	return ret.str();
}

bool Boy::satisfied(const Girl& girl) {
	if (girl.getYanZhi() >= salary * SALARY_FACTOR) {
		return true;
	}
	else {
		return false;
	}
}