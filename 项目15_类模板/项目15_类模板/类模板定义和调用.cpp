#include <iostream>

using namespace std;


// 继承中父子类和模板类的结合情况
// 1.父子类一般类, 子类是模板类, 和普通继承的用法类似
// 2.子类是一般类, 父类是模板类, 继承时必须在子类里面实例化父类的类型参数
// 3. 父类和子类都是模板类, 子类的类型可以传递到父类中

//class B {
//public:
//	B(int b) {
//		this->b = b;
//	}
//
//private:
//	int b;
//};

template <typename T>
class A /*: public B*/
{
public:
	A(T t = 0); /*: B(0)*/
	// 成员函数返回值是用虚拟类型
	T& getT();
	A operator+(const A& other);
	void print();

private:
	T t;
};

//class A
//{
//public:
//	A(int t = 0);
//	// 成员函数返回值是用虚拟类型
//	int& getT();
//	A operator+(const A& other);
//	void print();
//
//private:
//	int t;
//};

template <typename T>
A<T>::A(T t) {
	this->t = t;
}

template <typename T>
T &A<T>::getT() {
	return t;
}

template <typename T>
A<T> A<T>::operator+(const A<T>& other) {
	A<T> tmp;  // 类的内部类型可以显示声明,也可以不显示
	tmp.t = this->t + other.t;
	return tmp;
}

template <typename T>
void A<T>::print() {
	cout << this->t << endl;
}

//template <typename Tb>
//class B : public A<int> {
//	public:
//	B(Tb b) : A<Tb>(b) {
//		this->b = b;
//	}
//
//private:
//	Tb b;
//};
//
//void printA(A<int> &a) {
//	cout << a.getT() << endl;
//}

int main(void) {
	// 1.模板类定义类对象, 必须显示指定类型
	// 2.模板中如果使用了构造函数, 则遵守以前的类的构造函数的调用规则
	A<int> a(666), b(888);
	//cout << a.getT() << endl;

	A<int> tmp = a + b;

	tmp.print();

	//B<int> b(888);
	//cout << "b(888) : "<< b.getT() << endl;

	// 模板类作为函数参数
	//printA(a);

	system("pause");
	return 0;
}