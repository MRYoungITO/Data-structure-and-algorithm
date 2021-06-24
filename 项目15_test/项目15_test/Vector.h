#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Vector
{
public:
	Vector(int size = 128);
	Vector(const Vector& object);
	int getLength();
	friend ostream& operator<< <T> (ostream& os, const Vector<T>& object);
	T& operator[](int index);
	Vector& operator=(const Vector& object);

	~Vector();
private:
	int m_len;
	T* m_base;

};

