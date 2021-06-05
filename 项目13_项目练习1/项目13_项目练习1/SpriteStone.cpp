#include <sstream>
#include "SpriteStone.h"

SpriteStone::SpriteStone(int count, SpriteStoneLevel level)
{
	this->count = count;
	this->level = level;
}

string SpriteStone::str() const
{
	stringstream ret;
	ret << count << "¿é";
	
	switch (level) {
	case SpriteStoneLevel::PRIMARY_LEVEL:
		ret << "³õ½×ÁéÊ¯";
	case SpriteStoneLevel::MIDDLE_LEVEL:
		ret << "ÖÐ½×ÁéÊ¯";

	}
}
