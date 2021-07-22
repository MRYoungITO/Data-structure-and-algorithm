#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include <time.h>

#define MAX_SIZE 1000

typedef struct {
	int fd;
	time_t timeout;	//���ó�ʱʱ�̵�ʱ�����ʾ
}ConnTimeout;

typedef struct {
	ConnTimeout* elems;	//˳���Ļ���ַ
	int length;			//˳���ĳ���
	int size;			//˳���Ŀռ�
}TimeOutSqList;

bool initList(TimeOutSqList& L);
bool listAppend(TimeOutSqList& L, ConnTimeout e);
bool listDelete(TimeOutSqList& L, int i);
void destroyList(TimeOutSqList& L);
void listPrint(TimeOutSqList& L);

#endif // !_WEBSERVER_H_
