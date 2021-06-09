#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class SpriteStone;

// 妖兽类
class Monster
{
public:
	Monster(int level = 1, const string& category = "未知");
	SpriteStone getValue() const;
	int getPower() const;  // 获取该妖兽的战斗力
	friend ostream& operator<<(ostream& os, const Monster& monster);
	friend bool operator==(const Monster& one, const Monster& other);

private:
	string category;  //妖兽的种类
	int level;  //1-9级
};

ostream& operator<<(ostream& os, const Monster& monster);
bool operator==(const Monster& one, const Monster& other);