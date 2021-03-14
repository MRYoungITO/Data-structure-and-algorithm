#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	int n = 0;
	long long a = 1;
	long long b = 1;
	long long value = 0;

	cout << "请输入斐波那契数列的个数：";
	cin >> n;

	if (!(n<3)) {
		cout << "1 1 ";
	} else if (n <= 0) {
		cout << "请输入大于0的正数。" << endl;
		system("pasue");
		return 1;
	} else if (n == 1) {
		cout << "1" << endl;
		system("pause");
		return 0;
	} else if (n == 2) {
		cout << "1 1" << endl;
		system("pause");
		return 0;
	}

	for (int i=3; i<=n; i++) {
		value = a + b;
		//a 和 b 前进一位
		a = b;
		b = value;
		cout << value << " ";
	}

	system("pause");
	return 0;
}