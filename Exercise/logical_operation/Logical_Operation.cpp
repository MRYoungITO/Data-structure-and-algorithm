//  Examples of logic and operations
#include <iostream>
#include <Windows.h>

using namespace std;

int main (void)
{
	int money;
	int days;

	cout << "How much do you have?" << endl;
	cin >> money;

	cout << "How many holidays do you have?" << endl;
	cin >> days;
	
	if  (money > 100000 && days > 10)
	{
		cout << "I'm going to travel?" << endl;
	}else
	{
		cout << "I'll stay home!" << endl;
	}

	system("pause");
	return 0;
}



/*
//  Examples of logic or operations
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main (void)
{
	int money;
	string love;

	cout << "How much do you have?" << endl;
	cin >> money;

	cout << "Do you love me?" << endl;
	cin >> love;  //  Answer: yes or no

	if (money >1000000 || love == "yes")
	{
		cout << "Let's get married!" << endl;
	}else
	{
		cout << "You are a good man!" << endl;
	}

	system("pause");
	return 0;
}
*/


/*  Logical Thinking Exercise
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main (void)
{
	int salary;

	cout << "What's the monthly salary?" << endl;
	cin >> salary;

	if (!(salary >= 30000))  //salary < 30000
	{
		cout << "I am a rookie, the salary is less than 30,000, I want to practice hard!" << endl;
	}else
	{
		cout << "I am the old bird, I want to take the outsourcing!" << endl;
	}

	system("pause");
	return 0;
}
*/