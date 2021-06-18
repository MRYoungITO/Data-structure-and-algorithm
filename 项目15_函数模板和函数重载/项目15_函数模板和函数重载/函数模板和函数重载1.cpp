#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
 
void Swap(T& a, T& b) {
	T t;
	t = a;
	a = b;
	b = t;
	cout << "Swap 模板函数被调用了" << endl;
}

//void Swap(char& a, int& b) {
//	int t;
//	t = a;
//	a = b;
//	b = t;
//	cout << "Swap 普通函数被调用了" << endl;
//}

int main(void) {
	char cNum = 'c';
	int iNum = 65;

	// 第一种情况 模板函数和普通函数并存, 参数类型和普通重载函数更匹配
	// 调用普通函数
	//Swap(cNum, iNum);

	//第二种情况 不存普通函数, 函数模板会隐式数据类型转换嘛?
	// 结论: 不提供隐式的数据类型转换, 必须是严格的匹配
	//Swap(cNum, iNum);

	system("pause");
	return 0;
}