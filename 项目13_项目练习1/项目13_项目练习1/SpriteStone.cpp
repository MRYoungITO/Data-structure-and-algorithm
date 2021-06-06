#include "SpriteStone.h"
#include <sstream>

SpriteStone::SpriteStone(int count, SpriteStoneLevel level)
{
	this->count = count;
	this->level = level;
}

string SpriteStone::str() const
{
	stringstream ret;
	ret << count << "块";

	switch (level) {
	case SpriteStoneLevel::PRIMARY_LEVEL:
		ret << "初级灵石";
		break;
	case SpriteStoneLevel::MIDDLE_LEVEL:
		ret << "中级灵石";
		break;
	case SpriteStoneLevel::ADVANCE_LEVEL:
		ret << "高级灵石";
		break;
	default:
		ret << "未知灵石";
		break;
	}
	return ret.str();
}

ostream& operator<<(ostream& os, SpriteStone& stone)
{
	os << stone.str();
	return os;
}
