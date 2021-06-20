#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}

int main(void) {
	int x = 1;
	int y = 2;
	Max(x, y);

	float a = 2.0;
	float b = 3.0;
	Max(a, b);

	system("pause");
	return 0;
}