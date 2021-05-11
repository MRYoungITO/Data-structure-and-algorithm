#pragma once
#include "Tire.h"
#include "Engine.h"

class Engine;
class Car
{
public:
	Car(const string& carBrand, const string& carVeriosn, int carPrice,
		const string& engineBrand, float engineVer,
		const string& tireBrand = "米其林");
	~Car();

	Engine getEngine() const;
	const Tire* getTires(int i) const;
	string getBrand() const;
	string getVerison() const;
	int getPrice() const;
	int getMiles() const;
	string description() const;

private:
	Engine engine;
	Tire tires[4];
	string brand;  //品牌
	string verison;  //型号
	int price;
	int miles;  //行驶里程

};

