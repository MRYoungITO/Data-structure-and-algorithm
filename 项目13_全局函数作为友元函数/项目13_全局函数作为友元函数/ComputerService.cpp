#include <iostream>
#include "ComputerService.h"
#include "Computer.h"

void ComputerService::upgrade(Computer* computer)
{
	computer->cpu = "i9";
}

void ComputerService::clean(Computer* computer)
{
	cout << "正在对电脑执行清理[CPU:"
		<< computer->cpu << "]. . ."
		<< endl;
}

void ComputerService::kill(Computer* computer)
{
	cout << "正在对电脑执行杀毒[CPU:"
		<< computer->cpu << "]. . ."
		<< endl;
}
