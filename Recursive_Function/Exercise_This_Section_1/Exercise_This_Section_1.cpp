#include <iostream>
#include <Windows.h>

using namespace std;

void pyramid(int n, char ch='*') {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n-1-i; j++) {
			cout << " ";
		}
		for (int j=0;j<2*i+1; j++) {
			cout << ch;
		}
		cout << endl;
	}
}

int averageSalary(int data[], int n) {
	int sum = 0;
	for (int i=0; i<n; i++) {
		sum += data[i];
	}
	return sum / n;
}

int main(void) {
	int salary[5] = {50000, 35000, 28000, 15000, 20000};
	cout << averageSalary(salary, 5) << endl;
	/*
	int n = 0;
	char ch;
	cout << "ÇëÊäÈë½ð×ÖËþµÄ²ãÊý:  ";
	cin >> n;
	cout << "ÇëÊäÈë½ð×ÖËþµÄ×Ö·û:  ";
	cin >> ch;

	pyramid(n, ch);
	*/
	system("pause");
	return 0;
}