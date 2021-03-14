#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main(void) {
	char line[256]; //'\0'就是0
	int i =0;				//访问字符串（字符数组）的下标
	int count = 0;   //单词计数

	cout << "请输入一句话：";
	gets_s(line, sizeof(line));

	//跳过前面的连续空格
	while(line[i] == ' ') i++;		//'\0'就是0
	while(line[i]) {		            //while(line[i] != '\0)
		//  跳过连续的多个非空格组合
		while(line[i] && line[i] != ' ') i++;
		while(line[i] == ' ') i++;	
		count++;
	}

	cout << "一共有" << count << "个单词" << endl;
	system("pause");
	return 0;
}