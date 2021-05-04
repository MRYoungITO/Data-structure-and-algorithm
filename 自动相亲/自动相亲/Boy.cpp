#include "Boy.h"

Boy::Boy() {
	age = 0;
	name = "";
	salary = 0;
}

Boy::~Boy() {

}

int Boy::getAge() const {
	return age;
}

string Boy::getName() const {
	return name;
}

int getSalary() const {
	return salary;
}