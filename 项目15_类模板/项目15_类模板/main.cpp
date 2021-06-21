#include <Windows.h>
#include "类模板函数和头文件分开.hpp"

int main(void) {
	A<int> a(666), b(888);

	A<int> tmp = a + b;

	tmp.print();

	system("pause");
	return 0;
}