#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int main(void) {

	stack<int> stkInt;	//默认使用deque存储元素
	//stack<int, vector<int>> stkInt;	//使用vector容器
	//stack<int, list<int>> stkInt;	//使用list容器
	//stack<int, queue<int>> stkInt;
	stkInt.push(1);
	stkInt.push(2);
	//stkInt.pop();
	stkInt.push(3);

	int &iTop = stkInt.top();
	iTop = 66;
	//cout << "iYop: " << iTop << endl;
	cout << "stkInt.top(): " << stkInt.top() << endl;

	stkInt.top() = 88;
	cout << "stkInt.top(): " << stkInt.top() << endl;

	while (!stkInt.empty()) {
		cout << stkInt.top() << " ";
		stkInt.pop();	//栈顶的元素出栈
		cout << stkInt.size() << endl;
	}
	//cout << endl;

	system("pause");
	return 0;
}