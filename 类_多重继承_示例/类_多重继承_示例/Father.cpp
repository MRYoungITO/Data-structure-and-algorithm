#include <iostream>
#include "Father.h"

Father::Father(const char* lastName, const char* firstName)
{
	cout << __FUNCTION__ << endl;
	this->lastName = lastName;
	this->firstName = firstName;
}

Father::~Father()
{

}

void Father::playBasketball() const
{
	cout << "呦呦, 我要三步上篮了!" << endl;
}

void Father::dance() const
{
	cout << "一起跳locking舞吧, 一二三四, 二二三四..." << endl;
}
