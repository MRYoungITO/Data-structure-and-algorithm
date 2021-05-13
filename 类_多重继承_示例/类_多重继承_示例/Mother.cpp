#include <iostream>
#include "Mother.h"

Mother::Mother(const char* food, const char* lastName, const char* firstName)
{
	cout << __FUNCTION__ << endl;
	this->lastName = lastName;
	this->firstName = firstName;
	this->food = food;
}

Mother::~Mother()
{

}

void Mother::dance()
{
	cout << "一起跳舞吧, 一二三四, 二二三四..." << endl;
}
