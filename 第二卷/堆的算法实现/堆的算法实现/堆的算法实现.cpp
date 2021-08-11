#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAPACITY 128

typedef struct _Heap {
	int* arr;		//存储对元素的数组
	int size;		//当前已存储的元素个数
	int capacity;	//当前存储的容量
}Heap;

bool initHeap(Heap& heap, int* original, int size);
bool insert(Heap& heap, int value);
bool popMax(Heap& heap, int& value);
static void buildHeap(Heap& heap);
static void adjustDown(Heap& heap, int index);
static void adjustUp(Heap& heap, int index);

bool initHeap(Heap& heap, int* original, int size) {
	int capacity = DEFAULT_CAPACITY > size ? DEFAULT_CAPACITY : size;	//三目运算符

	heap.arr = new int[capacity];
	if (!heap.arr) return false;

	heap.capacity = capacity;
	heap.size = 0;

	//如果存在原始数据则构建堆
	if (size > 0) {
		/*//方式一: 直接调整
		memcpy(heap.arr, original, size * sizeof(int));
		heap.size = size;
		//建堆
		buildHeap(heap);*/

		//方式二: 一次插入一个
		for (int i = 0; i < size; i++) {
			insert(heap, original[i]);
		}
	}

	return true;
}

/* 从最后一个父节点(size/2-1的位置)逐个往前调整所有父节点(知道根节点)
确保每一个父节点都是一个最大堆, 最后整体上形成一个最大堆 */
void buildHeap(Heap& heap) {
	int i;
	for (i = heap.size / 2 - 1; i >= 0; i--) {
		adjustDown(heap, i);
	}
}

/*将当前的节点和子节点调整成最大堆*/
void adjustDown(Heap& heap, int index) {
	int cur = heap.arr[index];	//当前待调整的节点 
	int parent, child;

	/*判断是否存在大于当前节点子节点，如果不存在 ，则堆本身是平衡的，
	不需要调整；如果存在，则将最大的子节点与之交换，交换后，如果这个子节点还
	有子节点，则要继续按照同样的步骤对这个子节点进行调整*/

	for (parent = index; (parent * 2 + 1) < heap.size; parent = child) {
		child = parent * 2 + 1;

		//取两个子节点中的最大的节点 
		if (((child + 1) < heap.size) && (heap.arr[child] < heap.arr[child + 1])) {
			child++;
		}

		//判断最大的节点是否大于当前的父节点 
		if (cur >= heap.arr[child]) {//不大于，则不需要调整，跳出循环 
			break;
		}
		else {
			//大于当前的父节点，进行交换，然后从子节点位置继续向下调整 
			heap.arr[parent] = heap.arr[child];
			heap.arr[child] = cur;
		}
	}
}

/*将当前的节点和父节点调整成最大堆*/
void adjustUp(Heap& heap, int index) {
	if (index < 0 || index >= heap.size) {	//大于堆的最大值直接return
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
			else {//如果已经比父亲节点值小, 直接结束循环
				break;
			}
		}
		else {//越界结束循环
			break;
		}
	}
}

/*删除最大的节点, 并获得节点的值*/
bool popMax(Heap& heap, int& value) {
	if (heap.size < 1) return false;

	value = heap.arr[0];
	heap.arr[0] = heap.arr[--heap.size];
	adjustDown(heap, 0);//向下执行堆的调整
	return true;
}

/*最大堆尾部插入节点, 同时保证最大堆的特性*/
bool insert(Heap& heap, int value) {
	if (heap.size == heap.capacity) {
		fprintf(stderr, "栈空间耗尽!\n");
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
		fprintf(stderr, "初始化堆失败!\n");
		exit(-1);
	}

	for (int i = 0; i < hp.size; i++) {
		printf("the %dth element: %d\n", i, hp.arr[i]);
	}

	//堆中插入新的元素
	insert(hp, 99);
	printf("在堆中插入新的元素 99, 插入结果:\n");
	for (int i = 0; i < hp.size; i++) {
		printf("the %dth element: %d\n", i, hp.arr[i]);
	}

	//堆中元素出列
	printf("最大元素依次出列: \n");

	int value;
	while (popMax(hp, value)) {
		printf(" %d\n", value);
	}

	system("pause");
	return 0;
}