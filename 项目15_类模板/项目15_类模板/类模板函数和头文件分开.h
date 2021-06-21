#pragma once

template <typename T>
class A
{
public:
	A(T t = 0);
	T& getT();
	A operator+(const A& other);
	void print();

private:
	T t;
};