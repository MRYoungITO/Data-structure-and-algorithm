#include "Girl.h"
#include <sstream>		//stringstream

// 颜值系数
#define YANZHI_FACTOR	100

Girl::Girl() {
	age = 0;
	name = "";
	yanZhi = 0;
}

Girl::Girl(int age, string name, int yanZhi) {
	this->age = age;
	this->name = name;
	this->yanZhi = yanZhi;
}

Girl::~Girl() {

}

int Girl::getAge() const {
	return age;
}

string Girl::getName() const {
	return name;
}

int Girl::getYanZhi() const {
	return yanZhi;
}

bool Girl::satisfied(const Boy& boy) {
	// to do
	return false;
}

string Girl::description() const {
	stringstream ret;
	ret << name << "-女-颜值(" << yanZhi << ")-年龄(" << age << ")";
	return ret.str();
}

