#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAPCITY 128

typedef int DataType;
#define isLess(a,b) (a<b)

typedef struct _PriorityQueue {
	DataType* arr; //�洢��Ԫ�ص�����
	int size; //��ǰ�Ѵ洢��Ԫ�ظ���
	int capacity; //��ǰ�洢������
}PriorityQueue;

bool init(PriorityQueue& pq, DataType* orginal, int size);
bool push(PriorityQueue& pq, DataType value);
bool pop(PriorityQueue& pq, DataType& value);
bool isEmpty(PriorityQueue& pq);
bool isFull(PriorityQueue& pq);
void destroy(PriorityQueue& pq);


static void build(PriorityQueue& pq);
static void adjustDown(PriorityQueue& pq, int index);
static void adjustUp(PriorityQueue& pq, int index);

/*��ʼ�����ȶ���*/
bool init(PriorityQueue& pq, DataType* orginal, int size) {
	int capacity = DEFAULT_CAPCITY > size ? DEFAULT_CAPCITY : size;
	pq.arr = new DataType[capacity];
	if (!pq.arr) return false;
	pq.capacity = capacity;
	pq.size = 0;

	//�������ԭʼ�����򹹽�����
	if (size > 0) {
		//��ʽһ: ֱ�ӵ�������Ԫ��
		memcpy(pq.arr, orginal, size * sizeof(int));
		pq.size = size;
		//����
		build(pq);
	}
	return true;
}

/*�������ȼ�����*/
void destroy(PriorityQueue& pq) {
	if (pq.arr) delete[] pq.arr;
}

/*���ȶ����Ƿ�Ϊ��*/
bool isEmpty(PriorityQueue& pq) {
	if (pq.size < 1) return true;
	return false;
}

/*���ȶ����Ƿ�Ϊ��*/
bool isFull(PriorityQueue& pq) {
	if (pq.size < pq.capacity) return false;
	return true;
}

/*Ԫ�ظ���*/
int size(PriorityQueue& pq) {
	return pq.size;
}

/* �����һ�����ڵ�(size/2-1 ��λ��)�����ǰ�������и��ڵ㣨ֱ������
�㣩,
ȷ��ÿһ�����ڵ㶼��һ�����ѣ�����������γ�һ������*/
void build(PriorityQueue& pq) {
	int i;
	for (i = pq.size / 2 - 1; i >= 0; i--) {
		adjustDown(pq, i);
	}
}

/*����ǰ�Ľڵ���ӽڵ����������*/
void adjustDown(PriorityQueue& pq, int index)
{
	DataType cur = pq.arr[index];//��ǰ�������Ľڵ�

	int parent, child;
	/*�жϷ���ڴ��ڵ�ǰ�ڵ��ӽڵ㣬��������ڣ���ѱ�����ƽ��ģ�����Ҫ������
	������ڣ��������ӽڵ���֮�������������������ӽڵ㻹���ӽڵ㣬��Ҫ����
	����ͬ���Ĳ��������ӽڵ���е���
	*/
	for (parent = index; (parent * 2 + 1) < pq.size; parent = child) {
		child = parent * 2 + 1;

		//ȡ�����ӽڵ��е����Ľڵ�
		if (((child + 1) < pq.size) && isLess(pq.arr[child], pq.arr[child
			+ 1])) {
			child++;
		}

		//�ж����Ľڵ��Ƿ���ڵ�ǰ�ĸ��ڵ�
		if (isLess(pq.arr[child], cur)) {//�����ڣ�����Ҫ����������ѭ��
			break;
		}
		else {//���ڵ�ǰ�ĸ��ڵ㣬���н�����Ȼ����ӽڵ�λ�ü������µ���
			pq.arr[parent] = pq.arr[child];
			pq.arr[child] = cur;
		}
	}
}

/*����ǰ�Ľڵ�͸��ڵ����������*/
void adjustUp(PriorityQueue& pq, int index) {

	if (index < 0 || index >= pq.size) {
		//���ڶѵ����ֱֵ��return
		return;
	}
	while (index > 0) {
		DataType temp = pq.arr[index];
		int parent = (index - 1) / 2;
		if (parent >= 0) {
			//�������û�г����ִ����Ҫ�Ĳ���
			if (isLess(pq.arr[parent], temp)) {
				pq.arr[index] = pq.arr[parent];
				pq.arr[parent] = temp;
				index = parent;
			}
			else {//����Ѿ��ȸ���Сֱ�ӽ���ѭ��
				break;
			}
		}
		else {//Խ�����ѭ��
			break;
		}
	}
}

/* ɾ�����ȶ��������Ľڵ㣬����ýڵ��ֵ*/
bool pop(PriorityQueue& pq, DataType& value) {

	if (isEmpty(pq)) return false;

	value = pq.arr[0];
	pq.arr[0] = pq.arr[--pq.size];
	//heap.arr[0] = heap.arr[heap.size-1];
	//heap.size--;
	adjustDown(pq, 0);// ����ִ�жѵ���
	return true;
}

/*���ȶ����в���ڵ�*/
bool push(PriorityQueue& pq, DataType value) {

	if (isFull(pq)) {
		fprintf(stderr, "���ȶ��пռ�ľ���\n");
		return false;
	}

	int index = pq.size;
	pq.arr[pq.size++] = value;
	adjustUp(pq, index);
	return true;
}

int main(void) {

	PriorityQueue pq;
	int task[] = { 1, 2, 3, 87, 93, 82, 92, 86, 95 };
	int i = 0;

	if (!init(pq, task, sizeof(task) / sizeof(task[0]))) {
		fprintf(stderr, "��ʼ�����ȶ���ʧ�ܣ�\n");
		exit(-1);
	}
	for (i = 0; i < pq.size; i++) {
		printf("the %dth task:%d\n", i, pq.arr[i]);
	}

	//���в������ȼ�Ϊ88 ������
	push(pq, 88);

	//����Ԫ�س���
	printf("�������ȼ����У�\n");

	DataType value;
	while (pop(pq, value)) {
		printf(" %d\n", value);
	}

	destroy(pq);
	system("pause");
	return 0;
}