#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	for (int i=1; i<=20; i++) {      //表示公鸡数量
		for (int j=1; j<=33; j++) {  //j表示母鸡数量
			int k = 100 - i - j;          //表示小鸡数量
			if(k%3 == 0 && i*50+j*30+k/3*10 == 1000) {
					cout << "公鸡：" << i << " 母鸡：" << j << " 小鸡：" << k << endl;
			}
		}
	}

	system("pause");
	return 0;
}