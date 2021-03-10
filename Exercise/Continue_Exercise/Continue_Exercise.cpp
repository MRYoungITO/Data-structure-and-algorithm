#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void happy (void) {
	cout << "Start a romantic journey..." << endl;
}

int main (void) {
	string ret;

	for(int i=0; i<5; i++){
		cout << "This is " << i+1 << "th blind dates..." << endl;
		cout << "Do you like playing games?" << endl;
		cin >> ret;

		if(ret != "yes"){
			continue;
		}

		cout << "Add a WeChat?" << endl;

		cout << "I love you, do you love me?" << endl;
		cin >> ret;
		if (ret == "yes") {
			happy();
			break;
		}
	}

/*
happy:  //label usage
	cout << "Start a romantic journey..." << endl;
	*/

	system("pause");
	return 0;
}