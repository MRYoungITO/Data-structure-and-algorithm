#pragma once
#include "Father.h"

class Son : public Father 
{
public:
	Son(const char* name, int age, string game);
	~Son();

	string getGame() const;
	string description() const;
private:
	string game;
};