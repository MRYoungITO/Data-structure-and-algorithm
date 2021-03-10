#include <iostream>
#include <Windows.h>

using namespace std;

//1+2+3...+100 = ?

int main (void) {
	//  while_exercise
	int a = 1;
	int sum1 = 0;

	while (a<=100){
		sum1 += a;
		a++;
	}

	cout << "sum1 = " << sum1 << endl;
	
	//  for_exercise
	int i = 1;
	int sum2 = 0;

	for (i; i<=100; i++){
		sum2 += i;
	}
	cout << "sum2 = " << sum2 <<endl;

	//do...while_exercise
	int b = 1;
	int sum3 = 0;

	do {
		sum3 += b;
		b++;
	} while (b<=100);

	cout << "sum3 = " << sum3 << endl;

	system("pause");
	return 0;
}