#include  <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main (void)
{
	string name;
	string pwd;

	cout << "ÇëÊäÈëÕËºÅ£º";
	cin >> name;

	cout << "ÇëÊäÈëÃÜÂë£º";
	cin >>pwd;

	if (name == "54hk" && pwd == "123456")
	{
		cout << "1.ÍøÕ¾404¹¥»÷" << endl;
		cout << "2.ÍøÕ¾´Û¸Ä¹¥»÷" << endl;
		cout << "3.ÍøÕ¾¹¥»÷¼ÇÂ¼" << endl;
		cout << "4.DNS¹¥»÷" << endl;
		cout << "5.·þÎñÆ÷ÖØÆô¹¥»÷" << endl;
	}else
	{
		cout << "ÓÃ»§»òÃÜÂë´íÎó£¡" << endl;
	}

	system("pause");
	return 0;
}