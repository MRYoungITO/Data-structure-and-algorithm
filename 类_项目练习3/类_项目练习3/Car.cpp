#include "Car.h"

Car::Car(const string& carBrand, const string& carVeriosn, int carPrice, 
	const string& engineBrand, float engineVer, 
	const string& tireBrand) 
	: engine(engineBrand, engineVer),   // (类中包含其他类时) 初始化列表
	tires{tireBrand, tireBrand, tireBrand, tireBrand}  // (类中包含其他类时) 初始化列表(数组以大括号形式表示)
{
	this->brand = carBrand;
	this->verison = carVeriosn;
	this->price = carPrice;
	this->miles = 0;
}

Car::~Car()
{

}

Engine Car::getEngine() const
{
	return engine;
}

Tire* Car::getTires(int i)
{
	return &tires[i];
}
