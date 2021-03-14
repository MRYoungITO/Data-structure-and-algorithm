#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	int n;
	int ret[32];
	int i = 0;  //表示存放二进制数组的下标

	cout << "请输入一个正整数：";
	cin >> n;

	if(n<0) {
		cout << "需要输入一个正整数！" << endl;
		system("pause");
		return 1;
	}

	while (n != 0) {
		ret[i] = n % 2;
		n = n / 2;
		i++;
	}

	//输出结果

	for (i--; i>=0; i--) {
		cout <<ret[i];
	}

	cout << endl;

	system("pause");
	return 0;
}