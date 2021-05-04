#pragma once
#include "Cpu.h"
//#include "VoiceBox.h"

class VoiceBox;

class Computer
{
public:
	Computer(const char* cpuBrand, const char* cpuVerison, int hardDisk, int memory);
	~Computer();
	void addVoiceBox(VoiceBox* box);

private:
	Cpu cpu;			//Computer和Cpu之间,就是"组合"
	int hardDisk;		//硬盘, 单位: G
	int memory;		//内存, 单位: G
	VoiceBox* box;
};

