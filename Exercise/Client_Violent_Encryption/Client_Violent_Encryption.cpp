#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main (void) {
	 char pwd[7];
	 char dict[64];  //10+26+26+1 = 63;
	 char tmp[32];
	 int index = 0;

	 
	 for (int i=0; i<10; i++) {
		dict[index++] = '0' + i;
	 }
	 /*
	 for (int b=0; b<26; b++) {
		//  'c' = 'a' + 2
		dict[index++] = 'a' + b;
	 }

	 for (int a=0; a<26; a++) {
		dict[index++] = 'A' + a;
	 }
	*/

	 int n = index;
	 for (int p1=0; p1<n; p1++) {
		 for (int p2=0; p2<n; p2++) {
			 for (int p3=0; p3<n; p3++) {
				 for (int p4=0; p4<n;p4++) {
					 for (int p5=0; p5<n; p5++) {
						 for (int p6=0; p6<n; p6++) {
							 tmp[0] = dict[p1];
							 tmp[1] = dict[p2];
							 tmp[2] = dict[p3];
							 tmp[3] = dict[p4];
							 tmp[4] = dict[p5];
							 tmp[5] = dict[p6];
							 tmp[6] = '\0';
							 cout << tmp <<endl;
						 }
					 }
				 }
			 }
		 }
	 }

	system("pasue");
	return 0;
}