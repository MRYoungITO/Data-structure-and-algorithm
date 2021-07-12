#include <iostream>
#include <Windows.h>

using namespace std;

class Animal {
public:
	virtual void cry() = 0;
};

class Cat : public Animal {
public:
	virtual void cry() {
		cout << "喵喵喵" << endl;
	}
};

class Dog : public Animal {
public:
	virtual void cry() {
		cout << "汪汪汪" << endl;
	}
};

int main(void) {

	//第一种情况 父子类之间的类型转换
	Dog* dog1 = new Dog();
	Animal* a1 = static_cast<Animal*>(dog1); //子类的指针转型到父类指针
	a1->cry();
	
	Dog* dog1_1 = static_cast<Dog*>(a1);	 //父类的指针转型到子类的指针
	Cat* cat1 = static_cast<Cat*>(a1);		 //父类到子类, 有风险, 这样是不行的, 会出问题

	Dog dog2;
	Animal& a2 = static_cast<Animal&>(dog2); //子类的引用转型到父类的引用
	Dog& dog2_2 = static_cast<Dog&>(a2);	 //父类到子类的引用
	a2.cry();
	delete dog1;

	//第二种 基本类型的转换
	int kk = 234;
	char cc = static_cast<char>(kk);

	//第三种 把空指针转换成目标类型的空指针
	int* p = static_cast<int*>(NULL);
	Dog* dp = static_cast<Dog*>(NULL);

	//第四种 把任何类型的表达式转换城void类型
	int* q = new int[10];
	void* vq = static_cast<void*>(q);
	vq = q;

	system("pause");
	return 0;
}