#include <iostream>
#include <Windows.h>
#include <time.h>
#include "webServer.h"

using namespace std;

static void checkTimeouts(TimeoutSqList& L, time_t now);

int main(void) {

	time_t now, end;
	time_t last_timeout;
	TimeoutSqList list;

	time(&now);
	end = now + 60;
	last_timeout = now;

	initSqList(list);

	for (int i = 0; i < 10; i++) {
		ConnTimeout e;
		e.fd = i;
		e.timeout = now + 5 + 2 * i;
		listAppend(list, e);
	}

	listPrint(list);

	do {
		if (last_timeout + 0.999 < now) {
			checkTimeouts(list, now);
			last_timeout = now;
		}
		Sleep(10);
		time(&now);
	} while (now < end);

	system("pause");
	return 0;
}

void checkTimeouts(TimeoutSqList& L, time_t now) {
	int fd, i;
	cout << "��鳬ʱ... ...\n";

	for (int i = 0; i < L.length; i++) {
		if (L.elems[i].timeout > now) {
			continue;
		}

		fd = L.elems[i].fd;
		printf("����[fd%d] �Ѿ���ʱ, �ر�����!\n", fd);

		listDelete(L, i);
		i--;
	}
}