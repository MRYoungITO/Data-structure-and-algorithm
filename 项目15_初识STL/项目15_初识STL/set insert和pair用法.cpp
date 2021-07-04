#include <set>
#include <iostream>
#include <functional>>
#include <algorithm>

using namespace std;

int main(void) {

	set<int> setInt;

	for (int i = 5; i > 0; i--) {
		pair<set<int>::iterator, bool> ret = setInt.insert(i);
		if (ret.second) {
			cout << "插入 " << i << "成功! " << endl;
		}
		else {
			cout << "插入 " << i << "失败! " << endl;
		}
		setInt.insert(5);
	}
	

	cout << "max size: " << setInt.max_size() << endl;
	//bool ret = setInt.insert(5);  返回的并不是布尔类型

	/*cout << "第一个: " << *(ret.first) << endl;
	cout << "第二个: " << ret.second << endl;*/

	system("pause");
	return 0;
}