#pragma once
#include <string>
using namespace std;
class Father
{
public:
	Father(const char* name,int age);
	~Father();

	string getName() const;
	int getAge() const;
	string description() const;
private:
	string name;
	int age;
};

