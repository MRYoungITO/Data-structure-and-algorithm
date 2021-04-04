#include <stdio.h>
#include <stdlib.h>

//const 指针
int main(void) {
	int wife = 24;
	int girl = 18;

	printf("wife: %d, 0x%p\n", wife, &wife);

	//第一种   渣男型
	int *zha_nan = &wife;
	*zha_nan = 25;
	zha_nan = &girl;
	*zha_nan = 19;

	printf("girl: %d  wife: %d\n", girl, wife);

	//第二种   直男型
	//int const *zhi_nan = &wife;  另一种写法
	const int *zhi_nan = &wife;
	//*zhi_nan = 26;  //可以访问指针的值, 但无法直接修改指针的值
	printf("直男老婆的年龄和地址: %d, 0x%p\n", *zhi_nan, zhi_nan);
	zhi_nan = &girl;  //此种方式可以通过赋地址的方式来更改指针的值
	printf("直男女友的年龄和地址: %d, 0x%p\n", *zhi_nan, zhi_nan);

	//第三种   暖男型
	int * const nuan_nan = &wife;
	*nuan_nan = 26;
	printf("直男老婆的年龄和地址: %d, 0x%p\n", *nuan_nan, nuan_nan);
	//nuan_nan = &girl;  //不允许指向别的地址

	//第四种   超级暖男型
	const int * const super_nuan_nan = &wife;  //不允许指向别的地址, 不能修改指向变量的值
	//super_nuan_nan = 28;
	//super_nuan_nan = &girl;

	//总结:  看const 离类型(int)近, 还是离指针变量名近, 离谁近, 就修饰谁, 谁就不能变

	system("pause");
	return 0;
}