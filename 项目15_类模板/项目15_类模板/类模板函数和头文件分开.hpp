#include <iostream>
#include <Windows.h>
#include "类模板函数和头文件分开.h"

using namespace std;

template <typename T>
A<T>::A(T t) {
	this->t = t;
}

template <typename T>
T& A<T>::getT() {
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