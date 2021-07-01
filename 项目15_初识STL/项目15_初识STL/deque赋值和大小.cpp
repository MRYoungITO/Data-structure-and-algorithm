#include <iostream>
#include <deque>
#include <Windows.h>
using namespace std;

int main(void) {
	deque<int> deqIntA, deqIntB, deqIntC, deqIntD;

	deqIntA.push_back(1);
	deqIntA.push_back(2);
	deqIntA.push_back(3);
	deqIntA.push_back(4);
	deqIntA.push_back(5);
	
	deqIntB.assign(deqIntA.begin() /*+ 1*/, deqIntA.end() - 1); // 1 2 3 4 5

	for (deque<int>::iterator it = deqIntB.begin(); it != deqIntB.end(); it++) {
		cout << *it;
		cout << " ";
	}
	cout << endl;


	system("pause");
	return 0;
}