#pragma once
#include <string>
using namespace std;
class Mother
{
public:
	Mother(const char* food, const char* lastName = "无姓", const char* firstName = "无名");
	~Mother();

	void dance(); //跳舞
private:
	string lastName;  //姓
	string firstName;  //名
	string food;			//喜欢的食物
};

