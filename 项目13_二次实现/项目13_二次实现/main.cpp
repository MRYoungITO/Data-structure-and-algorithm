#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "Database.h"
#include "Boy.h"
#include "Girl.h"

/*
* 需求: 要使用文件来保存用户信息
* 分析: 设计一个类来实现信息的保存功能
* Database    数据库
* 功能:
*		init()  //初始化, 从文件中读取数据信息, 来初始化用户数据
*		autoPair()  //自动配对
*		print()  //打印当前数据库中的所有信息
* 数据:
*		vector<Boy> boys;  //所有的单身男信息
*		vector<Girloy> Goys;  //所有的单身男信息
*/

int main(void) {
	Database data;

	data.init();

	Boy boy;
	Boy::inputBoy(boy);  // 输入boy信息
	data.addOne(boy);

	Girl girl;
	Girl::inputGirl(girl);
	data.addOne(girl);
		
	system("pause");
	return 0;
}

/*
输入用例：
25 杨过 15000
28 郭靖 8000
35 段誉 50000
0
18 小龙女 95
25 如花 79
26 秋香 90
26 李莫愁 100
0
*/