#include <stdio.h>
#include <assert.h>
#include <Windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

#define MaxSize 5  //���е��������

typedef int DataType;  //ѭ��������Ԫ������

typedef struct Queue {
	DataType queue[MaxSize];
	int front;	//ѭ����ͷָ��
	int rear;	//ѭ����βָ��
}SeqQueue;

//���г�ʼ��, ��ѭ�����г�ʼ��Ϊ�ն���
void InitQueue(SeqQueue* SQ) {
	if (!SQ) return;
	SQ->front = SQ->rear = 0;	//�Ѷ�ͷ�Ͷ�βָ��ͬʱ��0
}

//�ж�ѭ������Ϊ��
int IsEmpty(SeqQueue* SQ) {

	if (!SQ) return 0;

	if (SQ->front == SQ->rear) {
		return 1;
	}
	return 0;
}

//�ж�ѭ�������Ƿ�Ϊ��
int IsFull(SeqQueue* SQ) {

	if (!SQ) return 0;

	if ((SQ->rear + 1) % MaxSize == SQ->front) {
		return 1;
	}
	return 0;
}

//���, data���뵽����SQ��
int EnterQueue(SeqQueue* SQ, DataType data) {
	if (IsFull(SQ)) {
		cout << "�޷�����Ԫ��" << data << ", ��������!" << endl;
		return 0;
	}

	SQ->queue[SQ->rear] = data;
	SQ->rear = (SQ->rear + 1) % MaxSize;

	return 1;
}

//����, ��ѭ�������ж�ͷ��Ԫ��data����, �����Ԫ����ǰ�ƶ�
int DeleteQueue(SeqQueue* SQ, DataType* data) {

	if (!SQ || IsEmpty(SQ)) {
		cout << "ѭ������Ϊ��!" << endl;
		return 0;
	}

	if (!data) return 0;

	*data = SQ->queue[SQ->front];	//����Ԫ��ֵ
	SQ->front = (SQ->front + 1) % MaxSize;	//����ָ�������Ϊ

	return 1;
}

//��ӡѭ�������е�Ԫ��
void PrintQueue(SeqQueue* SQ) {

	if (!SQ)return;

	int i = SQ->front;
	while (i != SQ->rear) {
		cout << setw(4) << SQ->queue[i];
		i = (i + 1) % MaxSize;
	}
	cout << endl;
}

//��ȡѭ������Ԫ��, ������
int GetHead(SeqQueue* SQ, DataType* data) {

	if (!SQ || IsEmpty(SQ)) {
		cout << "����Ϊ��!" << endl;
		return 0;
	}

	return *data = SQ->queue[SQ->front];
}

//��ն���
void ClearQueue(SeqQueue* SQ) {
	if (!SQ) return;
	SQ->front = SQ->rear = 0;
}

//��ȡ������Ԫ�صĸ���
int getLength(SeqQueue* SQ) {

	if (!SQ) return 0;

	return (SQ->rear - SQ->front + MaxSize) % MaxSize;
}

int main(void) {

	SeqQueue* SQ = new SeqQueue;
	DataType data = -1;

	//��ʼ������
	InitQueue(SQ);

	//���
	for (int i = 0; i < 7; i++) {
		EnterQueue(SQ, i);
	}

	//��ӡ�����е�Ԫ��
	printf("�����е�Ԫ��(�ܹ� %d ��Ԫ��):", getLength(SQ));
	PrintQueue(SQ);
	cout << endl;

	//����
	for (int i = 0; i < 5; i++) {
		if (DeleteQueue(SQ, &data)) {
			cout << "���ӵ�Ԫ����: " << data << endl;
		}
		else {
			cout << "����ʧ��! " << endl;
		}
	}

	//��ӡ�����е�Ԫ��
	printf("�������Ԫ�غ�, ������ʣ�µ�Ԫ�ظ���Ϊ %d ��: ", getLength(SQ));
	PrintQueue(SQ);
	cout << endl;

	//����ĸ�
	for (int i = 0; i < 4; i++) {
		EnterQueue(SQ, i + 10);
	}

	printf("\n������Ԫ�غ�, ������ʣ�µ�Ԫ�ظ���Ϊ %d ��: ", getLength(SQ));
	PrintQueue(SQ);

	system("pause");
	return 0;
}