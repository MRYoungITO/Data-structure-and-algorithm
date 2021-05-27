#include <sstream>s
#include "Computer.h"

Computer::Computer()
{
	this->cpu = "i7";
}

string Computer::description()
{
	stringstream ret;
	ret << "CPU:" << cpu;
	return ret.str();
}
