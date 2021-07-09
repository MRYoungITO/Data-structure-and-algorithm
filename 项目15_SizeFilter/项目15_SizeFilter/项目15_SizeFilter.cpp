#include <Windows.h>
#include <iostream>
#include <set>

#include "SizeFilter.hpp"

using namespace std;

int main(void) {
	multiset<int> musetInt;
	set<int> setInt;
	//setInt.insert()
	//musetInt.insert()

	sizeFilter<int, multiset<int>> sf;
	//sizeFilter<int, set<int>> sf;

	for (int i = 0; i < 10; i++) {
		sf.insert(i * 5);
	}

	//只存储1个元素 5
	//sf.insert(5);

	sf.erase(0);
	sf.erase(45);
	
	cout << "获取结果:" << endl;
	//获取最大值
	pair<int, bool> pb1 = sf.getMax();
	if (pb1.second) {
		cout << "max: " << pb1.first << endl;
	}
	else {
		cout << "Not Found." << endl;
	}

	//获取最小值
	pair<int, bool> pb2 = sf.getMin();
	if (pb2.second) {
		cout << "min: " << pb2.first << endl;
	}
	else {
		cout << "Not Found." << endl;
	}

	system("pause");
	return 0;
}