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
	void do_something() { cout << "do something..." << endl; }
};

class DestructTest {  //重载了operator() 操作符, 与普通函数行为类似, 定义为仿函数
public:
	void operator()(Test* pt){
		pt->do_something();
		delete pt;
	}
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
	
	//1.构造函数
	//普通的unique_ptr 变量定义
	//unique_ptr<Test> up1;
	//unique_ptr<Test> up2(new Test());
	//up1 = std::move(up2);

	////数组对象的的unique_ptr 的定义
	//unique_ptr<Test[]> up3;
	//{
	//	unique_ptr<Test[]> up4(new Test[5]);
	//}
	//
	//Test* t1 = new Test();
	//up1.reset(t1);

	//使用自定义的删除器
	/*{
		unique_ptr<Test, DestructTest>up5(new Test());
	}*/

	//2赋值, 一定要使用移动语义
	//unique_ptr<Test>up6(new Test());
	//unique_ptr<Test>up7(new Test());
	//up6 = std::move(up7);  //必须使用移动语义, 结果, up6 内存释放, up7交由up6管理

	//up6->do_something();

	//3. 主动释放对象
	unique_ptr<Test>up8(new Test());
	up8 = NULL; //或者 up8 = nullptr;  或者up8.reset();

	printf("up8: %p\n", up8.get());

	system("pause");
	return 0;
}