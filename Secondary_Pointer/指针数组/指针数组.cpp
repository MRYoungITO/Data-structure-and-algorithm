#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int girls[4][3] = {{173, 158, 166},
							 {168, 155, 171},
							 {163, 164, 165},
							 {163, 164, 172}};
	//int x1,y1,   x2,y2;
	int *qishou[2];  //定义一个有两个元素的指针数组, 每个元素都是一个指针变量

	if(girls[0][0]>girls[0][1]) {
		qishou[0] = &girls[0][0];
		qishou[1] = &girls[0][1];
	} else {
		qishou[0] = &girls[0][1];
		qishou[1] = &girls[0][0];
	}

	for(int i=2; i<12; i++) {
		//girls[i/3][i%3];
		if(*qishou[1]>=girls[i/3][i%3]) {
			continue;
		}
			//候选者高于第二位旗手候选女兵
			//1.候选者比第一位候选人矮
		if(girls[i/3][i%3]<=*qishou[0]){
			qishou[1] = &girls[i/3][i%3];
		} else {
			//2.候选者比"冠军"高
			qishou[1] = qishou[0];
			qishou[0] = &girls[i/3][i%3];
		}
	}

	printf("最高女兵的身高: %d, 次高女兵的身高: %d\n", *qishou[0], *qishou[1]);

	system("pause");
	return 0;
}