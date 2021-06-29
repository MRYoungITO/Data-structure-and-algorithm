#include <iostream>

using namespace std;

/*
设计一个数组类容器 Vector，重载[]操作，数组初始化时，对数组的个数进行有效检查
1）index<0 抛出异常errNegativeException
2）index = 0 抛出异常 errZeroException
3）index>1000抛出异常errTooBigException
4）index<10 抛出异常errTooSmallException
5）errSizeException类是以上类的父类，实现有参数构造、并定义virtual void printError()输出错误。

*/

class errSizeException {
public:
	errSizeException(int size) {
		m_size = size;
	}

	virtual	void printError() {
		cout << "size:" << m_size << endl;
	}

protected:
	int m_size;
};

class errNegativeException : public errSizeException {
public:
	errNegativeException(int size) : errSizeException(size) {

	}
	virtual	void printError() {
		cout << "errNegativeException size: " << m_size << endl;
	}
};

class errZeroException : public errSizeException {
public:
	errZeroException(int size) : errSizeException(size) {
		
	}
	virtual	void printError() {
		cout << "errZeroException size: " << m_size << endl;
	}
};

class errTooBigException : public errSizeException {
public:
	errTooBigException(int size) : errSizeException(size) {

	}
	virtual	void printError() {
		cout << "errTooBigException size: " << m_size << endl;
	}
};

class errTooSmallException : public errSizeException {
public:
	errTooSmallException(int size) : errSizeException(size) {

	}
	virtual	void printError() {
		cout << "errTooSmallException size: " << m_size << endl;
	}
};

class Vector {
public:
	Vector(int size = 128); //构造函数
	int getLength(); //获取内部存储的元素个数

	int& operator[](int index);
	~Vector();
private:
	int* m_base;
	int m_len;
};
Vector::Vector(int size) {
	if (size < 0) {
		throw errNegativeException(size);
	}
	else if (size == 0) {
		throw errZeroException(size);
	}
	else if (size > 1000) {
		throw errTooBigException(size);
	}
	else if (size < 10) {
		throw errTooSmallException(size);
	}

	m_len = size;
	m_base = new int[m_len];
}

Vector::~Vector() {
	if (m_base) {
		delete m_base;
		m_base = NULL;
		m_len = 0;
	}
}

int Vector::getLength() {
	return m_len;
}

int& Vector::operator[](int index) {
	return this->m_base[index];
}

int main(void) {

	try {
		Vector v(10000);
		for (int i = 0; i < v.getLength(); i++) {
			v[i] = i + 10;
			printf("v[i]:%d\n", v[i]);
		}
	}
	catch (errSizeException& err) {
		err.printError();
	}

	/*catch (errNegativeException &err) {
		err.printError();
	}
	catch (errZeroException &err) {
		err.printError();
	}
	catch (errTooBigException &err) {
		err.printError();
	}
	catch (errTooSmallException &err) {
		err.printError();
	}*/

	system("pause");
	return 0;
}