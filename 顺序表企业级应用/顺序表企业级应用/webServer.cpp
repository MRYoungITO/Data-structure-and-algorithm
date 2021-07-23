#include <iostream>
#include <Windows.h>
#include <time.h>
#include "webServer.h"

using namespace std;

static void checkTimeouts(TimeoutSqList& list, time_t now);

int main(void) {

	time_t now, end;
	time_t last_timeout;
	TimeoutSqList list;

	time(&now);
	end = now + 60;	//60s 后退出循环
	last_timeout = now;

	initList(list);

	//1. 模拟频率限制模块通过判断分析, 增加恶意连接到顺序表中
	for (int i = 0; i < 10; i++) {
		ConnTimeout e;
		e.fd = i;
		e.timeout = now + 5 + 2 * i;
		listAppend(list, e);
	}

	listPrint(list);

	do {
		if (last_timeout + 0.999 < now) {
			checkTimeouts(list, now);	//检查超时的连接
			last_timeout = now;
		}
		Sleep(10);
		time(&now);
	} while (now < end);

	/*time(&now);
	cout << "当前的时间戳 - timestamp:	" << now << endl;
	Sleep(2000);
	time(&now);
	cout << "两秒以后的时间戳 - timestamp:	" << now << endl;*/

	system("pause");
	return 0;
}

void checkTimeouts(TimeoutSqList& list, time_t now) {
	int fd, i;
	cout << "检查超时fd... ...\n";

	for (i = 0; i < list.length; i++) {
		if (list.elems[i].timeout > now) {
			cout << list.elems[i].timeout << "    " << now << endl;
			continue;
		}
		
		//超时, 清理连接
		fd = list.elems[i].fd;
		//关闭连接
		printf("连接[fd%d] 已经超时, 关闭连接!\n", fd);

		//删除顺序表中的元素
		listDelete(list, i);
		i--;
	}
}