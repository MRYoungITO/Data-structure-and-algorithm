#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	map<int, string> mapStu;

	mapStu.insert(pair<int, string>(2, "李四"));
	mapStu.insert(pair<int, string>(1, "张三"));
	mapStu.insert(pair<int, string>(3, "王五"));
	mapStu.insert(pair<int, string>(4, "赵六"));

	multimap<int, string> mmapTeacher; //<班级, 老师>

	mmapTeacher.insert(pair<int, string>(101, "李老师"));
	mmapTeacher.insert(pair<int, string>(101, "张老师"));
	mmapTeacher.insert(pair<int, string>(102, "王老师"));
	mmapTeacher.insert(pair<int, string>(102, "赵老师"));

	//multimap 的查找
	int count = mmapTeacher.count(101);
	multimap<int, string>::iterator mit = mmapTeacher.find(101);
	if (mit != mmapTeacher.end()) { //找到了
		//输出multimap 中的同一键的多个值上
		//方法一 通过比较key, 循环判断   推荐使用
		for (; mit != mmapTeacher.end(); mit++) {
			if (mit->first == 101) {
				cout << "mmapTeacher.find(101) = " << mit->second << endl;
			}
			else {
				break;
			}
		}
	}
	else { //没找到
		cout << "找不到键值为101的键值对!" << endl;
	}

	//方法二 通过count技术来控制
	/*for (int i = 0; i < count; i++, mit++) {
		cout << "mmapTeacher.find(101) = " << mit->second << endl;
	}*/
	
	/*for (; mit != mmapTeacher.end(); mit++) {
		cout << "key: " << mit->first << " value: " << mit->second << endl;
	}*/

	//map 的查找
	map<int, string>::iterator it = mapStu.find(3);
	if (it != mapStu.end()) { //找到了
		cout << "mapStu.find(3)" << it->second << endl;
	}
	else { //没找到
		cout << "找不到键值为3的键值对!" << endl;
	}

	////equal_range 用法
	//pair<multimap<int, string>::iterator, multimap<int, string>::iterator> mmiit = mmapTeacher.equal_range(101);
	//
	////第一个迭代器, 对应begin()
	//if (mmiit.first != mmapTeacher.end()) {
	//	cout << "mmapTeacher.find(101).begin = " << (*mmiit.first).second << endl;
	//}
	//
	////第二个迭代器, 对应end()
	//if (mmiit.second != mmapTeacher.end()) {
	//	cout << "mmapTeacher.find(101).end = " << (*mmiit.second).second << endl; 
	//}

	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> mmiit = mmapTeacher.equal_range(101);

	if (mmiit.first != mmapTeacher.end()) {
		cout << "mmapTeacher.find(101).begin = " << (*mmiit.first).second << endl;
	}

	if (mmiit.second != mmapTeacher.end()) {
		cout << "mmapTeacher.find(101).end = " << (*mmiit.second).second << endl;
	}
	for (map<int, string, greater<int>>::iterator it = mapStu.begin(); it != mapStu.end(); it++) {
		cout << "key: " << it->first << " value: " << it->second << endl;
	}


	system("pause");
	return 0;
}