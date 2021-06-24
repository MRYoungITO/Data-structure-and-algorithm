#include <iostream>
#include <Windows.h>
#include "Vector.cpp"

class Student {
	friend ostream& operator<<(ostream& os, const Student& object);
public:
	Student() {
		this->age = 0;
		name[0] = '\0';
	}
	Student(int age, const char* name) {
		this->age = age;
		strcpy_s(this->name, 64, name);
	}

	void print() {
		cout << this->name << ", " << this->age << endl;
	}

	~Student() {

	}
private:
	int age;
	char name[68];
};

ostream& operator<<(ostream& os, const Student& object) {
	os << "(" << object.name << ", " << object.age << ")";
	return os;
}

int main(void) {
	Vector<int> v1(5);
	Vector<int> v2(3);
	for (int i = 0; i < v1.getLength(); i++) {
		v1[i] = i;
	}
	for (int i = 0; i < v1.getLength(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;

	v2 = v1;
	cout << v2;

	Vector<int> v3(v2);
	cout << v3;

	Vector<float> v4(10);
	for (int i = 0; i < v4.getLength(); i++) {
		v4[i] = i * 0.1f;
	}
	cout << v4;

	Student s1(41, "Rock");
	Student s2(40, "Martin");

	Vector<Student> myStudentVector(2);
	myStudentVector[0] = s1;
	myStudentVector[1] = s2;
	for (int i = 0; i < myStudentVector.getLength(); i++) {
		cout << myStudentVector[i] << endl;
	}

	system("pause");
	return 0;
}