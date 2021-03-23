#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int ages[] = {20, 18, 19, 24, 23, 28, 30, 38, 35, 32};
	int len = sizeof(ages) / sizeof(ages[0]);

	int *p = ages;
	printf("第7个美女的年龄: %d\n", *(p+6));
	printf("*p+6: %d\n", *p+6);  //*取值运算符 优先级高于 加号运算符
	printf("第3个美女的年龄: %d\n", *(p+2));

	int *p1 = &ages[4];
	printf("第五个美女,她的年龄和地址: %d, 0x%p\n", *p1, p1);
	printf("相对于第五个美女,她的后一位的年龄和地址: %d,  0x%p\n", *(p1+1), p1+1);
	printf("相对于第五个美女,她的前一位的年龄和地址: %d,  0x%p\n", *(p1-1), p1-1);

	/*通过指针遍历数组
	for(int i=0; i<len; i++) {
		printf("%d ", *p++);
	}
	printf("\n");
	*/

	system("pause");
	return 0;
}