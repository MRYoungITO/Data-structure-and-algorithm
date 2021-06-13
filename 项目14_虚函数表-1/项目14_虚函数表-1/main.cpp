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
private:
	int x = 200;
	int y = 300;
	static int z;
};

int Father::z = 0;

int main(void) {
	Father father;

	cout << "sizeof(father)==" << sizeof(father) << endl;

	cout << "对象地址:" << (int*)&father << endl;
	int* vptr = (int*)*(int*)(&father);

	cout << "调用第一个虚函数: ";
	*vptr

	system("pause");
	return 0;
}