#include "Computer.h"
#include <iostream>

using namespace std;

// 初始化列表
Computer::Computer(const char* cpuBrand, const char* cpuVerison, int hardDisk, int memory) : cpu(cpuBrand, cpuVerison) {	//调用对应的构造函数
	this->hardDisk = hardDisk;
	this->memory = memory;
	//this->cpu = Cpu(cpuBrand, cpuVerison);
	cout << __FUNCTION__ << endl;
}

Computer::~Computer() {
	cout << __FUNCTION__ << endl;
}

void Computer::addVoiceBox(VoiceBox* box) {
	this->box = box;
}