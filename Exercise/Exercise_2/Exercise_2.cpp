//C++ -> implementation method
//Number of multiple lines

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main (void)
{
	string words;
	int countLine = 0;
	int length = 0;
	cout << "Please enter multiple words: " << endl;
	while (1)
	{
		if (getline(cin, words) == 0)
		{
			break;
		}
		countLine++;
		length += words.length();
	}
	cout << "Number of words: " << countLine << endl;
	cout << "Total length: " << length << endl;

	system("pause");
	return 0;
}



/*
//C Language -> Implementation Method
//Number of multiple lines

#include <stdio.h>
#include <string.h>
#include <Windows.h>

int main (void)
{
	char words[2048];
	int countLine = 0;
	int length = 0;
	printf("Please enter multiple words: \n");
	while (1)
	{
		if (gets(words) == 0)
		{
			break;
		}
		countLine++;
		length += strlen(words);
	}
	printf("Number of words: %d\n", countLine);
	printf("Total length: %d\n", length);

	system("pause");
	return 0;
}
*/