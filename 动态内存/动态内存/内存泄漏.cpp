#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

void A_live() {
	int* p = new int[1024];
	//挥霍
	p[0] = 0;
	//申请的内存必须要"还"(释放)
}

void B_live() {
	int* p = new int[1024];
	//正常的开支
	p[0] = 0;
	delete[] p;
}

int main6(void) {

	for (int i = 0; i < 100000; i++) {
		//A_live();
		B_live();
		Sleep(50);
	}

	system("pause");
	return 0;
}