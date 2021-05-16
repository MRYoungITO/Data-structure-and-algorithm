#include "WirelessTel.h"
//#include <iostream>


void WirelessTel::setNumber(const char* number)
{
	this->number = number;
	//this->FixedLine::number = number;
	//this->MobilePhone::number = "";
	//cout << FixedLine::number << endl;
}

string WirelessTel::getNumber() const
{
	return this->number;
}
