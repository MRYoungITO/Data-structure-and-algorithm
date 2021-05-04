#include "Cpu.h"
#include <iostream>

using namespace std;

Cpu::Cpu(const char* brand, const char* verison) {
	this->brand = brand;
	this->verison = verison;

	cout << __FUNCTION__ << endl;
}

Cpu::~Cpu() {
	cout << __FUNCTION__ << endl;
}