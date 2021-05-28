#include <Windows.h>
#include <iostream>
#include "Computer.h"


// 使用全局函数, 作为Computer友元函数
//void upgrade(Computer* computer) {
//	computer->cpu = "i9";
//}

int main(void) {
	Computer computer;
	ComputerService service;
	cout << computer.description() << endl;

	//upgrade(&computer);
	service.upgrade(&computer);
	service.clean(&computer);
	service.kill(&computer);

	cout << computer.description() << endl;

	system("pause");
	return 0;
}