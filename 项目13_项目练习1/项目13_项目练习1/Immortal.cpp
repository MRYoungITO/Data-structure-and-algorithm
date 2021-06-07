#include "Immortal.h"
#include "SpriteStone.h"

Immortal::Immortal(const char* name, const char* menPai, ImmortalLevel& level)
{
	this->name = name;
	this->menPai = menPai;
	this->level = level;
	this->alive = true;
}

void Immortal::mining()
{
	stones.push_back(SpriteStone(100, SpriteStoneLevel::PRIMARY_LEVEL));
}

bool Immortal::trade()
{
	return false;
}
