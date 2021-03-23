#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char input[128];
	int len;
	char tmp;

	scanf_s("%s", input, 128);
	len = strlen(input);

	//方法1
	/*
	for(int i=0; i<len/2; i++) {
		tmp = input[len-i-1];
		input[len-i-1] = input[i];
		input[i] = tmp;
	}
	printf("%s\n", input);
	*/

	//方法2
	/*
	for(int i=0; i<len; i++) {
		printf("%c", input[len-i-1]);
	}
	printf("\n");
	*/

	//方法3
	char *p = &input[len-1];
	for(int i=0; i<len; i++) {
		printf("%c", *p--);
	}
	printf("\n");
	system("pause");
	return 0;
}