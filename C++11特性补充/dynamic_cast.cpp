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

	void play() {
		cout << "爬爬树" << endl;
	}

};

class Dog : public Animal {
public:
	virtual void cry() {
		cout << "汪汪汪" << endl;
	}

	void play() {
		cout << "溜达溜达" << endl;
	}
};

void animalPlay(Animal& animal) {
	animal.cry();

	try {
		Dog& pDog = dynamic_cast<Dog&>(animal);
		pDog.play();
	}
	catch (std::bad_cast bc) {
		cout << "不是狗, 那应该是猫" << endl;
	}
	

	try {
		Cat& pCat = dynamic_cast<Cat&>(animal);
		pCat.play();
	}
	catch (std::bad_cast bc) {
		cout << "不是猫, 那应该是上面的狗" << endl;
	}
}

void animalPlay(Animal* animal) {
	animal->cry();

	Dog* pDog = dynamic_cast<Dog*>(animal);
	if (pDog) {
		pDog->play();
	}
	else { //pDog == NULL
		cout << "不是狗, 别骗我! " << endl;
	}

	Cat* pCat = dynamic_cast<Cat*>(animal);
	if (pCat) {
		pCat->play();
	}
	else { //pCat == NULL
		cout << "不是猫, 别骗我! " << endl;
	}
}

int main(void) {

	Dog* dog1 = new Dog();
	Animal* a1 = dog1;

	//animalPlay(a1);
	Dog dog2;
	animalPlay(dog2);

	Cat* cat1 = new Cat();
	Animal* a2 = cat1;

	//animalPlay(a2);
	Cat cat2;
	animalPlay(cat2);

	system("pause");
	return 0;
}