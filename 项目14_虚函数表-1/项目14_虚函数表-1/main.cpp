#include <iostream>
#include <Windows.h>

using namespace std;
class Father
{
public:
	virtual void func1() { cout << "Father::func1" << endl; }
	virtual void func2() { cout << "Father::func2" << endl; }
	virtual void func3() { cout << "Father::func3" << endl; }
	void func4() { cout << "非虚函数: Father::func4" << endl; }
public:
	int x = 200;
	int y = 300;
	static int z;
};

class Son : public Father {
public:
	void func1() { cout << "Son::func1" << endl; }
	virtual void func5() { cout << "Son::func5" << endl; }
};

int Father::z = 0;

typedef void(*func_t)(void);  

int main(void) {
	/*Father father;

	cout << "sizeof(father)==" << sizeof(father) << endl;

	cout << "对象地址:" << (int*)&father << endl;
	int* vptr = (int*)*(int*)(&father);

	cout << "调用第一个虚函数: ";
	((func_t) * (vptr + 0))();

	cout << "调用第二个虚函数: ";
	((func_t) * (vptr + 1))();

	cout << "调用第三个虚函数: ";
	((func_t) * (vptr + 2))();

	cout << "第一个数据成员的地址: " << endl;
	cout << &father.x << endl;
	cout << std::hex << (int)&father + 4 << endl;
	cout << "第一个数据成员的值: " << endl;
	cout << std::dec << father.x << endl;
	cout << *(int*)((int)&father + 4) << endl;

	cout << "第二个数据成员的地址: " << endl;
	cout << &father.y << endl;
	cout << std::hex << (int)&father + 8 << endl;
	cout << "第二个数据成员的值: " << endl;
	cout << std::dec << father.y << endl;
	cout << *(int*)((int)&father + 8) << endl;*/

	//Son son;
	//cout << "son对象地址: " << (int*)&son << endl;  //(int*) 以指针16进制方式打印出来
	//int* vptr = (int*)*(int*)&son;
	//cout << "虚函数表指针vptr: " << vptr << endl;

	//for (int i = 0; i < 4; i++) {
	//	cout << "调用第" << i + 1 << "个虚函数: ";
	//	((func_t) * (vptr + i))();
	//}

	//for (int i = 0; i < 2; i++) {
	//	cout << *(int*)((int)&son + 4 + i * 4) << endl;
	//}

	//cout << "sizeof(son) == " << sizeof(son) << endl;

	Son son;
	Father* father = &son;
	father->func1();

	system("pause");
	return 0;
}