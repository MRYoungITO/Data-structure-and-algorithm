#include <sstream>
#include <iostream>
#include "Car.h"

using namespace std;

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
	cout << __FUNCTION__ << endl;
}

Engine Car::getEngine() const
{
	return engine;
}

const Tire* Car::getTires(int i) const
{
	if (i >= 1 && i <= 4) {
		return &tires[i];
	}
	else {
		return NULL;
	}
}

string Car::getBrand() const
{
	return brand;
}

string Car::getVerison() const
{
	return verison;
}

int Car::getPrice() const
{
	return price;
}

int Car::getMiles() const
{
	return miles;
}

string Car::description() const
{
	stringstream ret;
	ret << "汽车品牌: " << brand << "-" << verison << "-$ " << price
		<< "\t\t引擎" << engine.description()
		<< "\t\t轮胎" << tires[0].description();
	return ret.str();
}
