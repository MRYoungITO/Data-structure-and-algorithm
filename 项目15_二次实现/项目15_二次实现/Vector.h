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

	template <typename T>
	friend ostream& operator<<(const ostream& os, const Vector<T>& object);

	T& operator[](int index);
	Vector& operator=(const Vector& object);

	~Vector();

private:
	T* m_base;
	int m_len;
};

template <typename T>
ostream& operator<<(const ostream& os, const Vector<T>& object);