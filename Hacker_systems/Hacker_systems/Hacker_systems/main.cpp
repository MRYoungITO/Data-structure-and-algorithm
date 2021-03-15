#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include "hacker.h"


using namespace std;

#define WIDTH 40
#define HEIGHT 15

void init(void) {
	//mode con cols=40 lines=10
	char cmd[128];
	sprintf(cmd, "mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(cmd);
}

//  把特定功能的代码,封装成一个"函数"[功能]
//  以后, 在需要这个功能是,就直接调用这个函数.

void login(void) {
	string name;
	string pwd;
	
	while (1) {
		system("cls");

		cout << "请输入账号: ";
		cin >> name;

		cout << "请输入密码: ";
		cin >> pwd;

		if (name == "54hk" && pwd == "123456") {
			break;  //return
		} else {
			system("pause");
			cout << "用户名或密码错误!" << endl;
		}
	}
}

void printInMiddle(string msg) {
	int leftSpace = (WIDTH - msg.length()) / 2;
	for (int i=0; i<leftSpace; i++) {
		cout << " ";
	}

	cout << msg << endl;
}

void menuShow(void) {
	/*
	system("cls");
	cout << "1.网站404攻击" << std::endl;
	cout << "2.网站篡改攻击" << std::endl;
	cout << "3.查看攻击记录" << std::endl;
	cout << "4.网站攻击修复" << std::endl;
	cout << "5.退出" << endl;
	*/

	string menu[ ] = {
		"1.网站404攻击",
		"2.网站篡改攻击",
		"3.查看攻击记录",
		"4.网站攻击修复",
		"5.退出"
	};
	 
	int max = 0;
	int menuCount = sizeof(menu) / sizeof(menu[0]);
	for (int i=0; i<menuCount; i++) {
		if (menu[i].length() > max) {
			max = menu[i].length();		
		}
	}

	printInMiddle("---黑客攻击系统---");

	int leftSpace = (WIDTH - max) / 2;
	for (int i=0; i<menuCount; i++) {
		for (int i=0; i<leftSpace; i++) {
			cout << " ";
		}
		cout << menu[i] << endl;
	}
}

int menuChoice(void) {
	//输入功能编号
	int n = 0;  //用户输入的编号
	while (1) {
		cout << "请选择: ";
		cin >> n;  //输入a
		if (cin.fail()) {
			cin.clear();
			cin.sync();
			cout << "无效输入, 请重新输入." << endl;
			system("pause");
		} else {
			break;
		}
	}
	
	return n;
}

void attack404(void) {
	char id[64];  //网站的ID
	char response[MAXSIZE];  //攻击后, 从服务器返回的结果

	system("cls");
	
	//cout << "404攻击..." << endl;
	//int hk_404(char *id, char *response) ;
	printInMiddle("---网站404攻击---");
	printInMiddle("请输入准备攻击的网站ID: ");
	scanf_s("%s", id, sizeof(id));

	cout << "正在执行404攻击...";

	//发起攻击
	hk_404(id, response);
	
	string retStr = UTF8ToGBK(response);
	cout << retStr;

	system("pause");
}

//  网站篡改攻击
void siteEdit(void) {
	system("cls");
	cout << "网站篡改攻击..." << endl;
	system("pause");
}

void attackRecord(void) {
	system("cls");
	cout << "查看攻击记录..." << endl;
	system("pause");
}

void attackRepair(void) {
	system("cls");
	cout << "攻击修复..." << endl;
	system("pause");
}

int main(void) {
	init();
	login(); //实现登陆功能

	while(1){
		menuShow();  //显示菜单选项
		int n = menuChoice();  //选择菜单选项

		switch (n) {  //实现对应功能
		case 1:
			attack404();
			break;
		case 2:
			siteEdit();
			break;
		case 3:
			attackRecord(); 
			break;
		case 4:
			attackRepair();
			break;
		case 5:
			return 0;
		default:
			cout << "无效输入, 请重新输入." << endl;
			break;
		}
	}

	system("pause");
	return 0;
}