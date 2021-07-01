#include <deque>
#include <iostream>
#include <Windows.h>

using namespace std;

class student {
public:
	student(int age) {
		cout << "construct student, age: " << age << endl;
		this->age = age;
	}

	student(const student& other) {
		cout << "拷贝构造函数: " << endl;
		this->age = other.age;
	}

	~student() {
		cout << "desconstruct student. " << endl;
	}

	int getAge() {
		return this->age;
	}

private:
	int age;
};

int main(void){

	//1. deque 类模板默认构造
	deque<int> deqIntA;		//存放int的deque容器
	deque<float> deqFloat;  //存放float的deque容器
	deque<student>	deqStu; //存放student的deque容器

	deque<student*> deqStuP;

	//deqInt.push_back(1);
	deqFloat.push_back(0.1f);
	deqStu.push_back(student(18));

	//2. deque 带参的构造

	//方式一: 给定区间
	deque<int> deqIntB(deqIntA.begin(), deqIntA.end()); //构造函数将[begin, end)区间中的元素拷贝给本身

	//方式二: 指定n 个元素进行拷贝
	deque<int> deqIntC(10, 0);

	//方式三: 拷贝构造
	deque<int> deqIntD(deqIntC);

	/*cout << "deqIntD 中的元素: " << endl;
	for (unsigned int i = 0; i < deqIntD.size(); i++) {
		cout << deqIntD[i] << endl;
	}*/

	//deque头部和尾部的添加移除操作
	deqIntA.push_back(1);
	deqIntA.push_back(2);
	deqIntA.push_back(3);
	deqIntA.push_back(4);
	deqIntA.push_back(5);
	//deqIntA.push_back(6);

	//普通迭代器
	/*for (deque<int>::iterator it = deqIntA.begin(); it != deqIntA.end(); it++) {
		(*it)++;
		cout << *it;
		cout << " ";
	}
	cout << endl;*/

	//常量迭代器
	/*deque<int>::const_iterator cit = deqIntA.cbegin();
	for (; cit != deqIntA.cend(); cit++) {
		cout << *cit;
		cout << " ";
	}
	cout << endl;*/

	//逆转的迭代器
	for (deque<int>::reverse_iterator rit = deqIntA.rbegin(); rit != deqIntA.rend(); rit++) {
		cout << *rit;
		cout << " ";
	}
	cout << endl;
	//int i1 = deqIntA.at(0); //i1 = 1;
	//int i2 = deqIntA[1];

	//deqIntA.at(0) = 666;
	//deqIntA[1] = 888;

	//deqIntA[5] = 999;  //越界访问, 程序报错
	//int iFront = deqIntA.front(); //666
	//int iBack = deqIntA.back();	  //5

	//iFront++;
	//iBack++;

	//deqIntA.front() = iFront;
	//deqIntA.back() = iBack;
	//
	// 1 2 3 4 5 6
	//deqIntA.pop_front();
	// 2 3 4 5 6
	//deqIntA.pop_front();
	// 3 4 5 6
	//deqIntA.push_front(7);
	// 7 3 4 5 6
	//deqIntA.push_front(8);
	// 8 7 3 4 5 6

	//deqIntA.pop_back();
	// 8 7 3 4 5 
	//deqIntA.pop_back();
	// 8 7 3 4 

	//cout << "deqIntA 中的元素: " << endl;
	//for (unsigned int i = 0; i < deqIntA.size(); i++) {
	//	cout << deqIntA[i] << endl;
	//}

	system("pause");
	return 0;
}