#include <stdio.h> 
#include <assert.h> 
#include <Windows.h> 
#include <iostream> 
#include <iomanip>

using namespace std;

#define MaxSize 5 //���е�������� 

typedef int DataType; //������Ԫ������ 

typedef struct _QNode { //���ṹ 
	int priority;  //ÿ���ڵ�����ȼ�, 0������ȼ�, 9������ȼ�, ���ȼ���ͬ, ȡ��һ���ڵ�
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
int EnterQueue(LinkQueue* LQ, DataType data, int priority) {

	if (!LQ) return 0;

	if (IsFull(LQ)) {
		cout << "�޷�����Ԫ�� " << data << ", ��������!" << endl;
		return 0;
	}

	QNode* qNode = new QNode;
	qNode->data = data;
	qNode->priority = priority;
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

//���ӣ���������, �ҵ����������ȼ���ߵ�Ԫ�� data ����
int DeleteQueue(LinkQueue* LQ, DataType* data) {

	QNode** prev = NULL, * prev_node = NULL;//���浱ǰ��ѡ�ٵ�������ȼ��ڵ���һ���ڵ��ָ���ַ��
	QNode* last = NULL, * tmp = NULL;

	if (!LQ || IsEmpty(LQ)) {
		cout << "����Ϊ�գ�" << endl;
		return 0;
	}

	if (!data) return 0;
	//prev ָ���ͷ front ָ��ĵ�ַ 
	prev = &(LQ->front);
	printf("��һ���ڵ�����ȼ�: %d\n", (*prev)->priority);
	last = LQ->front;
	tmp = last->next;
	while (tmp) {
		if (tmp->priority > (*prev)->priority) {
			printf("ץ�����������ȼ��Ľڵ�[priority: %d]\n", tmp->priority);
			prev = &(last->next);
			prev_node = last;
		}

		last = tmp;
		tmp = tmp->next;
	}
	*data = (*prev)->data;
	tmp = *prev; 
	*prev = (*prev)->next;
	delete tmp; 

	LQ->length--;

	//���������� 2 �������Ҫ�ֱ�Դ� 
	//1.ɾ�������׽ڵ�,���Ҷ��г���Ϊ�� 
	if (LQ->length == 0) {
		LQ->rear = NULL;
	}

	//2.ɾ������β���ڵ� 
	if (prev_node && prev_node->next == NULL) {
		LQ->rear = prev_node;
	}

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
		cout << setw(4) << tmp->data << "[" << tmp->priority << "]";
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
	for (int i = 0; i < 5; i++) {
		EnterQueue(LQ, i + 10, i);
	}

	//��ӡ�����е�Ԫ��
	printf("�����е�Ԫ��(�ܹ�%d ��)��", getLength(LQ));
	PrintQueue(LQ);
	cout << endl;

	//���� 
	for (int i = 0; i < 5; i++) {
		if (DeleteQueue(LQ, &data)) {
			cout << "���ӵ�Ԫ���ǣ�" << data << endl;
		}
		else {
			cout << "����ʧ�ܣ�" << endl;
		}
	}

	//��ӡ�����е�Ԫ�� 
	printf("����5��Ԫ�غ󣬶�����ʣ�µ�Ԫ��[%d]��\n", getLength(LQ));
	PrintQueue(LQ);
	cout << endl;

	ClearQueue(LQ);
	cout << "��ն���!\n";
	PrintQueue(LQ);

	//������Դ 
	delete LQ;

	system("pause");
	return 0;
}