#include <set>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main(void) {

	set<int> setInt;
	//set<int> setInt1(setInt.begin(), setInt.end());
	//set<int> setInt1(setInt);
	for (int i = 5; i > 0; i--) {
		setInt.insert(i);
	}

	set<int> setInt1(setInt);  // 1 2 3 4 5
	set<int> setInt2 = setInt; // 1 2 3 4 5

	/*for (set<int>::iterator it = setInt.begin(); it != setInt.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;*/

	setInt2.insert(666);
	setInt2.swap(setInt1);

	cout << "setInt1: " << endl;
	for (set<int>::iterator it = setInt1.begin(); it != setInt1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "setInt2: " << endl;
	for (set<int>::iterator it = setInt2.begin(); it != setInt2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;


	multiset<int> msetInt;

	for (int i = 0; i < 10; i++) {
		msetInt.insert(100 - i);
	}

	//set 不允许插入相同的元素, 而multiset 是支持插入多个相同元素的
	msetInt.insert(99);
	cout << "msetInt: " << endl;
	for (set<int>::iterator it = msetInt.begin(); it != msetInt.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}