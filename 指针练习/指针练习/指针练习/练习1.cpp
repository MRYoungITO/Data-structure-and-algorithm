#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void reverse(unsigned char* s) {
	int len = strlen((char*)s);
	unsigned char tmp[1024];

	unsigned char* p1 = s;
	unsigned char* p2 = tmp + len;

	*p2-- = 0;
	while(*p1) {
		if (*p1 < 0x80) {	//ASCII字符一般都是小于等于127的
			*p2-- = *p1++;
		} else {
			*(p2 - 1) = *p1++;
			*p2 = *p1++;
			p2 -= 2;
		}
	}

	for (int i = 0; i < len; i++) {
		s[i] = tmp[i];
	}
}

int main(void) {
	unsigned char str[] = { "我是小萌新" };
	reverse(str);
	printf("%s\n", str);

	system("pause");
	return 0;
}