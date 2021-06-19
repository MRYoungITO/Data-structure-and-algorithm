#include <iostream>

using namespace std;

//第一版
int Max(int a, int b)
{
	cout << "调用 int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b)
{
	cout << "调用 T Max(T a, T b)" << endl;
	return a > b ? a : b;
}

template <typename T>
T Max(T a, T b, T c) {
	cout << "调用 T Max(T a, T b, T c)" << endl;
	return Max(Max(a, b), c);
}

//第二版
int Max1(int a, int b)
{
	cout << "调用 int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template<typename T1, typename T2>
T1 Max1(T1 a, T2 b)
{
	cout << "调用 T Max1(T1 a, T2 b)" << endl;
	return a > b ? a : b;
}


void main(void) {
	int a = 1;
	int b = 2;


	//当函数模板和普通函数都符合调用时,优先选择普通函数
	//cout<<"Max(a, b)"<<Max(a, b)<<endl;

	//如果显式的使用函数模板,则使用<> 类型列表
	//Max<>(a, b);

	char c = 'a';
	//如果函数模板会产生更好的匹配，使用函数模板
	//Max1(c, a);
	//Max(1.0, 2.0);

	Max(3.0, 4.0, 5.0);

	system("pause");
	return;
}