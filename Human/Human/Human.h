#pragma once

#include <string>

using namespace std;

#define ADDR_LENS 64

class Human {
public:
	Human();
	Human(string name, int age, int salary);
	Human(const Human& copy);
	Human& operator=(const Human& assignment);
	~Human();
	void descripiton();
	void setAddr(const char* newAddr);
	Human& compare(Human& comparison);
	Human* compare2(Human* comparison);
	int getHumanCount();

private:
	string name;
	int age;
	int salary;
	char* addr;

	static int humanCount;
};