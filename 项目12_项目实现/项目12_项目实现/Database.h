#pragma once
#include <vector>
#include "Boy.h"
#include "Girl.h"

using namespace std;

/*
* 功能：
*	init() //初始化， 从文件中读取数据信息， 来初始化用户数据
*	autoPair() //自动配对
*	print()  // 打印该数据库中的所有用户信息
* 数据：
*	vector<Boy> boys;  //所有的单身男信息
*	vector<Girl> girls; //所有单生女信息
*/

class Database
{
public:
	Database();

	// 初始化， 从文件中读取数据信息， 来初始化用户数据
	void init();

	// 自动配对
	void autoPair();

	// 打印该数据库中的所有用户信息
	void print();
private:
	// 所有的单身男信息
	vector<Boy> boys;

	//所有单生女信息
	vector<Girl> girls;

	// 用文件中的信息来初始化boys
	void initBoysFromFile();

	// 用文件中的信息来初始化girls
	void initGirlsFromFile();

	// 保存boys的信息到文件中
	void saveBoys();

	// 保存girl s的信息到文件中
	void saveGirls();
};


