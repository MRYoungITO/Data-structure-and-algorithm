#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>

using namespace std;

#define ADDR_LEN 32

//定义一个"人类"
class Human {
public:
	Human();
	Human(int age, int salary, string name);
	Human(const Human&copy);

	void eat();
	void sleep();
	void play();
	void work();
	void description();	//test

	string getName();
	int getAge();
	int getSalary();
	void setAddr(const char* addr);

private:
	string name;
	int age;
	int salary;
	char* addr;		//地址
};

void Human::eat() {
	cout << "吃炸鸡, 喝啤酒! " << endl;
}

void Human::sleep() {
	cout << "我正在睡觉!" << endl;
}

void Human::play() {
	cout << "我在唱歌!" << endl;
}

void Human::work() {
	cout << "我在工作!" << endl;
}

string Human::getName() {
	return name;
}

int Human::getAge() {
	return age;
}

int Human::getSalary() {
	return salary;
}

Human::Human() {
	name = "无名";
	age = 18;
	salary = 20000;
}

Human::Human(int age, int salary, string name) {
	cout << "调用自定义的构造函数" << endl;
	this->age = age;	//this是一个特殊的指针, 指向这个对象本身
	this->salary = salary;
	this->name = name;;

	addr = new char[ADDR_LEN];
	strcpy_s(addr, ADDR_LEN, "China");
}

// Human h2 = h1;
Human::Human(const Human& copy) {	//const Human &copy = h1;
	cout << "调用拷贝构造函数" << endl;
	name = copy.name;
	age = copy.age;
	salary = copy.salary;

	//深度拷贝
	addr = new char[ADDR_LEN];
	strcpy_s(this->addr, ADDR_LEN, copy.addr);
}

void Human::setAddr(const char* newAddr) {
	if (!newAddr) {
		return;
	}
	strcpy_s(addr, ADDR_LEN, newAddr);
}

void Human::description() {
	cout << "age:" << age
		<< " name:" << name
		<< " salary:" << salary
		<< " addr:" << addr << endl;
}

int main(void) {
	Human h1(28, 35000, "young");	//使用自定义的构造函数
	Human h2 = h1;	//调用拷贝构造函数
	Human h3(h1);		//调用拷贝构造函数

	h1.description();
	h2.description();
	h3.description();

	h1.setAddr("美国");

	cout << "h1修改地址之后" << endl;
	h1.description();
	h2.description();
	h3.description();


	/*
	h1.eat();
	h1.play();
	h1.sleep();
	*/
	//cout << h1.getAge() << endl;

	/*
	Human* h2 = &h1;

	cout << "姓名: " << h2->getName() << endl;
	cout << "年龄: " << h2->getAge() << endl;
	cout << "薪资: " << h2->getSalary() << endl;
	*/
	system("pause");
	return 0;
}