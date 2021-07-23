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
	end = now + 60;	//60s ���˳�ѭ��
	last_timeout = now;

	initList(list);

	//1. ģ��Ƶ������ģ��ͨ���жϷ���, ���Ӷ������ӵ�˳�����
	for (int i = 0; i < 10; i++) {
		ConnTimeout e;
		e.fd = i;
		e.timeout = now + 5 + 2 * i;
		listAppend(list, e);
	}

	listPrint(list);

	do {
		if (last_timeout + 0.999 < now) {
			checkTimeouts(list, now);	//��鳬ʱ������
			last_timeout = now;
		}
		Sleep(10);
		time(&now);
	} while (now < end);

	/*time(&now);
	cout << "��ǰ��ʱ��� - timestamp:	" << now << endl;
	Sleep(2000);
	time(&now);
	cout << "�����Ժ��ʱ��� - timestamp:	" << now << endl;*/

	system("pause");
	return 0;
}

void checkTimeouts(TimeoutSqList& list, time_t now) {
	int fd, i;
	cout << "��鳬ʱfd... ...\n";

	for (i = 0; i < list.length; i++) {
		if (list.elems[i].timeout > now) {
			cout << list.elems[i].timeout << "    " << now << endl;
			continue;
		}
		
		//��ʱ, ��������
		fd = list.elems[i].fd;
		//�ر�����
		printf("����[fd%d] �Ѿ���ʱ, �ر�����!\n", fd);

		//ɾ��˳����е�Ԫ��
		listDelete(list, i);
		i--;
	}
}