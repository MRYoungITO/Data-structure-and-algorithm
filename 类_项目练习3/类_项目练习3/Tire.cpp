#include <sstream>
#include "Tire.h"

Tire::Tire(const string& brand)
{
	this->brand = brand;
	this->pressure = 2.5;
}

Tire::~Tire()
{

}

string Tire::getBrand() const
{
	return brand;
}

float Tire::getPressure() const
{
	return pressure;
}

string Tire::description() const
{
	stringstream ret;
	ret << "Æ·ÅÆ: " << brand << " Ì¥Ñ¹: " << pressure << endl;
	return ret.str();
}
