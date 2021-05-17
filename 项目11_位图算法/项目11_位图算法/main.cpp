#include <stdio.h>
#include <Windows.h>

void init(char* data, int len) {
	// 根据实际需求来实现
	// 这里只是为了测试算法效果, 假设:
	// 能够被3整除数的数, 都在这个集合中 [假设的需求]
	// 假设有40亿个数据: 
	unsigned int n = len * 8;  //一共有n个数据
	for (unsigned int i = 0; i < n; i++) {
		// 假设: 能够被3整除数的数, 都在这个集合中 [假设的需求]
		if (i % 3 == 0) {
			// 计算这个位置对应哪个字节
			char* p = data + i / 8;
			*p = *p | (1 << (i % 8));
		}
	}
}

//位图算法
bool check(char* data, int len, int value) {
	// 定位到指定的字节
	char* p = data + value / 8;

	// 判断这个字节中指定的位是否为1
	bool ret = *p & (1 << (value % 8));
	return ret;
}

int main(void) {
	// 分配一块足够的内存, 用来表示位图
	unsigned int n = 4000000000;
	int len = n / 8 + 1;
	char* data = (char*)malloc(len);
	memset(data, 0, len);  //清零

	//装载数据集合(只需要装载一次)
	init(data, len);

	while (1) {
		printf("请输入要检测的数: [输入-1退出]");
		int value;
		scanf_s("%d", &value);
		if (value == -1) {
			break;
		}
		if (check(data, len, value)) {
			printf("%d在数据集合中\n", value);
		}
		else {
			printf("%d不在数据集合中\n", value);
		}
	}

	system("pause");
	return 0;
}