#include <iostream>
#include <Windows.h>

using namespace std;


unsigned long long fib(int n) {
	if (n < 0) {
		cout << "²ÎÊý´íÎó" << endl;
		return 1;
	}

	if (n == 1 || n ==2) {
		return 1;
	}

	unsigned long long a1 = 1;
	unsigned long long a2 = 1;
	unsigned long long tmp;
	for (int i=3; i<=n; i++) {
		tmp = a1 + a2;
		a1 = a2;
		a2 = tmp;
	}
	return a2;
}

int main(void) {
	int n;
	cout << "ÇëÊäÈëÐòºÅ:  ";
	cin >> n;

	cout << fib(n) << endl;;

	system("pause");
	return 0;
}