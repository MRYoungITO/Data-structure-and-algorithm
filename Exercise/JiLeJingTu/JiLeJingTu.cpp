#include <stdio.h>
#include <graphics.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include <MMSystem.h>
#pragma comment(lib, "winmm.lib")

#define COUNT 148

using namespace std;

/*
_0147_layer-1.jpg   1
_0146_layer-2.jpg   2
_0145_layer-3.jpg   3
*/

int main(void) {
	IMAGE images[COUNT];
	char fileName[128];

	cout << "Loading..." << endl;

	//Preload resources
	for (int i = 1; i<=COUNT; i++) {
		sprintf(fileName, "D:\\CPP_Project_learning\\Exercise\\JiLeJingTu\\images2\\_%04d_Í¼²ã-%d.jpg", 148-i, i);	
		loadimage(&images[i-1], fileName);
	}

	initgraph(800, 450);
	mciSendString("play Maria_JiLeJingTu.mp3 repeat", 0, 0, 0);

	while (1) {
		//Play all the pictures in turn
		for (int i=0; i<COUNT; i++) {
			putimage(0, 0, &images[i]);
			Sleep(70);  //1000 / 20 = 50
		}
	}

	system("pause");
	closegraph();
	return 0;
}