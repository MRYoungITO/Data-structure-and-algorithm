#include <iostream>
#include <deque>
#include <Windows.h>
using namespace std;

int main(void) {
	deque<int> deqIntA; //, deqIntB, deqIntC, deqIntD;

	deqIntA.push_back(1);
	deqIntA.push_back(2);
	deqIntA.push_back(3);
	deqIntA.push_back(4);
	deqIntA.push_back(5);
	
	int size = deqIntA.size();  // 5
	
	deqIntA.resize(7);			// 1 2 3 4 5 0 0

	//deqIntA.resize(3);		// 1 2 3

	deqIntA.resize(8, 1);		// 1 2 3 4 5 0 0 1

	deqIntA.resize(2);			// 1 2

	for (deque<int>::iterator it = deqIntA.begin(); it != deqIntA.end(); it++) {
		cout << *it;
		cout << " ";
	}
	cout << endl;

	//deqIntB.assign(deqIntA.begin() /*+ 1*/, deqIntA.end() - 1); // 1 2 3 4 5
	//deqIntC.assign(4, 888);
	//deqIntD = deqIntA;
	//deqIntC.swap(deqIntD);

	//for (deque<int>::iterator it = deqIntC.begin(); it != deqIntC.end(); it++) {
	//	cout << *it;
	//	cout << " ";
	//}
	//cout << endl;
	//for (deque<int>::iterator it = deqIntD.begin(); it != deqIntD.end(); it++) {
	//	cout << *it;
	//	cout << " ";
	//}
	//cout << endl;


	system("pause");
	return 0;
}