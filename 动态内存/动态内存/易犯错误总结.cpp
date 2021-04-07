#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void) {
	int* p = new int[18];		//申请了一块内存, 总大小18*int;
	p[0] = 0;
	char* p1 = NULL;
	/*
	//... ...
	//... ...
	delete[] p;		//只允许一次释放
	//... ...
	//... ...
	delete[] p;		//申请的内存多次释放, 程序出现异常
	*/

	//2. 忘记delete, 内存泄漏
	/*
	do {

	} while ("1==1");
	*/

	//3.释放的内存不是申请时的地址, 后果很严重, 绝对禁止的
	/*
	for (int i = 0; i < 18; i++) {
		cout << *(p++) << endl;
	}
	delete[] p;
	cout << "come here!" << endl;
	*/

	//4.释放空指针
	//... ...
	/*
	if (1==0) {	//比如文件能打开的情况
		p1 = new char[2048];
	}
	//... ...
	delete[] p1;
	*/

	//5.释放一个内存块, 但继续引用其中的内容
	/*
	delete[] p;
	//...继续码代码...
	p[0] = '\0';		//绝对禁止
	*/

	//6.越界访问
	/*
	memset(p, 0, sizeof(int) * 18);
	for (int i = 0; i < 18; i++) {
		cout << *(p++) << endl;
	}
	//误判
	for (int i = 0; i < 18; i++) {
		cout << *(p++) << endl;
	}
	cout << "come here!" << endl;
	*/

	system("pause");
	return 0;
}