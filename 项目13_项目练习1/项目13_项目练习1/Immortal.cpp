#include "Immortal.h"
#include "SpriteStone.h"
#include "Monster.h"

#define IMMORTAL_LEVEL_FACTOR 1000
#define SPRITE_FACTOR 0.1
#define MONSTER_FACTOR 0.1

Immortal::Immortal(const char* name, const char* menPai, ImmortalLevel level)
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
	if (!alive) {
		return false;
	}
	SpriteStone stone;
	for (int i = 0; i < monsters.size(); i++) {
		// 不能使用+=, 因为只重载了+
		stone = stone + monsters[i].getValue();
	}
	stones.push_back(stone);
	monsters.erase(monsters.begin(), monsters.end());

	return true;
}

bool Immortal::trade(const Monster& monster)
{
	if (!alive) {
		return false;
	}

	// 判断是否有这个指定的妖兽
	if (!hadMonster(monster)) {
		cout << name << "没有" << monster << endl;
		return false;
	}

	SpriteStone stone = monster.getValue();
	stones.push_back(stone);
	removeMonster(monster);
}

bool Immortal::trade(Immortal& other, const Monster& monster)
{
	return false;
}

bool Immortal::trade(const Monster& monsterSource, Immortal& other, const Monster& monsterDest)
{
	return false;
}

bool Immortal::trade(const Monster& monster, Immortal& other)
{
	return false;
}

int Immortal::getPower() const
{
	// 计算修仙者级别的战斗力
	int ret = ((int)level + 1) * IMMORTAL_LEVEL_FACTOR;

	// 计算灵石助攻战斗力
	SpriteStone stone;
	for (int i = 0; i < stones.size(); i++) {
		stone = stone + stones[i];
	}
	ret += stone.getCount() * SPRITE_FACTOR;

	// 计算所有妖兽的助攻战斗力
	for (int i = 0; i < monsters.size(); i++) {
		ret += monsters[i].getPower() * MONSTER_FACTOR;
	}

	return ret;
}

void Immortal::fight(const Monster& monster)
{
	int selfPower = getPower();
	int monsterPower = monster.getPower();
	if (selfPower > monsterPower) {
		monsters.push_back(monster);
	}
	else if (selfPower < monsterPower) {
		dead();
	}
}

void Immortal::dead()
{
	this->alive = false;
	stones.erase(stones.begin(), stones.end());
	monsters.erase(monsters.begin(), monsters.end());
}

bool Immortal::hadMonster(const Monster& monster)
{
	for (int i = 0; i < monsters.size(); i++) {
		if (monster == monsters[i]) {
			return true;
		}
	}
	return false;
}

bool Immortal::removeMonster(const Monster& monster)
{
	// 顶一个迭代器, 是一种特殊的指针, 指向Monsters中的第一个成员的位置
	vector<Monster>::iterator it = monsters.begin();
	while (it != monsters.end()) {
		if (*it == monster) {
			it = monsters.erase(it);
			return true;
		}
		else {
			it++;
		}
	}
	return false;
}

ostream& operator<<(ostream& os, const Immortal& immortal)
{
	os << "[修仙者]" << immortal.name
		<< (immortal.alive ? "[在修]" : "[已忘]")
		<< "\t门派:" << immortal.menPai
		<< "\t级别:" << immortal.level;  // 重载

	SpriteStone stone;
	for (int i = 0; i < immortal.stones.size(); i++) {
		stone = stone + immortal.stones[i];
	}
	os << "\t灵石: 折合" << stone;
	os << "\t妖兽:";
	if (immortal.monsters.size() == 0) {
		os << "无";
	}
	else {
		for (int i = 0; i < immortal.monsters.size(); i++) {
			os << immortal.monsters[i] << " ";
		}
	}
	return os;
}

// 级别（练气期，筑基期,  结丹期，元婴期， 化神期，炼虚期，合体期，大成期，渡劫期）
ostream& operator<<(ostream& os, const ImmortalLevel& level)
{
	switch (level) {
	case ImmortalLevel::LIAN_QI:
		os << "练气期";
		break;
	case ImmortalLevel::ZHU_JI:
		os << "筑基期";
		break;
	case ImmortalLevel::JIE_DAN:
		os << "结丹期";
		break;
	case ImmortalLevel::YUAN_YING:
		os << "元婴期";
		break;
	case ImmortalLevel::HUA_SHEN:
		os << "化神期";
		break;
	case ImmortalLevel::LIAN_XU:
		os << "炼虚期";
		break;
	case ImmortalLevel::HE_TI:
		os << "合体期";
		break;
	case ImmortalLevel::DA_CHENG:
		os << "大成期";
		break;
	case ImmortalLevel::DU_JIE:
		os << "渡劫期";
		break;
	}

	return os;
}
