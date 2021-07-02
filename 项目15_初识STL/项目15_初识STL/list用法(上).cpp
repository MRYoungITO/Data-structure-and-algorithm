#include <iostream>
#include <Windows.h>
#include <list>
#include <vector>

using namespace std;

int main(void) {

	//vector<int> vectInt;
	//list<int> lstInt(10, 666);

	////vector 的内存空间是预先分配的
	//vectInt.capacity();

	////list 不存在capacity方法, 所以他并没有提前分配空间
	//cout << "lstInt size: " << lstInt.size() << endl;

	//for (list<int>::iterator it = lstInt.begin(); it != lstInt.end(); it++) {
	//	cout << *it << " ";
	//}
	//cout << endl;

	////list头尾的添加移除操作
	//list<int> lstInt;
	//lstInt.push_back(1);
	//lstInt.push_back(2);
	//lstInt.push_back(3);
	//lstInt.push_back(4);
	//lstInt.push_back(5);

	//lstInt.pop_front();
	//lstInt.pop_front();

	////前面插入
	//lstInt.push_front(11); // 11 3 4 5
	//lstInt.push_front(12); // 12 11 3 4 5

	//lstInt.pop_back(); // 12 11 3 4
	//lstInt.pop_back(); // 12 11 3

	//list的数据存取
	list<int> lstInt;
	lstInt.push_back(1);
	lstInt.push_back(2);
	lstInt.push_back(3);
	lstInt.push_back(4);
	lstInt.push_back(5);

	int iFront = lstInt.front(); // 1
	int iBack = lstInt.back(); // 5

	lstInt.front() = 11; //第一个元素就改为11
	lstInt.back() = 19; //最后一个元素就改为19

	for (list<int>::iterator it = lstInt.begin(); it != lstInt.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}