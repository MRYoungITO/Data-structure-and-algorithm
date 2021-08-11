#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAPACITY 128

typedef struct _Heap {
	int* arr;		//�洢��Ԫ�ص�����
	int size;		//��ǰ�Ѵ洢��Ԫ�ظ���
	int capacity;	//��ǰ�洢������
}Heap;

bool initHeap(Heap& heap, int* original, int size);
bool insert(Heap& heap, int value);
bool popMax(Heap& heap, int& value);
static void buildHeap(Heap& heap);
static void adjustDown(Heap& heap, int index);
static void adjustUp(Heap& heap, int index);

bool initHeap(Heap& heap, int* original, int size) {
	int capacity = DEFAULT_CAPACITY > size ? DEFAULT_CAPACITY : size;	//��Ŀ�����

	heap.arr = new int[capacity];
	if (!heap.arr) return false;

	heap.capacity = capacity;
	heap.size = 0;

	//�������ԭʼ�����򹹽���
	if (size > 0) {
		/*//��ʽһ: ֱ�ӵ���
		memcpy(heap.arr, original, size * sizeof(int));
		heap.size = size;
		//����
		buildHeap(heap);*/

		//��ʽ��: һ�β���һ��
		for (int i = 0; i < size; i++) {
			insert(heap, original[i]);
		}
	}

	return true;
}

/* �����һ�����ڵ�(size/2-1��λ��)�����ǰ�������и��ڵ�(֪�����ڵ�)
ȷ��ÿһ�����ڵ㶼��һ������, ����������γ�һ������ */
void buildHeap(Heap& heap) {
	int i;
	for (i = heap.size / 2 - 1; i >= 0; i--) {
		adjustDown(heap, i);
	}
}

/*����ǰ�Ľڵ���ӽڵ����������*/
void adjustDown(Heap& heap, int index) {
	int cur = heap.arr[index];	//��ǰ�������Ľڵ� 
	int parent, child;

	/*�ж��Ƿ���ڴ��ڵ�ǰ�ڵ��ӽڵ㣬��������� ����ѱ�����ƽ��ģ�
	����Ҫ������������ڣ��������ӽڵ���֮�������������������ӽڵ㻹
	���ӽڵ㣬��Ҫ��������ͬ���Ĳ��������ӽڵ���е���*/

	for (parent = index; (parent * 2 + 1) < heap.size; parent = child) {
		child = parent * 2 + 1;

		//ȡ�����ӽڵ��е����Ľڵ� 
		if (((child + 1) < heap.size) && (heap.arr[child] < heap.arr[child + 1])) {
			child++;
		}

		//�ж����Ľڵ��Ƿ���ڵ�ǰ�ĸ��ڵ� 
		if (cur >= heap.arr[child]) {//�����ڣ�����Ҫ����������ѭ�� 
			break;
		}
		else {
			//���ڵ�ǰ�ĸ��ڵ㣬���н�����Ȼ����ӽڵ�λ�ü������µ��� 
			heap.arr[parent] = heap.arr[child];
			heap.arr[child] = cur;
		}
	}
}

/*����ǰ�Ľڵ�͸��ڵ����������*/
void adjustUp(Heap& heap, int index) {
	if (index < 0 || index >= heap.size) {	//���ڶѵ����ֱֵ��return
		return;
	}

	while (index > 0) {
		int temp = heap.arr[index];
		int parent = (index - 1) / 2;

		if (parent >= 0) {
			if (temp > heap.arr[parent]) {
				heap.arr[index] = heap.arr[parent];
				heap.arr[parent] = temp;
				index = parent;
			}
			else {//����Ѿ��ȸ��׽ڵ�ֵС, ֱ�ӽ���ѭ��
				break;
			}
		}
		else {//Խ�����ѭ��
			break;
		}
	}
}

/*ɾ�����Ľڵ�, ����ýڵ��ֵ*/
bool popMax(Heap& heap, int& value) {
	if (heap.size < 1) return false;

	value = heap.arr[0];
	heap.arr[0] = heap.arr[--heap.size];
	adjustDown(heap, 0);//����ִ�жѵĵ���
	return true;
}

/*����β������ڵ�, ͬʱ��֤���ѵ�����*/
bool insert(Heap& heap, int value) {
	if (heap.size == heap.capacity) {
		fprintf(stderr, "ջ�ռ�ľ�!\n");
		return false;
	}

	int index = heap.size;
	heap.arr[heap.size++] = value;
	adjustUp(heap, index);
	return true;
}

int main(void) {
	Heap hp;
	int origVals[] = { 1,2,3,87,93,82,92,86,95 };

	if (!initHeap(hp, origVals, sizeof(origVals) / sizeof(origVals[0]))) {
		fprintf(stderr, "��ʼ����ʧ��!\n");
		exit(-1);
	}

	for (int i = 0; i < hp.size; i++) {
		printf("the %dth element: %d\n", i, hp.arr[i]);
	}

	//���в����µ�Ԫ��
	insert(hp, 99);
	printf("�ڶ��в����µ�Ԫ�� 99, ������:\n");
	for (int i = 0; i < hp.size; i++) {
		printf("the %dth element: %d\n", i, hp.arr[i]);
	}

	//����Ԫ�س���
	printf("���Ԫ�����γ���: \n");

	int value;
	while (popMax(hp, value)) {
		printf(" %d\n", value);
	}

	system("pause");
	return 0;
}