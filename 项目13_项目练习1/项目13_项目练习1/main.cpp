#include <iostream>
#include <Windows.h>
#include "SpriteStone.h"
#include "Monster.h"

void testSpriteStone() {
	SpriteStone stone(100, SpriteStoneLevel::MIDDLE_LEVEL);
	cout << stone << endl;
}

void testMonster() {
	Monster monster(5, "òÔÁú");
	monster.getValue();
	cout<< monster << endl;
}

int main(void) {
	testSpriteStone();
	testMonster();

	system("pause");
	return 0;
}