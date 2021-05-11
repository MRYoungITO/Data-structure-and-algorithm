#include <sstream>
#include <iostream>
#include "Father.h"

using namespace std;

Father::Father(const char* name, int age)
{
	cout << __FUNCTION__ << endl;
	this->name = name;
	this->age = age;
}

Father::~Father()
{

}

string Father::getName() const
{
	return name;
}

int Father::getAge() const
{
	return age;
}

string Father::description() const
{
	stringstream ret;
	ret << "ÐÕÃû: " << name << " ÄêÁä: " << age;
	return ret.str();
}
