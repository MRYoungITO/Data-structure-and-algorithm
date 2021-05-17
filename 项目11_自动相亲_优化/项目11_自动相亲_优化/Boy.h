#pragma once
#include <string>
#include <vector>
#include "Single.h"

using namespace std;
class Girl;

class Boy :public Single
{
public:
	Boy();
	Boy(int age, string name, int salary);
	~Boy();

	//int getAge() const;
	//string getName() const;
	int getSalary() const;
	bool satisfied(const Girl& girls) const;
	string description() const;
	static void inputBoys(vector<Boy>& boys);
private:
	//int age;
	//string name;
	int salary;
};

