#pragma once
#include <string>

using namespace std;

class Girl;

class Boy
{
public:
	Boy();
	Boy(int age, string name, int salary);
	~Boy();

	int getAge() const;
	string getName() const;
	int getSalary() const;
	string description() const;

	bool satisfied(const Girl& girl);
private:
	int age;
	string name;
	int salary;		//Ð½×Ê
};

