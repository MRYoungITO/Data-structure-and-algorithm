#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/*据同学们报道, A栋学生有学生用高倍望远镜偷看别人洗澡,
	宿管办决定逐个宿舍排查, 得到的线报是A0 到 A3 宿舍的
	某个个子最矮的男生.
	*/
	int A[4][3] = {{173, 158, 166},
						{168, 155, 171},
						{163, 164, 165},
						{163, 164, 172}};

	int (*p)[3];  //定义一个指向三个成员的数组的指针
	
	p = &A[0];

	//第一种   数组下标法
	/*for(int i=0; i<4; i++) {
		for(int j=0; j<3; j++) {
			printf(" %d", (*p)[j]);  //(*p) 等同于 a[0], a[0][0] 等同于 (*p)[0]
		}
		printf("\n");
		p++;
	}*/

	//第二种   指针访问法  
	//int a[3];
	//int *p;
	//p=a;(指向数组首位元素地址)
	//数组成员: *p, *(p+1), *(p+2), ...... 

	int *boy = NULL;
	boy = &(*p)[0];
	//boy = *p;

	for(int i=0; i<4; i++) {
		for(int j=0; j<3; j++) {
			printf(" %d", *((*p)+j));
			if(*boy > *((*p)+j)) {
				boy = (*p)+j;
			}
		}
		printf("\n");
		p++;
	}

	printf("偷窥的学生是: %d\n", *boy);

	system("pause");
	return 0;
}