#include <iostream>
#include <Windows.h>
#include <string>
#include "SpriteStone.h"
#include "Monster.h"
#include "Immortal.h"

void testSpriteStone() {
	SpriteStone stone(100, SpriteStoneLevel::MIDDLE_LEVEL);
	cout << stone << endl;
}

void testMonster() {
	Monster monster(5, "蛟龙");
	monster.getValue();
	cout << monster << endl;
}

void testIImmortal() {
	Immortal rock("Rock", "奇牛", ImmortalLevel::LIAN_QI);
	cout << rock << endl;

	for (int i = 0; i < 50; i++) {
		rock.mining();
	}

	cout << rock << endl;

	Monster monster(1, "蛟龙");
	rock.fight(monster);
	cout << "捕获" << monster << "之后:" << endl;
	cout << rock << endl;

	Monster monster2(1, "蜘蛛");
	rock.fight(monster2);
	Monster monster3(1, "壁虎");
	rock.fight(monster3);
	cout << "捕获" << monster2 << "和" << monster3 << "之后:" << endl;
	cout << rock << endl;

	rock.trade(monster2);
	cout << "售卖" << monster2 << "之后" << endl;
	cout << rock << endl;

	rock.trade();
	cout << "售卖所有妖兽之后" << endl;
	cout << rock << endl;

	Immortal hanli("韩立", "黄枫谷", ImmortalLevel::JIE_DAN);
	cout << hanli << endl;

	Monster monster4(2, "蛟龙");
	hanli.fight(monster4);
	cout << hanli << endl;

	rock.trade(hanli, monster4);
	cout << "贸易之后" << endl;
	cout << rock << endl;
	cout << hanli << endl;

	Monster monster5(1, "天蚕");
	hanli.fight(monster5);
	cout << "韩立" << "捕获" << monster5 << endl;
	cout << hanli << endl;

	cout << "Rock使用" << monster4 << "和韩立交换" << monster5 << endl;
	rock.trade(monster4, hanli, monster5);
	cout << rock << endl;
	cout << hanli << endl;

	hanli.trade(monster4, rock);
	cout << "韩立卖" << monster4 << "给Rock" << endl;
	cout << rock << endl;
	cout << hanli << endl;
}

int main(void) {
	testSpriteStone();
	testMonster();
	testIImmortal();

	system("pause");
	return 0;
}