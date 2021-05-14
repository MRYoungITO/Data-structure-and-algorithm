#include <iostream>
#include "Son.h"

using namespace std;

Son::Son(const char* lastName, const char* firstName, 
	const char* food, 
	const char* game) : Father(lastName, firstName), Mother(food)
{
	this->game = game;
}

Son::~Son()
{

}

void Son::playGame()
{
	cout << "Ò»ÆðÍæ" << game << "°É..." << endl;
}

void Son::dance()
{
	Father::dance();
	Mother::dance();
	cout << "»ô»ô, ÎÒÃÇÀ´ÌøÌßÌ¤Îè°É! " << endl;
}
