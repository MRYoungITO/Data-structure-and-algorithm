#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <memory>
#include <vector>

using namespace std;

class Person {
public:
	Person(int v) {
		no = v;
		cout << "Construct" << no << endl;
	}
	~Person() {
		cout << "Destruct" << no << endl;
	}
	int no;
};

int main(void) {

	shared_ptr<Person> sp1;  //空的shared_ptr, 可以指向类型为T的对象
	shared_ptr<Person> sp2(new Person(2));  //定义shared_ptr,同时指向类型为T的对象

	cout << "sp2 ref_counter: " << sp2.use_count();  //当前管控Person(2) 的共享指针的数量

	system("pause");
	return 0;
}