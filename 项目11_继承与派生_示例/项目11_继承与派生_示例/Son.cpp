#include <sstream>
#include <iostream>
#include "Son.h"

using namespace std;

Son::Son(const char* name, int age, string game) : Father(name, age)
{
	cout << __FUNCTION__ << endl;
	this->game = game;
}

Son::~Son()
{

}

string Son::getGame() const
{
	return game;
}

string Son::description() const
{
	stringstream ret;
	ret << "ÐÕÃû: " << getName() << " ÄêÁä: " << getAge() << " ÓÎÏ·: " << game;
	return ret.str();
}
