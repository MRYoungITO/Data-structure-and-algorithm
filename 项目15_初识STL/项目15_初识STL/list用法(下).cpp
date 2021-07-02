#include <iostream>
#include <Windows.h>
#include <list>
#include <vector>

using namespace std;

int main(void) {
	//list<int> lstIntA, lstIntB, lstIntC, lstIntD;
	//lstIntA.push_back(1);
	//lstIntA.push_back(3);
	//lstIntA.push_back(5);
	//lstIntA.push_back(7);
	//lstIntA.push_back(9);

	////lstIntB.assign(lstIntA.begin(), lstIntA.end());	// 1 3 5 7 9

	////使用前置++ 和--
	//lstIntB.assign(++lstIntA.begin(), --lstIntA.end()); // 3 5 7  注意: 前开后闭
	//lstIntC.assign(5, 8);								// 8 8 8 8 8
	//lstIntD = lstIntA;								// 1 3 5 7 9
	//lstIntC.swap(lstIntD);							// 互换


	//list 插入元素
	//list<int> listA;
	//list<int> listB;

	//listA.push_back(1);
	//listA.push_back(2);
	//listA.push_back(3);
	//listA.push_back(4);
	//listA.push_back(5);

	//listB.push_back(11);
	//listB.push_back(12);
	//listB.push_back(13);
	//listB.push_back(14);

	//listA.insert(listA.begin(), -1);		//{-1, 1, 2, 3, 4, 5}
	//listA.insert(++listA.begin(), 2, -2);	//{-1, -2, -2, 1, 2, 3, 4, 5}
	//listA.insert(listA.begin(), ++listB.begin(), --listB.end());	//{11, 12, 13, 14, -1, -2, -2, 1, 2, 3, 4, 5}

	//vector<int> vectA;
	//vector<int> vectB;
	//vectA.insert(vectA.begin(), vectB.begin() + 2, --vectB.end());

	//list 删除元素
	//list<int> listA;

	//listA.push_back(1);
	//listA.push_back(2);
	//listA.push_back(3);
	//listA.push_back(4);
	//listA.push_back(5);

	////erase 的用法
	//list<int>::iterator itBegin = listA.begin();
	//++itBegin;
	//list<int>::iterator itEnd = listA.begin();
	//++itEnd;
	//++itEnd;
	//++itEnd;
	//listA.erase(itBegin, itEnd);//此时容器lstInt包含按顺序的1, 4, 5三个元素。

	//listA.erase(listA.begin());
	//listA.push_back(4); // 4 5 4
	//listA.insert(listA.end(), 5, 4); //4 5 4 4 4 4 4 4

	////remove 删除元素
	////方式一 直接调用remove
	////listA.remove(4);

	////方式二 遍历然后删除
	//for (list<int>::iterator it = listA.begin(); it != listA.end();) {
	//	if (*it == 4) {
	//		it = listA.erase(it); // 相当于执行可++;
	//	}
	//	else {
	//		++it;
	//	}
	//}

	//list 反序元素
	list<int> listA;

	listA.push_back(1);
	listA.push_back(2);
	listA.push_back(3);
	listA.push_back(4);
	listA.push_back(5);

	listA.reverse();

	for (list<int>::iterator it = listA.begin(); it != listA.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}