#include <iostream>
#include <Windows.h>
#include "Cow.h"
#include "Goat.h"
#include "Pork.h"
#include "Boy.h"
using namespace std;

ostream& operator<<(ostream& os, const Boy& boy) {
	os << "ID:" << boy.id << "\t姓名:" << boy.name << "\t年龄:" << boy.age
	<< "\t薪资:" << boy.salary << "\t黑马系数:" << boy.darkHouse;
	return os;
}

istream& operator>>(istream& is, Boy& boy) {
	string name2;
	is >> name2 >> boy.age >> boy.salary >> boy.darkHouse;
	boy.name = (char*)malloc((name2.length() + 1) * sizeof(char));
	strcpy_s(boy.name, name2.length() + 1, name2.c_str());
	return is;
}

int main(void) {
	Boy boy1("Rock", 38, 58000, 5);
	Boy boy2("Jack", 25, 50000, 10);

	// cout << boy1;
	//boy1 << cout << endl;  //boy1.operator<<(cout);
	cout << boy1 << endl;
	cout << boy1 << endl << boy2 << endl;
	cin >> boy1;
	cout << boy1 << endl;

	cout << "age:" << boy1[AGE_KEY] << endl;
	cout << "salary:" << boy1[SALARY_KEY] << endl;
	cout << "darkHorse:" << boy1[DARK_HORSE_KEY] << endl;
	cout << "power:" << boy1[POWER_KEY] << endl<<endl;

	cout << "age:" << boy1[AGE] << endl;
	cout << "salary:" << boy1[SALARY] << endl;
	cout << "darkHorse:" << boy1[DARK_HORSE] << endl;
	cout << "power:" << boy1[POWER] << endl;
	/*
	if (boy1 > boy2) {  //boy1.operator>(boy2)
		cout << "选择boy1" << endl;
	}
	else if (boy1 == boy2) {
		cout << "难以选择, 差不多" << endl;
	}
	else {  //boy1 < boy2
		cout << "选择boy2" << endl;
	}*/

	system("pause");
	return 0;
}

/*
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
}*/

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