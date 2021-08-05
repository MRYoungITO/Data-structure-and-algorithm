#include <stdio.h> 
#include <assert.h> 
#include <Windows.h> 
#include <iostream> 
#include <iomanip>

using namespace std;

#define MaxSize 5 //���е�������� 

typedef int DataType; //������Ԫ������ 

typedef struct _QNode { //���ṹ 
	DataType data;
	struct _QNode* next;
}QNode;

typedef QNode* QueuePtr;

typedef struct Queue {
	int length; //���еĳ��� 
	QueuePtr front; //��ͷָ�� 
	QueuePtr rear; //��βָ�� 
}LinkQueue; 

//���г�ʼ���������г�ʼ��Ϊ�ն��� 
void InitQueue(LinkQueue* LQ) {

	if (!LQ) return;

	LQ->length = 0;
	LQ->front = LQ->rear = NULL; //�Ѷ�ͷ�Ͷ�βָ��ͬʱ�� 0 
}

//�ж϶���Ϊ��
int IsEmpty(LinkQueue* LQ) {

	if (!LQ) return 0;

	if (LQ->front == NULL) {
		return 1;
	}

	return 0;
} 

//�ж϶����Ƿ�Ϊ��
int IsFull(LinkQueue* LQ) {

	if (!LQ) return 0;

	if (LQ->length == MaxSize) {
		return 1;
	}

	return 0;
}

//���,��Ԫ�� data ���뵽���� LQ �� 
int EnterQueue(LinkQueue* LQ, DataType data) {

	if (!LQ) return 0;

	if (IsFull(LQ)) {
		cout << "�޷�����Ԫ�� " << data << ", ��������!" << endl;
		return 0;
	}

	QNode* qNode = new QNode;
	qNode->data = data;
	qNode->next = NULL;

	if (IsEmpty(LQ)) {//�ն��� 
		LQ->front = LQ->rear = qNode;
	}
	else {
		LQ->rear->next = qNode;//�ڶ�β����ڵ� qNode 
		LQ->rear = qNode; //��βָ���²���Ľڵ� 
	}

	LQ->length++;
	return 1;
}

//���ӣ��������ж�ͷ��Ԫ�س��ӣ����ĵ�һ��Ԫ�س�Ϊ�µĶ��� 
int DeleteQueue(LinkQueue* LQ, DataType* data) {

	QNode* tmp = NULL;

	if (!LQ || IsEmpty(LQ)) {
		cout << "����Ϊ�գ�" << endl;
		return 0;
	}

	if (!data) return 0;

	tmp = LQ->front;
	LQ->front = tmp->next;

	if (!LQ->front) LQ->rear = NULL;//�����ͷ���к󲻴�������Ԫ�أ��� rear �ڵ�ҲҪ�ÿ� 

	*data = tmp->data;
	LQ->length--;

	delete tmp;
	return 1;
}

//��ӡ�����еĸ�Ԫ�� 
void PrintQueue(LinkQueue* LQ) {

	QueuePtr tmp;

	if (!LQ) return;

	if (LQ->front == NULL) {
		cout << "����Ϊ�գ�";
		return;
	}

	tmp = LQ->front;
	while (tmp) {
		cout << setw(4) << tmp->data;
		tmp = tmp->next;
	}
	cout << endl;
}

//��ȡ����Ԫ�أ������� 
int GetHead(LinkQueue* LQ, DataType* data) {

	if (!LQ || IsEmpty(LQ)) {
		cout << "����Ϊ��!" << endl;
		return 0;
	}

	if (!data) return 0;

	*data = LQ->front->data;

	return 1;
}

//��ն��� 
void ClearQueue(LinkQueue* LQ) {

	if (!LQ) return;

	while (LQ->front) {
		QueuePtr tmp = LQ->front->next;
		delete LQ->front;
		LQ->front = tmp;
	}

	LQ->front = LQ->rear = NULL;
	LQ->length = 0;
}

//��ȡ������Ԫ�صĸ��� 
int getLength(LinkQueue* LQ) {

	if (!LQ) return 0;

	return LQ->length;
}

int main() {

	LinkQueue* LQ = new LinkQueue;
	DataType data = -1;

	//��ʼ������ 
	InitQueue(LQ);

	//��� 
	for (int i = 0; i < 7; i++) {
		EnterQueue(LQ, i);
	}

	//��ӡ�����е�Ԫ��
	printf("�����е�Ԫ��(�ܹ�%d ��)��", getLength(LQ));
	PrintQueue(LQ);
	cout << endl;

	//���� 
	//for(int i=0; i<10; i++){ 
	if (DeleteQueue(LQ, &data)) {
		cout << "���ӵ�Ԫ���ǣ�" << data << endl;
	}
	else {
		cout << "����ʧ�ܣ�" << endl;
	}
	//} 

	//��ӡ�����е�Ԫ�� 
	printf("����һ��Ԫ�غ󣬶�����ʣ�µ�Ԫ��[%d]��", getLength(LQ));
	PrintQueue(LQ);
	cout << endl;

	ClearQueue(LQ);
	cout << "��ն���!\n";
	PrintQueue(LQ);
	cout << endl;

	//������Դ 
	delete LQ;
	system("pause");
	return 0;
}