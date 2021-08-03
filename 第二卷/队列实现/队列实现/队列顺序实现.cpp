#include <stdio.h>
#include <assert.h>
#include <Windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

#define MaxSize 5  //���е��������

typedef int DataType;  //������Ԫ������

typedef struct Queue {
	DataType queue[MaxSize];
	int front;	//��ͷָ��
	int rear;	//��βָ��
}SeqQueue;

//���г�ʼ��, �����г�ʼ��Ϊ�ն���
void InitQueue(SeqQueue* SQ) {
	if (!SQ) return;
	SQ->front = SQ->rear = 0;	//�Ѷ�ͷ�Ͷ�βָ��ͬʱ��0
}

//�ж϶���Ϊ��
int IsEmpty(SeqQueue* SQ) {

	if (!SQ) return 0;

	if (SQ->front == SQ->rear) {
		return 1;
	}
	return 0;
}

//�ж϶����Ƿ�Ϊ��
int IsFull(SeqQueue* SQ) {

	if (!SQ) return 0; 

	if (SQ->rear == MaxSize) {
		return 1; 
	}
	return 0; 
}

//���, data���뵽����SQ��
int EnterQueue(SeqQueue* SQ, DataType *data) {
	if (IsFull(SQ)) {
		cout << "�޷�����Ԫ��" << *data << ", ��������!" << endl;
		return 0;
	}

	SQ->queue[SQ->rear] = *data;
	SQ->rear++;

	return 1;
}

//����, �������ж�ͷ��Ԫ��data����, �����Ԫ����ǰ�ƶ�
int DeleteQueue(SeqQueue* SQ, DataType *data) {
	if (!SQ || IsEmpty(SQ)) {
		cout << "����Ϊ��!" << endl;
		return 0;
	}

	if (!data) return 0;

	*data = SQ->queue[SQ->front];

	for (int i = SQ->front + 1; i < SQ->rear; i++) {	//�ƶ������Ԫ��
		SQ->queue[i - 1] = SQ->queue[i];
	}

	SQ->rear--;
	return 1;
}


//��ӡ�����е�Ԫ��
void PrintQueue(SeqQueue* SQ) {

	if (!SQ)return;

	int i = SQ->front;
	while (i < SQ->rear) {
		cout << setw(4) << SQ->queue[i];
		i++;
	}
	cout << endl;
}

int main(void) {

	SeqQueue* SQ = new SeqQueue;
	DataType data = -1;

	//��ʼ������
	InitQueue(SQ);

	//���
	for (int i = 0; i < 7; i++) {
		EnterQueue(SQ, &i);
	}

	//��ӡ�����е�Ԫ��
	printf("�����е�Ԫ��:");
	PrintQueue(SQ);
	cout << endl;

	//����
	DeleteQueue(SQ, &data);
	cout << "���ӵ�Ԫ����: " << data << endl;

	//��ӡ�����е�Ԫ��
	printf("����һ��Ԫ�غ�, ������ʣ�µ�Ԫ��:");
	PrintQueue(SQ);
	cout << endl;


	system("pause");
	return 0;
}