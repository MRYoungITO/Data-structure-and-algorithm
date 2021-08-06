#include <stdio.h>
#include <assert.h>
#include <Windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

#define MaxSize 5  //队列的最大容量

typedef int DataType;  //循环队列中元素类型

typedef struct Queue {
	DataType queue[MaxSize];
	int front;	//循环队头指针
	int rear;	//循环队尾指针
}SeqQueue;

//队列初始化, 将循环队列初始化为空队列
void InitQueue(SeqQueue* SQ) {
	if (!SQ) return;
	SQ->front = SQ->rear = 0;	//把队头和队尾指针同时置0
}

//判断循环队列为空
int IsEmpty(SeqQueue* SQ) {

	if (!SQ) return 0;

	if (SQ->front == SQ->rear) {
		return 1;
	}
	return 0;
}

//判断循环队列是否为满
int IsFull(SeqQueue* SQ) {

	if (!SQ) return 0;

	if ((SQ->rear + 1) % MaxSize == SQ->front) {
		return 1;
	}
	return 0;
}

//入队, data插入到队列SQ中
int EnterQueue(SeqQueue* SQ, DataType data) {
	if (IsFull(SQ)) {
		cout << "无法插入元素" << data << ", 队列已满!" << endl;
		return 0;
	}

	SQ->queue[SQ->rear] = data;
	SQ->rear = (SQ->rear + 1) % MaxSize;

	return 1;
}

//出队, 将循环队列中队头的元素data出队, 后面的元素向前移动
int DeleteQueue(SeqQueue* SQ, DataType* data) {

	if (!SQ || IsEmpty(SQ)) {
		cout << "循环队列为空!" << endl;
		return 0;
	}

	if (!data) return 0;

	*data = SQ->queue[SQ->front];	//出队元素值
	SQ->front = (SQ->front + 1) % MaxSize;	//队首指针后移以为

	return 1;
}

//打印循环队列中的元素
void PrintQueue(SeqQueue* SQ) {

	if (!SQ)return;

	int i = SQ->front;
	while (i != SQ->rear) {
		cout << setw(4) << SQ->queue[i];
		i = (i + 1) % MaxSize;
	}
	cout << endl;
}

//获取循环队首元素, 不出队
int GetHead(SeqQueue* SQ, DataType* data) {

	if (!SQ || IsEmpty(SQ)) {
		cout << "队列为空!" << endl;
		return 0;
	}

	return *data = SQ->queue[SQ->front];
}

//清空队列
void ClearQueue(SeqQueue* SQ) {
	if (!SQ) return;
	SQ->front = SQ->rear = 0;
}

//获取队列中元素的个数
int getLength(SeqQueue* SQ) {

	if (!SQ) return 0;

	return (SQ->rear - SQ->front + MaxSize) % MaxSize;
}

int main(void) {

	SeqQueue* SQ = new SeqQueue;
	DataType data = -1;

	//初始化队列
	InitQueue(SQ);

	//入队
	for (int i = 0; i < 7; i++) {
		EnterQueue(SQ, i);
	}

	//打印队列中的元素
	printf("队列中的元素(总共 %d 个元素):", getLength(SQ));
	PrintQueue(SQ);
	cout << endl;

	//出队
	for (int i = 0; i < 5; i++) {
		if (DeleteQueue(SQ, &data)) {
			cout << "出队的元素是: " << data << endl;
		}
		else {
			cout << "出队失败! " << endl;
		}
	}

	//打印队列中的元素
	printf("出队五个元素后, 队列中剩下的元素个数为 %d 个: ", getLength(SQ));
	PrintQueue(SQ);
	cout << endl;

	//入队四个
	for (int i = 0; i < 4; i++) {
		EnterQueue(SQ, i + 10);
	}

	printf("\n入队五个元素后, 队列中剩下的元素个数为 %d 个: ", getLength(SQ));
	PrintQueue(SQ);

	system("pause");
	return 0;
}