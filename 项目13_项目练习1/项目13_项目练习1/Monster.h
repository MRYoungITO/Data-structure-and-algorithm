#pragma once
#include <string>
#include <iostream>

using namespace std;

class SpriteStone;

// 妖兽类
class Monster
{
public:
	Monster(int level = 1, const string& category = "未知");
	SpriteStone getValue();
	friend ostream& operator<<(ostream& os, const Monster& monster);
private:
	string category;  //妖兽的种类
	int level;  //1-9级
};

ostream& operator<<(ostream& os, const Monster& monster);