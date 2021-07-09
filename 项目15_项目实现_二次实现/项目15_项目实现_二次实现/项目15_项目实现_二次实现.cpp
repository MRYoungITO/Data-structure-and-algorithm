#include <iostream>
#include <Windows.h>
#include <string>
#include <set>
#include "SizeFilter.hpp"

using namespace std;

int main(void) {

	SizeFilter<int, set<int>> sf;
	for (int i = 0; i < 10; i++) {
		sf.insert(i * 5);
	}
	string line(25, '-');
	cout << line << endl;

	sf.erase(0);
	sf.erase(45);
	
	cout << "最值比较结果: " << endl;
	
	pair<int, bool> max = sf.getMax();
	if (max.second) {
		cout << "Max: " << max.first << endl;
		max.second = true;
	}
	else {
		cout << "Not Found!" << endl;
		max.second = false;
	}

	pair<int, bool> min = sf.getMin();
	if (min.second) {
		cout << "Min: " << min.first << endl;
		min.second = true;
	}
	else {
		cout << "Not Found!" << endl;
		min.second = false;
	}

	system("pause");
	return 0;
}