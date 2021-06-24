#include <iostream>
#include <Windows.h>
#include "Vector.cpp"
using namespace std;

class Student {
	friend ostream& operator<<(ostream& out, const Student& object);
	friend ostream& operator<<(ostream& out, const Student* object);
public:
	Student() {
		this->age = 0;
		this->pname = new char[64];
		strcpy_s(this->pname, 64, "\0");
	}
	Student(int age, const char* name) {
		this->age = age;
		this->pname = new char[64];
		strcpy_s(this->pname, 64, name);
	}

	Student& operator=(const Student& object) {
		if (this->pname) {
			delete[] pname;
			this->pname = NULL;
			this->age = 0;
		}

		this->age = object.age;
		this->pname = new char[64];
		strcpy_s(this->pname, 64, object.pname);

		return *this;
	}

	void print() {
		cout << pname << ", " << age << endl;
	}

	~Student() {
		if (this->pname) {
			delete[] pname;
			this->pname = NULL;
			this->age = 0;
		}
	}
private:
	int age;
	char* pname;
};

ostream& operator<<(ostream& out, const Student& object) {
	out << "(" << object.pname << ", " << object.age << ")";
	return out;
}

ostream& operator<<(ostream& out, const Student* object) {
	out << "(" << object->pname << ", " << object->age << ")";
	return out;
}

int main(void) {
	Student s1(18, "李小花");
	Student s2(19, "王大炮");
	Student s3;
	s3 = s2;
	cout << s3 << endl;

	Vector<Student*> studentVector(3);
	studentVector[0] = &s1;
	studentVector[1] = &s2;
	studentVector[2] = &s3;

	//for (int i = 0; i < studentVector.getLength(); i++) {
	//	studentVector[i].print();
	//}

	cout << studentVector << endl;

	Vector<int> myVector(10);
	// int a[10];  len: sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < myVector.getLength(); i++) {
		myVector[i] = i;
	}

	cout << myVector << endl;
	system("pause");

	for (int i = 0; i < myVector.getLength(); i++) {
		cout << myVector[i] << endl;
	}

	// 测试拷贝构造函数
	Vector<int> myIntVector1(myVector);
	cout << "新的myIntVector1中的元素如下: " << endl;
	for (int i = 0; i < myIntVector1.getLength(); i++) {
		cout << myIntVector1[i] << endl;
	}
	cout << "---end---" << endl;

	// 测试赋值运算符重载
	Vector<int> myIntVector2(1);
	myIntVector2 = myIntVector1;

	cout << "新的myIntVector2中的元素如下: " << endl;
	for (int i = 0; i < myIntVector2.getLength(); i++) {
		cout << myIntVector2[i] << endl;
	}
	cout << "---end---" << endl;

	Vector<float> myVector1(10);
	// int a[10];  len: sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < myVector1.getLength(); i++) {
		myVector1[i] = i * 0.1f;
	}

	for (int i = 0; i < myVector1.getLength(); i++) {
		cout << myVector1[i] << endl;
	}

	system("pause");
	return 0;
}