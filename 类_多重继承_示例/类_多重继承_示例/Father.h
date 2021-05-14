#pragma once
#include <string>
using namespace std;
class Father
{
public:
	Father(const char* lastName="无姓",const char* firstName="无名");
	~Father();

	void playBasketball() const;  //打篮球
	void dance() const;
protected:
	string lastName;  //姓
	string firstName;  //名字
};

