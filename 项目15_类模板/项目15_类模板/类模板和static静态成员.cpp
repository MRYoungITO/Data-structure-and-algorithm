#include <iostream>

using namespace std;

template <typename T>
class A
{
public:
	A(T t = 0);

	// 声明一个友元函数, 实现对两个对象A类对象进行加法操作
	template <typename T>
	friend A<T> addA(const A<T>& a, const A<T>& b);

	T& getT();

	A operator +(const A& other);

	void print();

public:
	static T count;

private:
	T t;
};

template <typename T> T A<T>::count = 666;

template <typename T>
A<T>::A(T t)
{
	this->t = t;
}

template <typename T>
T& A<T>::getT()
{
	return t;
}

template <typename T>
A<T> A<T>::operator+(const A<T>& other) {
	A<T> tmp; //类的内部类型可以显示声明也可以不显示
	tmp.t = this->t + other.t;
	return tmp;
}

template <typename T>
void A<T>::print() {
	cout << this->t << endl;
}


// A 类的友元函数, 就是它的好朋友
template <typename T>
A<T> addA(const A<T>& a, const A<T>& b) {
	A<T> tmp;
	cout << "call addA(). . ." << endl;
	tmp.t = a.t + b.t;
	return tmp;
}

// 当我们虚拟的类型T被int实例化以后, 模板类如下:
// 
//class A
//{
//public:
//	A(int t = 0);
//
//	int& getT();
//
//	A operator +(const A& other);
//
//	void print();
//
//public:
//	static int count;
//
//private:
//	int t;
//};
//
//int A::count = 666;
//
//A::A(int t)
//{
//	this->t = t;
//}
//
//
//int& A::getT()
//{
//	return t;
//}
//
//A A::operator+(const A& other) {
//	A tmp; //类的内部类型可以显示声明也可以不显示
//	tmp.t = this->t + other.t;
//	return tmp;
//}
//
//
//void A::print() {
//	cout << this->t << endl;
//}

// 当我们虚拟的类型T被float实例化以后, 模板类如下:
// 
//class A
//{
//public:
//	A(float t = 0);
//
//	flaot& getT();
//
//	A operator +(const A& other);
//
//	void print();
//
//public:
//	static int count;
//
//private:
//	float t;
//};
//
//int A::count = 666;
//
//A::A(float t)
//{
//	this->t = t;
//}
//
//
//float& A::getT()
//{
//	return t;
//}
//
//A A::operator+(const A& other) {
//	A tmp; //类的内部类型可以显示声明也可以不显示
//	tmp.t = this->t + other.t;
//	return tmp;
//}
//
//
//void A::print() {
//	cout << this->t << endl;
//}

int main(void) {

	A<int> a(666), b(888);  // <int>的意思是A类类模板的参数列表是整形, A类类模板中的T将被替换为int
	A<int> tmp = a + b;
	//A a(666), b(888);
	//A tmp = a + b;

	A<float> c(777), d(999);

	a.count = 888;
	cout <<"b.count: " << b.count << endl;

	cout << "c.count: " << c.count << endl;
	cout << "修改前 d.count: " << d.count << endl;
	c.count = 1000;
	cout << "修改后 d.count: " << d.count << endl;

	//tmp.print();

	system("pause");
	return 0;
}