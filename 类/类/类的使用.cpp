#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

// 定义一个"人类"
class Human {
public:	//公有的,	对外的
	void eat();		//方法, "成员函数"
	void	sleep();
	void play();
	void work();
	string getname();
	int getAge();
	int gerSalary();

private:
	string name;		//此处定义了三个数据成员
	int age;
	int salary;
};

void Human::eat() {
	cout << "吃炸鸡, 喝啤酒!" << endl;
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

string Human::getname() {
	return name;
}

int Human::getAge() {
	return age;
}

int Human::gerSalary() {
	return salary;
}

int main(void) {
	Human zhangsan;

	system("pause");
	return 0;
}