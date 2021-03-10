/*  Comparison of C language strings
#include <stdio.h>
#include <string.h>
#include <Windows.h>

int main (void)
{
	char addr[32];

	printf("Hey girl, where are you from?\n");
	scanf("%s", addr);

	if (strcmp(addr, "California") == 0)
	{
		printf("Oh! we're townspeople£¡\n");
	}else
	{
		printf("Oh, my classmate and you are a fellow townsman£¡\n");
	}

	system("pause");
	return 0;
}
*/


#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main (void)
{
	int weight;
	cout << "Hey girl, how heavy are you?" << endl;
	cin >> weight;

	if (weight >= 120)
	{
		cout << "Oh, It's awesome!" << endl;
	}else
	{
		cout << "Oh, you have a good figure!" << endl;
	}
	system("pause");
	return 0;

}