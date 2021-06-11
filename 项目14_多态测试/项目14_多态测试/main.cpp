#include <iostream>
#include <Windows.h>
#include "Father.h"
#include "Son.h"

void party(Father** men, int n) {
	for (int i = 0; i < n; i++) {
		men[i]->play();
	}
}

int main(void) {
	Father father;
	Son son1, son2;
	Father* men[] = { &father,&son1,&son2 };

	party(men, sizeof(men) / sizeof(men[0]));

	system("pause");
	return 0;
}