#include "Human.h"
#include <sstream>


Human::Human() {

}

Human::Human(const string& name, gender_t gender, int age) {
	this->name = name;
	this->gender = gender;
	this->age = age;
}

Human::~Human() {

}

string Human::getName() const {
	return name;
}

int Human::getAge() const {
	return age;
}

gender_t Human::getGender() const {
	return gender;
}

Human* Human::getLover() const
{
	return lover;
}

vector<Human*> Human::getFriends() const {
	return friends;
}

string Human::description() const {
	stringstream des;
	des << name << "-age: " << age << "-" << (gender == MAN ? "男" : "女");
	return des.str();
}

void Human::marry(Human& other) {
	if (gender == other.gender) {
		return;
	}
	this->lover = &other;
	other.lover = this;
}

void Human::divorce() {
	if (this->lover == NULL) {
		return;
	}
	lover->lover = NULL;
	lover = NULL;
}

void Human::addFriend(Human& other) {  // & 这里是引用 
	friends.push_back(&other);  // & 这里是取地址符
}

void Human::delFriend(Human& other) {
	//auto x = 100;  //int x = 100;  自动推导类型用法
	//auto y = 3.14;	//double y = 3.14;
	//friends.begin() 返回一个特殊的指针, 指向第一个成员! ! ! > "迭代器"
	//不是 &friends[0]
	// friends.end() 返回一个迭代器, 指向最后一个元素的下一个位置
	for (auto it = friends.begin(); it != friends.end();) {
		if (*it == &other) {
			it = friends.erase(it);  //erase方法, 返回值是也是一个迭代器, 指向下一个成员
		}
		else {
			it++;
		}
	}
}
