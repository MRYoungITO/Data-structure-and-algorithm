#include <Windows.h>
#include "Son.h"

int main(void) {
	Son wsc("Íõ", "Ë¼´Ï", "´¨²Ë", "³Ô¼¦");

	wsc.playBasketball();
	wsc.dance();
	wsc.playGame();

	system("pause");
	return 0;
}