#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>

using namespace std;

#define ADDR_LEN 32

//定义一个"人类"
class Human {
public:
	Human();	//默认构造函数(不带参数)
	Human(string name, int age, int salary);	//自定义的构造函数(带参数)
	Human(const Human& copy);	//自定义的拷贝构造函数

	// =运算符重载函数
	Human& operator=(const Human& assignment);

	// 析构函数
	~Human();

	void eat();
	void sleep();
	void play();
	void work();
	void description(); 	//test

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

string Human::getName() {	// 若函数名后加const, 则内部的成员无法修改
	return name;
}

int Human::getAge() {
	return age;
}

int Human::getSalary() {
	return salary;
}

Human::Human() {
	cout << "调用构造函数: " << this << endl;
	name = "无名";
	age = 18;
	salary = 20000;

	addr = new char[ADDR_LEN];
	strcpy_s(addr, ADDR_LEN, "China");
}

Human::Human(string name, int age, int salary) {
	cout << "调用自定义的构造函数" << endl;
	this->name = name;	//this是一个特殊的指针, 指向这个对象本身
	this->age = age;
	this->salary = salary;

	addr = new char[ADDR_LEN];
	strcpy_s(addr, ADDR_LEN, "China");
}

Human::Human(const Human& copy) {
	cout << "调用拷贝构造函数" << endl;
	name = copy.name;
	age = copy.age;
	salary = copy.salary;


	addr = new char[ADDR_LEN];
	strcpy_s(addr, ADDR_LEN, copy.addr);		//深度拷贝
}

void Human::setAddr(const char* newAddr) {
	if (!newAddr) {
		return;
	}

	strcpy_s(addr, ADDR_LEN, newAddr);
}

void Human::description() {
	cout << "name:" << name
		<< " age:" << age
		<< " salary:" << salary
		<< " addr:" << addr << endl;
}

// 调用函数 showMsg(h1);
// 在进行参数传递时, 自动执行: Human man = h1;
void showMsg(Human man) {
	cout << man.getName() << "的基本信息: ";
	man.description();
}

Human getBetterMan(Human man1, Human man2) {
	if (man1.getSalary() > man2.getSalary()) {
		return man1;
	}
	else {
		return man2;
	}
}

Human& Human::operator=(const Human& assignment) {
	// 防止对象给自己赋值  f1 = f1;
	if (this == &assignment) {
		return *this;
	}

	// 比如执行: f1 = f2;
	// 就会调用: f1.opreator= (f2);
	name = assignment.name;
	age = assignment.age;
	salary = assignment.salary;

	// 如果有必要, 需要先释放自己的资源(动态内存)
	//delete addr;
	addr = new char[ADDR_LEN];
	// 深拷贝
	strcpy_s(addr, ADDR_LEN, assignment.addr);

	// 返回对象本身的引用, 是为了方便做链式处理 例如: f1 = f2 = f3;
	return *this;
}

Human::~Human() {
	cout << "调用析构函数" << this << endl;
	delete addr;
}

void test() {
	Human h1;
	{
		Human h2;
	}
	cout << "test() end. " << endl;
}

int main(void) {
	test();

	/*
	Human f1("Young", 28, 30000), f2;
	f2 = f1;		// 自动调用赋值构造函数! 位拷贝(浅拷贝)
	f1.description();
	f2.description();

	cout << "-----------------------------------" << endl;

	f1.setAddr("新加坡");
	f1.description();
	f2.description();
	*/
	/*
	Human f1(18, 20000, "Young");
	Human f2 = f1;
	Human f3 = f1;
	Human f4(f1);

	Human F4[4] = { f1,f2,f3,f4 };
	*/
	/*
	Human h1(28, 35000, "young");	//使用自定义的构造函数
	Human h2(29, 40000, "young");

	getBetterMan(h1, h2);		// 返回了一个临时对象
	*/
	system("pause");
	return 0;
}