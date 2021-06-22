#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Vector {
public:
	Vector(int size = 128);  //构造函数
	Vector(const Vector& object);  //拷贝构造函数

	int getLength();  //获取内部存储的元素个数

	template <typename T>
	friend ostream& operator<<(const ostream& os, const Vector<T>& object);

	//Vector<int> a1, a2;  a1[0]
	T& operator[](int index);

	//实现=操作符重载
	//a1 = a2 = a3;
	Vector& operator=(const Vector& object);

	~Vector();  //析构函数

private:
	T* m_base;
	int m_len;
};

template <typename T>
ostream& operator<<(const ostream& os, const Vector<T>& object);