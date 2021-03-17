#include <iostream>
#include <Windows.h>

using namespace std;

int main (void)
{
	int years;
	int days;

	cout << "请输入工作年限：" << endl;
	cin >> years;

	//工作满5年,有10天年假，否则只有1天年假
	/*  逻辑语句写法
	if (years >= 5)
	{
		days = 10;
	}else
	{
		days = 1;
	}
	*/

	days = years >=5 ? 10 : 1;

	cout << "你的年假是" << days << "天！" << endl;

	system("pause");
	return 0;
}