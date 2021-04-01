#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

#define NUM 7

bool statistics(const char *path, int ball_16[], int len);

int main(void) {
	string filename;
	int ball_16[33] = {0};  //一定要记得初始化

	cout << "请输入文件名.\n";
	cin >> filename;

	if(statistics(filename.c_str(), ball_16, 33)) {
		cout << "-----------------------" << endl;
		for(int i=0; i<33; i++) {
			cout << "第" << i+1 << "号球出现: " << ball_16[i] << "次" << endl;
		}
	} else {//统计失败
		cout << "统计出错" << endl;
	}

	system("pause");
	return 0;
}

bool statistics(const char *path, int ball_16[], int len) {
	int result[NUM];
	ifstream file;
	int i = 0;

	if(!path) {
		cerr << "path is NULL" << endl;
		return false;
	}

	file.open(path);
	if(file.fail()) {
		cerr << "打开输入文件出错." << strerror(errno) <<endl;
		return false;
	}

	//从数据文件读数据到数组, 一行必须能读取7个
	do {
		i = 0;
		for(i=0; i<NUM; i++) {
			file>>result[i];
			if(file.eof()) {
				break;
			}
			if(file.fail()) {
				cerr << "读取文件失败, 原因: " << strerror(errno) << endl;
				break;
			}
		}
		if(i==0) break;  //记录正常结束

		//如果到最后未满7个
		if(i<NUM) {
			cerr << "仅读到" << i << "个记录, 预期读取7个" << endl;
			file.close();
			return false;
		}

		for(i=0; i<NUM; i++) {
			cout << " " << result[i];
		}
		cout << endl;

		//对读入的数据进行统计
		for(i=0; i<NUM-1; i++) {
			int index = *(result+i)-1;

			if(index>=0 && index<len) {
				*(ball_16+index)+=1;	//另一种写法: (*(ball_16+index))++;
													//*(ball_16+index)+=1;首次运算的值为1,因为主函数中初始化数组中的所有元素的值都为0
			}
		}
	} while(1);

	file.close();
	return true;
}