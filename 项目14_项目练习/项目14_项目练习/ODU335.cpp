#include <iostream>
#include <string>
#include "ODU335.h"

using namespace std;

ODU335::ODU335()
{
	cout << "调用ODU335()" << endl;
	type = ODU_TYPE::ODU_TYPE_335;
}

bool ODU335::heartBeat()
{
	cout << name() << "模拟串口协议读取数据: 获取心跳包的反馈. . .【"
		<< ODU_TYPE_335_FLAG << "】";
	string response;
	cin >> response;
	bool ret = false;

	if (response == ODU_TYPE_335_FLAG) {
		type = ODU_TYPE::ODU_TYPE_335;
		ret = true;
	}

	return ret;
}
