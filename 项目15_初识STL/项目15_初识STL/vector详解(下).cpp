#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

void demo1() {
	//vector 带参构造函数
	//vector<int> v2(10);  //构造时就分配空间, 同时插入10个元素,元素大小为0
	vector<int> v2(10, 666);
	//vector<int> v3(v2);
	//vector<int> v3(v2.begin() + 3, v2.end());
	int test[] = { 1,2,3,4,5 };
	vector<int> v3(test, test + 5);

	cout << "v2 的元素个数: " << v2.size() << endl;
	cout << "v2 容器的大小: " << v2.capacity() << endl;

	//vector 的删除
	//1. 把整个vector 都干掉
	/*v2.clear();
	cout << "调用 v2.clear() 后" << endl;
	cout << "v2 的元素个数: " << v2.size() << endl;
	cout << "v2 容器的大小: " << v2.capacity() << endl;*/

	//2.干掉单个元素
	//v2[1] = 888;
	//v2.erase(v2.begin() + 1);

	//3.干掉多个元素
	v2.erase(v2.begin(), v2.begin() + 3);

	cout << "v2 的元素个数: " << v2.size() << endl;
	cout << "v2 容器的大小: " << v2.capacity() << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << endl;
	}

	//v2.push_back(888);  //int &&_val - 右值引用 C++11的新特性
	//cout << "v2 的元素个数: " << v2.size() << endl;
	//cout << "v2 容器的大小: " << v2.capacity() << endl;

	//重新调整vector 的大小
	//v2.resize(2, 999);  //第一种方式: 重新定义大小
	//v2.resize(13, 888);  //第二种方式: 重新定义大小,扩大时指定新增的值
	//v2.resize(13);  //第三种方式: 重新定义大小,扩大时不指定新增的值.新增加的默认值是0

	//cout << "v2 的元素个数: " << v2.size() << endl;
	//cout << "v2 容器的大小: " << v2.capacity() << endl;
	//cout << "容器中的值: " << endl;
	//for (int i = 0; i < v2.size(); i++) {
	//	cout << v2[i] << endl;
	//}
	//cout << "---end---" << endl;

	//vector<int> v4;
	//if (v4.empty()) {
	//	cout << "v4 为空!" << endl;
	//}

	//尾部添加和删除元素
	//v2.push_back(999);
	/*v2.pop_back();
	cout << "v2尾部删除一个元素" << endl;
	cout << "v2 的元素个数: " << v2.size() << endl;
	cout << "v2 容器的大小: " << v2.capacity() << endl;*/

	//第一 使用下标操作
	//第二 使用at
	//第三 接口返回的引用
	//第一种和第二种方式必须注意越界
	//cout << "v2 中的元素: " << endl;
	//v2[0] = 555;
	/*v2.front() = 555;
	v2.back() = 999;
	v2.at(2) = 777;*/

	//vector 的插入
	//插入单个元素
	//vector<int>::iterator it = v2.insert(v2.begin(), 888);
	//for (; it!=v2.end(); it++) {
	//	cout << *it << endl;
	//}
	//cout << "-----------------" << endl;
	//插入多个元素
	//v2.insert(v2.begin(), 3, 888);
	//v2.insert(v2.begin() + 3, v3.begin(), v3.end());

	//for (int i = 0; i < v2.size(); i++) {
	//	cout << v2.at(i) << endl;
	//}

	/*cout << "v2 第一个元素: " << v2.front() << endl;
	cout << "v2 最后一个元素: " << v2.back() << endl;*/

	//逆转的迭代器
	cout << "逆向输出 v3:" << endl;
	vector<int>::reverse_iterator it = v3.rbegin();
	for (; it != v3.rend(); it++) {
		cout << *it << endl;
	}

	/*vector<int>::const_iterator it1 = */v2.cbegin();
	vector<int>::const_iterator it = v2.begin();
}

int main(void) {
	demo1();

	system("pause");
	return 0;
}