#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

int main(void) {
	string name;
	int age;
	ifstream infile;
	infile.open("user.dat", ios::in | ios::binary);
	
	while (1) {
		infile >> name;
		if (infile.eof()) {
			break;
		}
		cout << name << "\t";

		char tmp;
		infile.read(&tmp, sizeof(tmp));

		infile.read((char*)&age, sizeof(age));
		cout << age << endl;
	}
	infile.close();

	system("pause");
	return 0;
}