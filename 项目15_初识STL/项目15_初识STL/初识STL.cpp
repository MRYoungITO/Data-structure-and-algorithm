#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class student {
public:
	student(int age, const char* name) {
		this->age = age;
		strncpy_s(this->name, name, 64);
	}

	student(const student& s) {
		this->age = s.age;
		strncpy_s(this->name, s.name, 64);
		cout << "拷贝构造函数被调用!" << endl;
	}
public:
	int age;
	char name[64];
};

//容器中存放指针
void demo3() {
	vector<student*> v1;

	student s1(18, "李小美");
	student s2(19, "王大帅");

	v1.push_back(&s1);
	v1.push_back(&s2);

	cout << "v1 的学生个数: " << v1.size() << endl;

	//方式1, 下标访问
	/*for (unsigned int i = 0; i < v1.size(); i++) {
		cout << v1[i].name << ": " << v1[i].age << endl;
	}*/

	//方式2, 迭代器访问
	//第二部分 迭代器
	//1 2 3 4
	//it
	vector<student*>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << (**it).name << ": " << (**it).age << endl;
	}
}

void demo2() {
	vector<student> v1;

	student s1(18, "李小美");
	student s2(19, "王大帅");

	v1.push_back(s1);
	v1.push_back(s2);

	cout << "v1 的学生个数: " << v1.size() << endl;

	//方式1, 下标访问
	/*for (unsigned int i = 0; i < v1.size(); i++) {
		cout << v1[i].name << ": " << v1[i].age << endl;
	}*/

	//方式2, 迭代器访问
	//第二部分 迭代器
	//1 2 3 4
	//it
	vector<student>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << (*it).name << ": " << (*it).age << endl;
	}
}

void demo1() {
	//第一部分 容器
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(3);

	cout << "v1 的元素个数" << v1.size() << endl;
	cout << "v1中保存的元素:" << endl;
	//方式1, 下标访问
	/*for (unsigned int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}*/

	//方式2, 迭代器访问
	//第二部分 迭代器
	//1 2 3 4
	//it
	vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << *it << endl;
	}

	//第三部分 算法
	int ncount = count(v1.begin(), v1.end(), 90);
	cout << "v1 中数值为90 的元素个数:" << ncount << endl;

}

int main(void) {
	demo3();

	system("pause");
	return 0;
}