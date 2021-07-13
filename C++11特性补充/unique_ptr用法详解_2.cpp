#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class Test {
public:
	Test() { cout << "Test is construct" << endl; }
	~Test() { cout << "Test is destruct" << endl; }
	do_something() { cout << "do something..." << endl; }
};

/******************************************************************************************************************
unique_ptr<T> up ; //空的unique_ptr，可以指向类型为T的对象
*unique_ptr<T> up1(new T()) ;//定义unique_ptr,同时指向类型为T的对象
*unique_ptr<T[]> up ; //空的unique_ptr，可以指向类型为T[的数组对象
*unique_ptr<T[]> up1(new T[]) ;//定义unique_ptr,同时指向类型为T的数组对象
*unique_ptr<T,D> up(); //空的unique_ptr，接受一个D类型的删除器d，使用d释放内存
*unique_ptr<T,D> up(new T()); //定义unique_ptr,同时指向类型为T的对象，接受一个D类型的删除器d，使用删除器d来释放内存
*******************************************************************************************************************/

int main(void) {
	
	//普通的unique_ptr 变量定义
	unique_ptr<Test> up1;
	//unique_ptr<Test> up2(new Test());
	//up1 = std::move(up2);

	//数组对象的的unique_ptr 的定义
	unique_ptr<Test[]> up3;
	{
		unique_ptr<Test[]> up4(new Test[5]);
	}
	
	//Test* t1 = new Test();
	//up1.reset(t1);

	

	system("pause");
	return 0;
}