#include <Windows.h>
#include <iostream>
#include "Human.h"

int main(void) {
	Human lhc("¡Ó∫¸≥Â", MAN, 25);
	Human ryy("»Œ”Ø”Ø", WOMEN, 26);
	Human tbg("ÃÔ≤Æπ‚", MAN, 30);
	Human yls("‘¿¡È…∫", WOMEN, 20);
	Human cx("≥Â–Èµ¿≥§", MAN, 55);

	lhc.marry(yls);
	Human* who = lhc.getLover();
	cout << lhc.getName() << "µƒ≈‰≈º «: " << who->description() << endl;
	cout << who->getName() << "µƒ≈‰≈º «: " << who->getLover()->description() << endl;

	cout << lhc.getName() << "¿ÎªÈ" << endl << endl;
	lhc.divorce();

	if (lhc.getLover() == NULL) {
		cout << lhc.getName() << "µ•…Ì" << endl;
	}
	else {
		cout << lhc.getName() << "¿ÎªÈ ß∞‹" << endl;
	}

	lhc.addFriend(cx);
	lhc.addFriend(tbg);
	vector<Human*> friends = lhc.getFriends();
	for (int i = 0; i < friends.size(); i++) {
		cout << friends[i]->description() << endl;
	}

	lhc.delFriend(tbg);
	cout << lhc.getName() << "…æ≥˝∫√”—: " << tbg.getName() << endl;
	friends = lhc.getFriends();
	for (int i = 0; i < friends.size(); i++) {
		cout << friends[i]->description() << endl;
	}

	system("pause");
	return 0;
}