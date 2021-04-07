#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <Windows.h>

using namespace std;

const double THRESHOLD = 1.5;	//THRESHOLD--->阀值
//(短时间窗口数据的平方相加再求平均值 / 长时间窗口数据的平方相加再求平均值 = 阙值)  与阀值比较

//计算短/长时间窗口能量数据的采样值
double power_w(double* arr, int length, int n);

int main9(void) {
	string filename;
	ifstream fin;		//fin 类似于	cin作用, 用于文件读入;
	int num = 0, short_window = 0, long_window = 0;	//读数据的总数量, 短时间窗口, 长时间窗口分别初始化为0;
	double time_incr = 0, * sensor = NULL, short_power = 0, long_power = 0;	//time_incr是时间增长的间隔, 类似每读一个数据的时间间隔;
	//分配一个double类型*sensor(传感器)指针,用于存储传感器的数据;	//短时间窗口的能量值, 长时间窗口的能量值
	double ratio = 0;		//定义比率, 比率 = 短时间窗口能量值 / 长时间窗口能量值

	cout << "Enter name of input file: " << endl;
	cin >> filename;

	fin .open(filename.c_str());
	if (fin.fail()) {
		cerr << "error opening input file!" << endl;
		exit(-1);
	}
	else {
		fin >> num >> time_incr;
		cout << "num: " << num << " time_incr: " << time_incr << endl;

		if (num >= 0) {
			sensor = new double[num];

			for (int i = 0; i < num; i++) {
				fin >> sensor[i];
				//cout << *(sensor+i) << endl;  测试是否正常读入数据
			}

			cout << "Enter number of points for short-window: " << endl;		//输入短时间能量窗口的数字
			//(短时间窗口数据的平方相加再求平均值 / 长时间窗口数据的平方相加再求平均值 = 阙值)
			cin >> short_window;

			cout << "Enter number of points for long-window: " << endl;
			cin >> long_window;

			//分析能量数据, 找出地震事件
			for (int i = long_window-1; i < num; i++) {
				short_power = power_w(sensor, i, short_window);
				long_power = power_w(sensor, i, long_window);

				ratio = short_power / long_power;

				if (ratio > THRESHOLD) {
					cout << "Possible event at " << time_incr * i << " seconds" << endl;
				}
			}
			delete[] sensor;	//动态内存分配完毕后记得释放回收, 一定要避免内存泄漏
		}

		fin.close();
	}

	system("pause");
	return 0;
}

//统计短/长时间窗口对应能量值的采样值
double power_w(double* arr, int length, int n) {
	double xsquare = 0;		//求到的平均值

	for (int i = 0; i < n; i++) {
		xsquare += pow(arr[length-i], 2);		//pow使用需要包含cmath头文件;
		//其中pow函数表示求多少次方, 参数中的2表示求2次方
	}
	return xsquare / n;
}