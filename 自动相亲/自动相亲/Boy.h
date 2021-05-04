#pragma once
#include <string>

using namespace std;

class Boy
{
public:
	Boy();
	~Boy();
	int getAge() const;
	string getName() const;
	int getSalary() const;
private:
	int age;
	string name;
	int salary;		//Ð½×Ê
};

