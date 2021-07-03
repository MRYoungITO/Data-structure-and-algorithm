#include <iostream>
#include <string>
using namespace std;

#include <vector>
#include <list>
#include <deque>
#include <algorithm>

class student {
public:
	student() {
		cout << "无参构造函数被调用!" << endl;
	}
	student(int age, string name) {
		this->age = age;
		this->name = name;
		//strncpy_s(this->name, name, 64);
		cout << "有参构造函数被调用!" << endl;
		cout << "姓名: " << this->name << " 年龄: " << this->age << endl;
	}

	student(const student& s) {
		this->age = s.age;
		this->name = s.name;
		//strncpy_s(this->name, s.name, 64);
		cout << "拷贝构造函数被调用!" << endl;
	}
	~student() {
		cout << "析构函数被调用" << endl;
	}
private:
	int age;
	string name;
};

int main(void) {
	//vector<int> vectInt(10, 0);
	deque<int> dqInt;
	list<int> lstInt;

	vector<student> vectStu(10);

	cout << "vectStu size:" << vectStu.size() << endl;
	cout << "vectStu capacity:" << vectStu.capacity() << endl;

	//插入学生

	//方法一 先定义对象, 在插入
	//student xiaoHua(18, "李校花");
	//vectStu.push_back(xiaoHua);

	//方法二 直接插入临时对象
	//vectStu.push_back(student(19, "王大锤"));

	//C++11 新特性 变参模板和完美转发

	vectStu.emplace_back(19, "王大锤"); //push_back()
	cout << "vectStu size(1):" << vectStu.size() << endl;
	cout << "vectStu capacity(1):" << vectStu.capacity() << endl;

	vectStu.emplace(vectStu.end(), 18, "李校花");  //相当于 insert()
	cout << "vectStu size(2):" << vectStu.size() << endl;
	cout << "vectStu capacity(2):" << vectStu.capacity() << endl;

	system("pause");
	return 0;

}