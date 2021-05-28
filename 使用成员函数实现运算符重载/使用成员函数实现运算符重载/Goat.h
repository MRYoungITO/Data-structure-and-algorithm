#pragma once
//#include "Cow.h"  
class Goat
{
public:
	//friend class Cow;  // ÉùÃ÷ÓÑÔªÀà
	Goat(int weight = 0);
	int getWeight() const;
private:
	int weight;
};

