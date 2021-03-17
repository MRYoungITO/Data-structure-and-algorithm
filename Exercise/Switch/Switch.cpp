#include <iostream>
#include <Windows.h>

using namespace std;

/*
星期一：包子
星期二：馒头
星期三：稀饭
星期四：白菜
星期五：土豆
星期六：休息
星期日：休息
*/

int main (void)
{
	int num = 0;

	cout << "请输入星期（1-7）：";
	cin >> num;

	switch (num) {
	case 1:
		cout << "星期一：包子" << endl;
		break;
	case 2:
		cout << "星期二：馒头" << endl;
		break;
	case 3:
		cout << "星期三：稀饭" << endl;
		break;
	case 4:
		cout << "星期四：白菜" << endl;
		break;
	case 5:
		cout << "星期五：土豆" << endl;
		break;
	case 6:
	case 7: 
		cout << "星期六、日：休息" << endl;
		break;
	default:
		cout << "您输入的天数错误！" << endl;
	}

	/*  if 语句写法示例
	if (num == 1) {
		cout << "星期一：包子" << endl;
	} else if (num == 2) {
		cout << "星期二：馒头" << endl;
	} else if (num == 3) {
		cout << "星期三：稀饭" << endl;
	} else if (num == 4) {
		cout << "星期四：白菜" << endl;
	} else if (num == 5) {
		cout << "星期五：土豆" << endl;
	} else if ((num ==6) || (num == 7)) {
		cout << "星期六、日：休息" << endl;
	} else {
		cout << "您输入的天数错误！" << endl;
	}
	*/

	system("pause");
	return 0;
}