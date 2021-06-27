#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define BUFSIZE 1024


//实现文件的二进制拷贝

//第一种情况，throw 普通类型，和函数返回传值是一样的
int copyfile2(const char* dest, const char* src) {
	FILE* fp1 = NULL, * fp2 = NULL;

	//rb 只读方式打开一个二进制文件，只允许读取数据
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		//int ret = -1;
		char ret = 'a';
		throw ret;
	}

	//wb 以只写的方式打开或新建一个二进制文件，只允许写数据。
	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		throw - 2;
	}

	char buffer[BUFSIZE];
	int readlen, writelen;

	//如果读到数据，则大于0
	while ((readlen = fread(buffer, 1, BUFSIZE, fp1)) > 0) {
		writelen = fwrite(buffer, 1, readlen, fp2);
		if (readlen != writelen) {
			throw - 3;
		}
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}

int copyfile1(const char* dest, const char* src) {
	return copyfile2(dest, src);
}

void main() {
	int ret = 0;


	try {//保护段
		//printf("开始执行 copyfile1...\n");
		ret = copyfile1("D:/CPP_Project_learning/项目15_传统错误处理机制/项目15_传统错误处理机制/dest.txt", "D:/CPP_Project_learning/项目15_传统错误处理机制/项目15_传统错误处理机制/src.txt");
		//printf("执行 copyfile1 完毕\n");

	}
	catch (int error) {
		printf("出现异常啦！%d\n", error);
	}
	catch (char error) {
		printf("出现异常啦！%c\n", error);
	}

	system("pause");
}