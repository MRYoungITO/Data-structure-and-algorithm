#include <iostream>
#include <Windows.h>

using namespace std;

void demo(const char* p) {

	//对指针去掉const
	//char* p1 = const_cast<char*>(p);
	//p1[0] = 'A';

	//直接去掉const修改
	const_cast<char*>(p)[0] = 'A';

	cout << p << endl;
}

//void demo(const int p) {
//	cout << p << endl;
//}

int main(void) {

	//字符串数组
	/*char p[] = "12345678";
	demo(p);*/  //合情合理

	//常量字符串不能去掉const 修改
	//再去掉常量限定符之前, 保证指针所指向的内存能够修改, 不能修改则会引起异常
	const char* cp = "987654321";
	demo(cp);

	system("pause");
	return 0;
}