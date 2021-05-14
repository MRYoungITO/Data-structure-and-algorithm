#pragma once
#include "Father.h"
#include "Mother.h"
class Son : public Father, public Mother
{
public:
	Son(const char* lastName, const char* firstName, const char* food, const char* game);
	~Son();

	void playGame();
	void dance();
private:
	string game;
};

