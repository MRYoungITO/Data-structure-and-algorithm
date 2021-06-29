#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

void demo1() {
	//vector 对象的默认构造
	//vector<int> v1;
	//vector<float> v2;

	//cout << "v1 的大小: " << v1.size() << endl;
	//cout << "v1 容器的大小: " << v1.capacity() << endl;

	//当我们使用vector 的默认构造函数时, 切记, 不能直接通过下标去访问
	//v1[0] = 1;

	//v1.push_back(1);
	//cout << "尾部插入1个元素后: " << endl;
	//cout << "v1 的元素个数: " << v1.size() << endl;
	//cout << "v1 容器的大小: " << v1.capacity() << endl;
	//v1.push_back(2);
	//v1.push_back(3);
	//v1.push_back(4);
	//v1.push_back(5);

	//cout << "尾部插入5个元素后: " << endl;
	//cout << "v1 的元素个数: " << v1.size() << endl;
	//cout << "v1 容器的大小: " << v1.capacity() << endl;

	//vector 带参构造函数
	//vector<int> v2(10);  //构造时就分配空间, 同时插入10个元素,元素大小为0
	vector<int> v2(10, 666);
	//vector<int> v3(v2);
	//vector<int> v3(v2.begin() + 3, v2.end());
	int test[] = { 1,2,3,4,5 };
	vector<int> v3(test, test + 2);

	cout << "v2 的元素个数: " << v2.size() << endl;
	cout << "v2 容器的大小: " << v2.capacity() << endl;

	//vector 的赋值
	v2[0] = 1;
	v2[1] = 2;

	//v2.assign(2, 888); //第一种玩法  改变原来vector中的元素个数和值
	//v2.assign(v3.begin(), v3.end()); //第二种玩法, 使用迭代器赋值
	int test1[] = { 1,2,3,4,5 };
	//v2.assign(test1, test1 + 3); //第三种玩法, 使用指针赋值
	v2 = v3;

	cout << "v2调用 assign 后: " << endl;
	cout << "v2 中存储的元素是: " << endl; 
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << endl;
	}

	cout << "v3 中存储的元素是: " << endl;
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i] << endl;
	}
}

int main(void) {
	demo1();

	system("pause");
	return 0;
}