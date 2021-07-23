#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include <time.h>

#define MAX_SIZE 1000

typedef struct {
	int fd;
	time_t timeout;	//适用超时时刻的时间戳表示
}ConnTimeout;

typedef struct {
	ConnTimeout* elems;	//顺序表的基地址
	int length;			//顺序表的长度
	int size;			//顺序表的空间
}TimeoutSqList;

bool initList(TimeoutSqList& L);
bool listAppend(TimeoutSqList& L, ConnTimeout e);
bool listDelete(TimeoutSqList& L, int i);
void destroyList(TimeoutSqList& L);
void listPrint(TimeoutSqList& L);

#endif // !_WEBSERVER_H_
