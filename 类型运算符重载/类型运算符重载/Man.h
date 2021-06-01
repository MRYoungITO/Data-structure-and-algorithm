#pragma once

class Boy;

class Man
{
public:
	Man(const char* name, int age, int salary);
	Man(const Boy& boy);
	~Man();

private:
	char* name;
	int age;
	int salary;
};

