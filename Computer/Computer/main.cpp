#include <Windows.h>
#include <iostream>
#include "Computer.h"
#include <string>
#include "VoiceBox.h"

using namespace std;

void test(VoiceBox *box) {
	Computer myComputer("Inter", "i9", 1000, 8);
	myComputer.addVoiceBox(box);
}

int main(void) {
	VoiceBox box;
	test(&box);

	system("pause");
	return 0;
}