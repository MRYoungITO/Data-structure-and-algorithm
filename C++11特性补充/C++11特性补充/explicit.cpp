#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class student {
public:
	/*explicit*/ student(int age) {
		this->age = age;
		cout << "age= " << this->age << endl;
	}

	/*explicit*/ student(int age, string name) {
		this->age = age;
		this->name = name;
		cout << "age= " << this->age << "; name= " << this->name << endl;
	}

	~student() {

	}

	int getAge() {
		return this->age;
	}

	string getName() {
		return this->name;
	}

private:
	int age;
	string name;
};

int main(void) {

	student xiaoMing(18);  //显示构造
	student xiaoWang = 18; //隐式构造

	student xiaoua(19, "小花");  //显示构造
	student xiaoMei = { 18, "小美" }; //隐式构造 初始化参数列表, C++11之前版本编译不能通过



	system("pause");
	return 0;
}