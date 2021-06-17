#include <iostream>
#include <Windows.h>
#include <thread>  // 线程 头文件
#include "ODU.h"
#include "ODU335.h"

using namespace std;

ODU* odu = NULL;  // odu 全局变量

void test(ODU* odu) {
	odu->setTxFre(35588);
	cout << odu->getTxFre() << endl;
	odu->heartBeat();
}

void oduMonitorHandler() {
	while (1) {
		if (!odu->heartBeat()) {
			// 切换ODU
			ODU_TYPE type = odu->getODUType();
			switch (type) {
			case ODU_TYPE::OUD_TYPE_331:
				delete odu;
				odu = new ODU335;
				break;
			case ODU_TYPE::ODU_TYPE_335:
				delete odu;
				odu = new ODU;
				break;
			default:
				odu = NULL;
				return;
			}
		}

		Sleep(3000);
	}
}

int main(void) {
	odu = new ODU;

	//  创建一个线程, 用于对ODU进行心跳检测
	thread oduMonitor(oduMonitorHandler);

	// 主线程等待线程oduMonitor的结束
	oduMonitor.join();

	system("pause");
	return 0;
}