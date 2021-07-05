#include <map>
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

int main(void) {
	map<int, string> mapStu;

	//方式一 构造一个pair, 然后插入, 如果键存在,就会插入失败
	pair<map<int, string>::iterator, bool> ret = mapStu.insert(pair<int, string>(1, "张三"));
	if (ret.second) {
		cout << "插入成功! value: " << (*(ret.first)).second << endl;
	}
	else {
		cout << "插入失败!" << endl;
	}

	ret = mapStu.insert(pair<int, string>(1, "小张三"));
	if (ret.second) {
		cout << "插入成功! value: " << (*(ret.first)).second << endl;
	}
	else {
		cout << "插入小张三失败!" << endl;
	}

	//方式二 make_pair
	mapStu.insert(make_pair(2, "李四"));

	//方式三 使用value_type, 相当于pair<int, sting>
	mapStu.insert(map<int, string>::value_type(3, "王五"));

	//mapStu.insert(pair<int, string>(4, "赵六"));

	//方式四 直接使用[]重载， 如果键值对已经存在,则覆盖值
	mapStu[4] = "赵六";

	mapStu[5] = mapStu[6];
	mapStu[7] = mapStu[4];
	//multimap 不支持[]操作, map 支持
	//mapStu[4] = "赵六";

	//multimap 支持相同的key 插入
	//mapStu.insert(pair<int, string>(3, "小王五"));

	for (multimap<int, string>::iterator it = mapStu.begin(); it != mapStu.end(); it++) {
		cout << "key: " << it->first << " value: " << it->second << endl;
	}

	system("pause");
	return 0;
}