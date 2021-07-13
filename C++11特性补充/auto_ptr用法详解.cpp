#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <exception>

using namespace std;

//auto_ptr<Test> t(new Test());  //忠告1: 智能指针不要定义为全局变量

class Test {
public:
	Test() {
		cout << "Test is contrust" << endl;
		debug = 1;
	}
	~Test() { cout << "Test is detrust" << endl; }

	int getDebug() {
		return debug;
	}

private:
	int debug;
};

// 用法: auto_ptr<类型> 变量名(new 类型)

void memory_leak_demo1() {
	auto_ptr<Test> t(new Test());  //智能指针 C-98, 写法

	//忠告3: 除非自己知道后果, 不要吧ayto_ptr 智能指针赋值给同类型的另外一个智能指针 
	//auto_ptr<Test> t1;
	//t1 = t;

	//auto_ptr<Test>* tp = new auto_ptr<Test>(new Test()); //忠告2: 不要定义指向智能指针对象的指针变量

	//在使用智能指针访问对象时, 使用方式和普通指针一样
	cout << "-> debug: " << t->getDebug() << endl;
	cout << "* debug: " << (*t).getDebug() << endl;

	/*Test* tmp = t.get();
	cout << "get debug: " << tmp->getDebug() << endl;*/

	//release 取消指针对动态内存的托管, 之前分配的内存必须手动释放
	/*Test* tmp = t.release();
	delete tmp;*/

	//reset 重置智能指针托管的内存地址, 如果地址不一致, 原来的会被析构
	//t.reset();
	t.reset(new Test());

	if (0) {
		Test* t1 = new Test();
		t1->getDebug();
	}

	return;
}

int memory_leak_Demo2() {
	auto_ptr<Test> t(new Test());
	//Test* t = new Test();

	/*****************************************
	* 程序执行一段复杂的逻辑, 假设从一个必须存在
	* 的文件中读取某些数据, 为文件此时不存在
	******************************************/
	{
		throw exception("文件不存在");
	}
	//delete t;
	return 0;
}

int main(void) {

	memory_leak_demo1();

	/*try {
		memory_leak_Demo2();
	}
	catch (exception e) {
		cout << "catch execption: " << e.what() << endl;
	}*/

	system("pause");
	return 0;
}