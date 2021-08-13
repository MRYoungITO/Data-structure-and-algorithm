#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct _Heap {
	int* arr; //�洢��Ԫ�ص����� 
	int size; //��ǰ�Ѵ洢��Ԫ�ظ��� 
	int capacity; //��ǰ�洢������ 
}Heap;

bool initHeap(Heap& heap, int* orginal, int size);
bool popMax(Heap& heap, int& value);
void heapSort(Heap& heap);
static void buildHeap(Heap& heap);
static void adjustDown(Heap& heap, int index);

/*��ʼ����*/
bool initHeap(Heap& heap, int* orginal, int size) {
	//heap.arr = new int[capacity]; 
	heap.arr = orginal;
	if (!heap.arr) return false;

	heap.capacity = size;
	heap.size = size;

	//�������ԭʼ�����򹹽��� 
	if (size > 0) {
		//��ʽһ: ֱ�ӵ�������Ԫ�� 
		//���� 
		buildHeap(heap);
	}
	return true;
}

/* �����һ�����ڵ�(size/2-1 ��λ��)�����ǰ�������и��ڵ㣨ֱ������ �㣩,
ȷ��ÿһ�����ڵ㶼��һ�����ѣ�����������γ�һ������ */
void buildHeap(Heap& heap) {
	int i;
	for (i = heap.size / 2 - 1; i >= 0; i--) {
		adjustDown(heap, i);
	}
}

/*����ǰ�Ľڵ���ӽڵ����������*/
void adjustDown(Heap& heap, int index) {
	int cur = heap.arr[index];//��ǰ�������Ľڵ� 
	int parent, child;

	/*�жϷ���ڴ��ڵ�ǰ�ڵ��ӽڵ㣬��������� ����ѱ�����ƽ��ģ��� ��Ҫ������
	������ڣ��������ӽڵ���֮�������������������ӽڵ㻹���ӽ� �㣬��Ҫ����
	����ͬ���Ĳ��������ӽڵ���е��� */
	for (parent = index; (parent * 2 + 1) < heap.size; parent = child) {
		child = parent * 2 + 1;

		//ȡ�����ӽڵ��е����Ľڵ� 
		if (((child + 1) < heap.size) && (heap.arr[child] < heap.arr[child + 1])) {
			child++;
		}

		//�ж����Ľڵ��Ƿ���ڵ�ǰ�ĸ��ڵ� 
		if (cur >= heap.arr[child]) {
			//�����ڣ�����Ҫ����������ѭ�� 
			break;
		}
		else {
			//���ڵ�ǰ�ĸ��ڵ㣬���н�����Ȼ����ӽڵ�λ�ü������µ� �� 
			heap.arr[parent] = heap.arr[child];
			heap.arr[child] = cur;
		}
	}
}

/* ʵ�ֶ����� */
void heapSort(Heap& heap) {
	if (heap.size < 1) return;

	while (heap.size > 0) {
		int tmp = heap.arr[0];
		heap.arr[0] = heap.arr[heap.size - 1];
		heap.arr[heap.size - 1] = tmp;
		heap.size--;
		adjustDown(heap, 0);// ����ִ�жѵ��� 
	}
}

/* ɾ�����Ľڵ㣬����ýڵ��ֵ*/ bool popMax(Heap& heap, int& value) {
	if (heap.size < 1) return false;
	value = heap.arr[0];
	heap.arr[0] = heap.arr[--heap.size];
	//heap.arr[0] = heap.arr[heap.size-1]; 
	//heap.size--; 
	adjustDown(heap, 0);// ����ִ�жѵ��� 
	return true;
}

int main(void) {
	Heap hp; int origVals[] = { 1, 2, 3, 87, 93, 82, 92, 86, 95 };
	int i = 0;

	if (!initHeap(hp, origVals, sizeof(origVals) / sizeof(origVals[0]))) {
		fprintf(stderr, "��ʼ����ʧ�ܣ�\n");
		exit(-1);
	}

	for (i = 0; i < hp.size; i++) {
		printf("the %dth element:%d\n", i, hp.arr[i]);
	}

	//ִ�ж����� 
	heapSort(hp);

	printf("�������Ľ����\n");
	for (i = 0; i < sizeof(origVals) / sizeof(origVals[0]); i++) {
		printf(" %d", origVals[i]);
	}

	system("pause");
	return 0;
}