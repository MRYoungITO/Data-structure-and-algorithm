#include "Monster.h"
#include "SpriteStone.h"

#define MONSTER_LEVEL_FACTOR 1000

Monster::Monster(int level, const string& category)
{
	this->level = level;
	this->category = category;
}

/*
1级妖兽：价值 100：   初阶灵石
2级妖兽：价值 200：   初阶灵石
3级妖兽：价值 500：   初阶灵石
4级妖兽：价值 1000     初阶灵石
5级妖兽：价值 2000     初阶灵石
6级妖兽：价值 5000     初阶灵石
7级妖兽：价值 10000   初阶灵石
8级妖兽：价值 20000   初阶灵石
9级妖兽：价值 100000 初阶灵石
*/

SpriteStone Monster::getValue() const
{
	int stoneCount[] = { 100,200,500,1000,2000,5000,10000,20000,100000 };
	int count = stoneCount[level - 1];
	return SpriteStone(count, SpriteStoneLevel::PRIMARY_LEVEL);
}

int Monster::getPower() const
{
	int ret = level * MONSTER_LEVEL_FACTOR;
	return ret;
}

ostream& operator<<(ostream& os, const Monster& monster)
{
	os << monster.level << "级" << monster.category << "妖兽";
	return os;
}

bool operator==(const Monster& one, const Monster& other)
{
	if (one.category == other.category &&
		one.level == other.level) {
		return true;
	}
	else {
		return false;
	}
}

