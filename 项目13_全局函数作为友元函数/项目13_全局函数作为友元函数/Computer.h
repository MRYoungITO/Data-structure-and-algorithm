#pragma once
#include <string>
#include "ComputerService.h"

using namespace std;

class Computer
{
public:
	Computer();
	string description();

	// 把外部的全局函数upgrade, 声明为这个类的友元函数
	//friend void upgrade(Computer* computer);
	friend void ComputerService::upgrade(Computer* computer);
private:
	string cpu;  // 计算机的CPU芯片
};

