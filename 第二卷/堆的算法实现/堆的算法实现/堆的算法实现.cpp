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
static void buildHeap(Heap& heap);
static void adjustDown(Heap& heap, int index);

bool initHeap(Heap& heap, int* original, int size) {
	int capacity = DEFAULT_CAPACITY > size ? DEFAULT_CAPACITY : size;	//��Ŀ�����

	heap.arr = new int[capacity];
	if (!heap.arr) return false;

	//�������ԭʼ�����򹹽���
	if (size > 0) {
		memcpy(heap.arr, original, size * sizeof(int));
		heap.size = size;
		buildHeap(heap);
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

int main(void) {
	Heap hp;
	int origVals[] = { 1,2,3,87,93,82,92,86,95 };



	system("pause");
	return 0;
}