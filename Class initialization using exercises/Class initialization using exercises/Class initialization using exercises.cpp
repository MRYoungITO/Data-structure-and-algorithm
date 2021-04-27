#include <iostream>
#include <string>
#include <Windows.h>

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

private:
	string name;
	int age;
	int salary;
	char* addr;
};

Human::Human() {
	name = "Young";
	age = 28;
	salary = 30000;
	addr = new char[ADDR_LENS];
	strcpy_s(addr, ADDR_LENS, "中国");
}

Human::Human(string name, int age, int salary) {
	this->name = name;
	this->age = age;
	this->salary = salary;
	addr = new char[ADDR_LENS];
	strcpy_s(this->addr, ADDR_LENS, "中国");
}

Human::Human(const Human& copy) {
	name = copy.name;
	age = copy.age;
	salary = copy.salary;
	addr = new char[ADDR_LENS];
	strcpy_s(addr, ADDR_LENS, copy.addr);
}

Human& Human::operator=(const Human& assignment) {
	name = assignment.name;
	age = assignment.age;
	salary = assignment.salary;
	addr = new char[ADDR_LENS];
	strcpy_s(addr, ADDR_LENS, assignment.addr);

	return *this;		// 返回这个对象本身
}

void Human::descripiton() {
	cout << "name:" << name
		<< " age:" << age
		<< " salary:" << salary
		<< " addr:" << addr << endl;
}

void Human::setAddr(const char* newAddr) {

	strcpy_s(this->addr, ADDR_LENS, newAddr);
}

Human::~Human() {
	delete addr;
}

Human& Human::compare(Human& comparison) {
	if (salary > comparison.salary) {
		return *this;
	}
	else {
		return comparison;
	}
}

Human* Human::compare2(Human* comparison) {
	if (salary > comparison->salary) {
		return this;
	}
	else {
		return comparison;
	}
}

int main(void) {
	Human h1("Young", 28, 28000), h4;
	Human h2 = h1;
	Human h3(h1);
	h4 = h1;
	h1.descripiton();
	h2.descripiton();
	h3.descripiton();
	h4.descripiton();

	cout << "-----------------------------------------" << endl;

	h1.setAddr("美国");
	h2.setAddr("日本");
	h3.setAddr("新加坡");
	h1.descripiton();
	h2.descripiton();
	h3.descripiton();
	h4.descripiton();

	Human h5("Young", 28, 28000);
	Human h6("LaoYang", 30, 30000);
	
	h5.compare(h6).descripiton();
	
	Human* p = &h1;
	p->compare2(&h2)->descripiton();

	system("pause");
	return 0;
}