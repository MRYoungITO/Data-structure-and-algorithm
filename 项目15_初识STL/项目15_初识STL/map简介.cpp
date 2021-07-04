#include <map>
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

int main(void) {
	multimap<int, string> mapStu;

	mapStu.insert(pair<int, string>(1, "张三"));
	mapStu.insert(pair<int, string>(2, "李四"));
	mapStu.insert(pair<int, string>(3, "王五"));

	//multimap 不支持[]操作, map 支持
	//mapStu[4] = "赵六";

	//multimap 支持相同的key 插入
	mapStu.insert(pair<int, string>(3, "小王五"));

	for (multimap<int, string>::iterator it = mapStu.begin(); it != mapStu.end(); it++) {
		cout << "key: " << it->first << " value: " << it->second << endl;
	}

	system("pause");
	return 0;
}