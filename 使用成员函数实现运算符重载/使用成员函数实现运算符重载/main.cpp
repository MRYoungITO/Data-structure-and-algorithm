#include <iostream>
#include <Windows.h>
#include "Cow.h"
#include "Goat.h"
#include "Pork.h"
#include "Boy.h"
using namespace std;

int main(void) {
	Boy boy1("Rock", 38, 58000, 10);
	Boy boy2, boy3;
	cout << boy1.description() << endl;
	cout << boy2.description() << endl;
	cout << boy3.description() << endl;

	cout << "赋值以后" << endl;
	boy3 = boy2 = boy1;
	cout << boy1.description() << endl;
	cout << boy2.description() << endl;
	cout << boy3.description() << endl;

	system("pause");
	return 0;
}

/*
Pork operator+(const Cow& cow1, const Cow& cow2) {
	int tmp = (cow1.weight + cow2.weight) * 2;
	return Pork(tmp);
}

Pork operator+(const Cow& cow, const Goat& goat) {
	int tmp = cow.weight * 3 + goat.getWeight() * 2;
	return Pork(tmp);
}

Pork operator+(const Goat& goat, const Cow& cow) {
	int tmp = goat.getWeight() * 2 + cow.weight * 3;
	return Pork(tmp);
}

int main(void) {
	Cow c1(100);
	Cow c2(200);

	// 此时调用的是: c1.operator+(c2)
	//Pork p = c1 + c2;
	//Pork p = c1.operator+(c2);
	//Pork p = c1 + c2;
	Pork p = operator+(c1, c2);	
	cout << p.description() << endl;
	Goat g1(100);
	//p = c1 + g1;
	//p = c1.operator+(g1);
	//p = c1 + g1;
	p = operator+(c1, g1);
	cout << p.description() << endl;
	p = operator+(g1, c1);
	cout << p.description() << endl;

	system("pause");
	return 0;
}*/