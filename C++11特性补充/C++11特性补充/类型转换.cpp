#include <iostream>
#include <Windows.h>

using namespace std;

struct dog_ {
	int age;
};

int main(void) {

	double PI = 3.1415926;

	int i = PI; //隐式转换
	int i1 = (int)PI; //强制类型转换, 把double 转成int
	int i2 = static_cast<int>(PI);
	

	//struct dog_* dq = static_cast<struct dog_*>(&PI); //NO!

	int* addr = (int*)0X888888; //强制类型转化, 整数直接变指针
	//int* adde1 = static_cast<int*>(0x888888);
	int* addr2 = reinterpret_cast <int*>(0x888888);

	system("pause");
	return 0;
}