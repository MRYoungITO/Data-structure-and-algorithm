#include <iostream>
#include "Vector.h"

using namespace std;

template <typename T>
Vector<T>::Vector(int size) { //构造函数
	if (size > 0) {
		m_len = size;
		m_base = new T[m_len];
	}
}

template <typename T>
Vector<T>::Vector(const Vector<T>& object) { //拷贝构造函数

	// 根据传入的对象元素个数分配空间
	m_len = object.m_len;
	m_base = new T[m_len];
	//strcpy_s(m_base, m_len, object.m_base);

	// 数据的拷贝
	for (int i = 0; i < this->m_len; i++) {
		m_base[i] = object.m_base[i];
	}
}

template<typename T>
int Vector<T>::getLength()
{
	return this->m_len;
}

template <typename T>
ostream& operator<<(const ostream& os, const Vector<T>& object) {

}


//Vector<int> a1, a2;  a1[0]
template <typename T>
T& Vector<T>::operator[](int index) {
	return this->m_base[index];  //return *(m_base+index);
}

//实现=操作符重载
//a1 = a2 = a3;
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& object) {
	if (m_base) {
		delete[] m_base;
		m_base = NULL;
		m_len = 0;
	}

	// 根据传入的对象元素个数分配空间
	m_len = object.m_len;
	m_base = new T[m_len];
	//strcpy_s(m_base, m_len, object.m_base);

	// 数据的拷贝
	for (int i = 0; i < this->m_len; i++) {
		m_base[i] = object.m_base[i];
	}

	return *this;  //a3 = a2 = a1;
}

template <typename T>
Vector<T>::~Vector() {  //析构函数
	if (m_base) {
		delete[] m_base;
		m_base = NULL;
		m_len = 0;
	}
}
