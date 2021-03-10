//C++ -> implementation method
//Number of individual words acquired

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main (void)
{
	string words;
	int countWords = 0;
	int length = 0;
	cout << "Please enter multiple words: ";
	while (1)
	{
		if ((cin >> words) == 0)
		{
			break;
		}
		countWords++;
		length += words.length();
	}
	cout << "Number of words: " << countWords << endl;
	cout << "Total length: " << length << endl;

	system("pause");
	return 0;
}


/*
//C Language -> Implementation Method
//Number of individual words acquired

#include <stdio.h>
#include <string.h>s
#include <Windows.h>

int main (void)
{
	char words[128];
	int countWords = 0;
	int length = 0;
	printf("Please enter multiple words: \n");
	while (1)
	{
		if (scanf("%s", words) == -1)
		{
			break;
		}
		countWords++;
		length += strlen(words);
	}
	printf("Number of words: %d¸ö\n", countWords);
	printf("Total length: %d¸ö\n", length);

	system("pause");
	return 0;
}
*/