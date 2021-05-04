#pragma once

#include <string>

class Cpu
{
public:
	Cpu(const char* brand = "Inter", const char* verison = "i5");
	~Cpu();

private:
	std::string brand;		//Æ·ÅÆ
	std::string verison;	//ÐÍºÅ
};