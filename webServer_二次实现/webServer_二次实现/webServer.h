#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include <time.h>

#define MAX_SIZE 1000

typedef struct {
	int fd;
	time_t timeout;
}ConnTimeout;

typedef struct {
	ConnTimeout* elems;
	int length;
	int size;
}TimeoutSqList;

bool initSqList(TimeoutSqList& L);
bool listAppend(TimeoutSqList& L, ConnTimeout e);
bool listDelete(TimeoutSqList& L, int i);
void destroyList(TimeoutSqList& L);
void listPrint(TimeoutSqList& L);

#endif // !_WEBSERVER_

