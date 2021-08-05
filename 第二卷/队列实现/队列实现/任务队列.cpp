#include <stdio.h>
#include <assert.h>
#include <Windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

#define MaxSize 1000 //���е��������

typedef struct _QNode { //������ṹ
	int id;
	void (*handler)(void);
	struct _QNode* next;
}QNode;

typedef QNode* QueuePtr;

typedef struct Queue {
	int length; //���еĳ���
	QueuePtr front; //��ͷָ��
	QueuePtr rear; //��βָ��
}LinkQueue;

//�����߳�ִ�е�����ڵ�
QueuePtr thread_task_alloc() {
	QNode* task;
	task = (QNode*)calloc(1, sizeof(QNode));
	if (task == NULL) {
		return NULL;
	}
	return task;
}

//���г�ʼ���������г�ʼ��Ϊ�ն���
void InitQueue(LinkQueue* LQ) {
	if (!LQ) return;
	LQ->length = 0;
	LQ->front = LQ->rear = NULL; //�Ѷ�ͷ�Ͷ�βָ��ͬʱ��0
}

//�ж϶���Ϊ�� 8979438401111
int IsEmpty(LinkQueue* LQ) {
	if (!LQ) return 0;
	if (LQ->front == NULL)
	{
		return 1;
	}
	return 0;
}

//�ж϶����Ƿ�Ϊ��
int IsFull(LinkQueue* LQ) {
	if (!LQ) return 0;
	if (LQ->length == MaxSize)
	{
		return 1;
	}
	return 0;
}

//���, ��Ԫ�� data ���뵽����LQ ��
int EnterQueue(LinkQueue* LQ, QNode* node) {
	if (!LQ || !node) return 0;
	if (IsFull(LQ)) {
		cout << "�޷���������" << node->id << ", ��������!" << endl;
		return 0;
	}
	node->next = NULL;
	if (IsEmpty(LQ)) {//�ն���
		LQ->front = LQ->rear = node;
	}
	else {
		LQ->rear->next = node;//�ڶ�β����ڵ�qNode
		LQ->rear = node; //��βָ���²���Ľڵ�
	}
	LQ->length++;
	return 1;
}

//����,�������ж�ͷ�Ľڵ���ӣ�����ͷ�ڵ�
QNode* PopQueue(LinkQueue* LQ) {

	QNode* tmp = NULL;

	if (!LQ || IsEmpty(LQ)) {
		cout << "����Ϊ�գ�" << endl;
		return 0;
	}

	tmp = LQ->front;

	LQ->front = tmp->next;

	if (!LQ->front) LQ->rear = NULL;//�����ͷ���к󲻴�������Ԫ�أ��� rear �ڵ�ҲҪ�ÿ�
	LQ->length--;
	return tmp;
}

//��ӡ�����еĸ�Ԫ��
void PrintQueue(LinkQueue* LQ)
{
	QueuePtr tmp;

	if (!LQ) return;

	if (LQ->front == NULL) {
		cout << "����Ϊ�գ�";
		return;
	}

	tmp = LQ->front;
	while (tmp)
	{
		cout << setw(4) << tmp->id;
		tmp = tmp->next;
	}
	cout << endl;
}

//��ȡ������Ԫ�صĸ���
int getLength(LinkQueue* LQ) {
	if (!LQ) return 0;
	return LQ->length;
}

void task1() {
	printf("��������1 ...\n");
}

void task2() {
	printf("��������2 ...\n");
}

int main()
{
	LinkQueue* LQ = new LinkQueue;

	QNode* task = NULL;

	//��ʼ������
	InitQueue(LQ);

	//����1 ���
	task = thread_task_alloc();
	task->id = 1;
	task->handler = &task1;
	EnterQueue(LQ, task);

	//����2 ���
	task = thread_task_alloc();
	task->id = 2;
	task->handler = &task2;
	EnterQueue(LQ, task);

	//��ӡ��������е�Ԫ��
	printf("�����е�Ԫ��(�ܹ�%d ��)��", getLength(LQ));
	PrintQueue(LQ);
	cout << endl;

	//ִ������
	while ((task = PopQueue(LQ))) {
		task->handler();
		delete task;
	}

	//������Դ
	delete LQ;
	system("pause");
	return 0;
}