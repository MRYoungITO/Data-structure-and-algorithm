#include <iostream>
#include <Windows.h>

using namespace std;

class Animal {
public:
	void cry() {
		cout << "动物叫" << endl;
	}
};

class Cat : public Animal {
public:
	void cry() {
		cout << "喵喵喵" << endl;
	}
};

class Dog : public Animal {
public:
	void cry() {
		cout << "汪汪汪" << endl;
	}
};

int main(void) {

	//用法一 数值与指针之间的转换
	int* p = reinterpret_cast<int*>(0x888888);
	int val = reinterpret_cast<int>(p);
	

	//用法二 不同类型指针和引用之间的转换
	Dog dog1;
	Animal* a1 = &dog1;
	a1->cry();

	Cat* cat_p = reinterpret_cast<Cat*>(a1);

	Dog* dog1_p = reinterpret_cast<Dog*>(a1);
	Dog* dog2_p = static_cast<Dog*>(a1); //如果能用static_cast, static_cast优先

	//Cat* cat1_p = static_cast<Cat*>(a1);
	//Cat* cat1_p = static_cast<Cat*>(dog1_p); //NO! 不同类型指针转换不能使用static_cast
	Cat* cat1_p =  reinterpret_cast<Cat*>(dog1_p);

	Animal& a2 = dog1;
	Dog& dog3 = reinterpret_cast<Dog&>(a2); //引用强转用法

	dog1_p->cry();
	dog2_p->cry();

	cat1_p->cry();

	system("pause");
	return 0;
}