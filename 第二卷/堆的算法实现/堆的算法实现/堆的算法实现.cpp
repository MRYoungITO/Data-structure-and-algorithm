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
static void buildHeap(Heap& heap);
static void adjustDown(Heap& heap, int index);

bool initHeap(Heap& heap, int* original, int size) {
	int capacity = DEFAULT_CAPACITY > size ? DEFAULT_CAPACITY : size;	//三目运算符

	heap.arr = new int[capacity];
	if (!heap.arr) return false;

	//如果存在原始数据则构建堆
	if (size > 0) {
		memcpy(heap.arr, original, size * sizeof(int));
		heap.size = size;
		buildHeap(heap);
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

int main(void) {
	Heap hp;
	int origVals[] = { 1,2,3,87,93,82,92,86,95 };



	system("pause");
	return 0;
}