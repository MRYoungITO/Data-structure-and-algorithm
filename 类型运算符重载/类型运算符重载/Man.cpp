#include <iostream>
#include "Man.h"

Man::Man(const char* name, int age, int salary) 
{
	if (!name) {
		name = "Î´ÃüÃû";
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->age = age;
	this->salary = salary;
}

Man::Man(const Boy& boy)
{
	int len = strlen(boy.getName()) + 1;
	name = new char[len];
}

Man::~Man()
{
	delete name;
}
