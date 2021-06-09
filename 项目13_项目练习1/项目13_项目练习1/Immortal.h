#pragma once
#include <string>
#include <vector>
#include <iostream>

class SpriteStone;
class Monster;

using namespace std;


//级别（练气期， 筑基期, 结丹期，元婴期， 化神期，
//			炼虚期，合体期，大成期，渡劫期）

enum class ImmortalLevel {
	LIAN_QI,
	ZHU_JI,
	JIE_DAN,
	YUAN_YING,
	HUA_SHEN,
	LIAN_XU,
	HE_TI,
	DA_CHENG,
	DU_JIE
};

// 修仙者类
class Immortal
{
public:
	Immortal(const char* name, const char* menPai, ImmortalLevel level);

	// 挖矿
	void mining();

	// 到市场售卖所有的妖兽
	bool trade();
	// 到市场售卖指定的妖兽
	bool trade(const Monster& monster);
	// 用自己的灵石, 来购买其他修仙者的指定妖兽
	bool trade(Immortal& other, const Monster& monster);
	// 用自己指定的妖兽, 来和其他修仙者的指定的妖兽进行对换
	bool trade(const Monster& monsterSource, Immortal& other, const Monster& monsterDest);
	// 把自己的妖兽, 售卖给其他的修仙者, 以换取灵石
	bool trade(const Monster& monster, Immortal& other);

	int getPower() const;
	// 捕获妖兽
	void fight(const Monster& monster);

	friend ostream& operator<<(ostream& os, const Immortal& immortal);
	friend ostream& operator<<(ostream& os, const ImmortalLevel& level);

	void dead();  // 修仙者死亡后的处理
private:
	string name;
	string menPai;  // 门派
	ImmortalLevel level;  // 修仙者的级别
	vector<SpriteStone> stones; //灵石资产
	vector<Monster> monsters; // 妖兽资产
	bool alive;  // 生死状态

	bool hadMonster(const Monster& monster);  // 判断是否有指定的妖兽
	bool removeMonster(const Monster& monster); // 移除指定的妖兽
};

ostream& operator<<(ostream& os, const Immortal& immortal);
ostream& operator<<(ostream& os, const ImmortalLevel& level);
