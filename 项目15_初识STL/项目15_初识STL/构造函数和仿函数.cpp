#include <set>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

class student {
public:
	student(int age) {
		this->age = age;
	}

	bool operator<(const student& right) const{
		return this->age < right.age;
	}

	bool operator>(const student& right) const {
		return this->age > right.age;
	}

	int getAge() const {
		return age;
	}

private:
	int age;
	string name;
};

class FunStudent {
public:
	bool operator()(const student& left, const student& right) const {
		cout << "调用了 FunStudent ." << endl;
		return left < right;
	}
public:
	int ret;
};

int main(void) {

	//less 函数对象实现比较, 为排序提供依据
	//less 和 greater 都是函数对象, 又叫仿函数
	//set<int, less<int>> set1;

	set<int, greater<int>> set1;

	for (int i = 5; i > 0; i--) {
		set1.insert(i);
	}

	//less<student>
	set<student, FunStudent> setStu;  //等同于 set<student, less<student>>
	student lixiaohua(18);
	student wangdachui(19);
	
	//函数对象(仿函数)可以像函数一样直接调用
	FunStudent funStu;
	bool ret = funStu(lixiaohua, wangdachui);

	cout << "比较结果: " << ret << endl;

	setStu.insert(lixiaohua);
	setStu.insert(wangdachui);

	/*for (set<int, greater<int>>::iterator it = set1.begin(); it != set1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;*/

	for (set<student, FunStudent>::iterator it = setStu.begin(); it != setStu.end(); it++) {
		cout << it->getAge() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}