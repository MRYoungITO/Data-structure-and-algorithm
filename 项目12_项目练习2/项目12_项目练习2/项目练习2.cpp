#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
	ofstream stream;
	int num;
	int n = 0;
	stream.open("num.txt");
	if (!stream.is_open()) {
		cout << "文件打开失败" << endl;
		exit(1);
	}

	while (1) {
		// 输入一个整数
		cout << "请输入一个整数: ";
		cin >> num;
		if (cin.eof()) {
			break;
		}

		// 如果输入错误, 需要反复重复输入
		while (cin.fail()) {
			cin.clear();  // 清除错误标志
			//cin.sync();  //清空输入缓冲区, 在vs编译器中没有效果, gcc等编译器中可以正常使用
			// 把cin的输入缓冲区中的数据全部清除, 直到遇到回车符
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "输入错误, 请重新输入: ";
			cin >> num;
			}

		// 写入数据到文件
		stream << num << "\t";
		if (++n % 10 == 0) {
			stream << endl;
		}
	}

	stream.close();
	system("pause");
	return 0;
}