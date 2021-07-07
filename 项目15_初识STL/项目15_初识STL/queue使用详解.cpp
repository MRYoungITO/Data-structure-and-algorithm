#include <queue>
#include <deque>
#include <set>
#include <list>
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

int main(void) {
	//queue<int> queueInt;
	//queue<int, list<int>> queueList;  //list 可以作为queue的内置容器
	////queue<int, vector<int>> queueVector;  //vector 不能作为queue的内置容器
	//queueInt.push(1);
	//queueInt.push(2);
	//queueInt.push(3);
	//queueInt.push(4);
	//queueInt.push(5);
	//int iFront = queueInt.front();	//1
	//int iBack = queueInt.back();	//5
	//queueInt.front() = 66;
	//queueInt.back() = 88;
	//cout << "队首的元素是: " << queueInt.front() << endl;
	//cout << "队尾的元素是: " << queueInt.back() << endl;
	//int iSize = queueInt.size();  //iSize = 5;
	//if (!queueInt.empty()) {
	//	cout << "queueInt的元素个数: " << iSize << endl;
	//}
	//*queueInt.pop();
	//queueInt.pop();*/
	////cout << "队首的元素是: " << queueInt.front() << endl;

	//priority_queue<int> pqA;	//默认情况下是值越大, 优先级越大
	//priority_queue<int, vector<int>, greater<int>> pqA; //使用 vector值越小, 优先级越大
	priority_queue<int, deque<int>, greater<int>> pqA;	//使用 deque值越小, 优先级越大
	//priority_queue<int, list<int>, greater<int>> pqA;	//不可以使用 list, 不兼容
	

	pqA.push(1);
	pqA.push(2);
	pqA.push(3);
	pqA.push(3);
	pqA.push(3);
	pqA.push(4);
	pqA.push(5);
	pqA.push(3);

	while (!pqA.empty()) {
		cout << pqA.top() << " ";	//读取队首的元素, 但元素不出列
		pqA.pop();					//出队列
	}
	cout << endl;

	system("pause");
	return 0;
}