#include <iostream>
#include <Windows.h>
//#include "Cow.h"
//#include "Goat.h"
//#include "Pork.h"
#include "Boy.h"
#include "Man.h"
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
	Boy boy("Rock", 28, 10000, 5);
	Man man = boy;
	//int power = boy1;
	//char* name = boy1;

	//cout << boy1 << endl;
	//cout << power << endl;
	//cout << name << endl;
	//Boy boy1 = 10000;
	//Boy boy2 = "Rock";

	//cout << boy1 << endl;
	//cout << boy2 << endl;

	//Boy boy1("Rock", 38, 58000, 5);
	//Boy boy2("Jack", 25, 50000, 10);

	//// cout << boy1;
	////boy1 << cout << endl;  //boy1.operator<<(cout);
	//cout << boy1 << endl;
	//cout << boy1 << endl << boy2 << endl;
	//cin >> boy1;
	//cout << boy1 << endl;

	//cout << "age:" << boy1[AGE_KEY] << endl;
	//cout << "salary:" << boy1[SALARY_KEY] << endl;
	//cout << "darkHorse:" << boy1[DARK_HORSE_KEY] << endl;
	//cout << "power:" << boy1[POWER_KEY] << endl << endl;

	//cout << "age:" << boy1[AGE] << endl;
	//cout << "salary:" << boy1[SALARY] << endl;
	//cout << "darkHorse:" << boy1[DARK_HORSE] << endl;
	//cout << "power:" << boy1[POWER] << endl;
	///*
	//if (boy1 > boy2) {  //boy1.operator>(boy2)
	//	cout << "选择boy1" << endl;
	//}
	//else if (boy1 == boy2) {
	//	cout << "难以选择, 差不多" << endl;
	//}
	//else {  //boy1 < boy2
	//	cout << "选择boy2" << endl;
	//}*/

	system("pause");
	return 0;
}
