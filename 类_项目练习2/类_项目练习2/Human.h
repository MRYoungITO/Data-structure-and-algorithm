#pragma once
#include <string>
#include <vector>

using namespace std;

typedef enum gender {
	MAN,  //男
	WOMEN  //女
} gender_t;

class Human
{
public:
	Human();
	Human(const string& name, gender_t gender, int age);
	~Human();

	string getName() const;
	int getAge() const;
	gender_t getGender() const;
	Human* getLover() const;
	vector<Human*> getFriends() const;
	string description() const;

	void marry(Human& other);
	void divorce();  //离婚
	void addFriend(Human& other);
	void delFriend(Human& other);

private:
	string name;  //昵称
	int age;
	gender_t gender;  //性别
	Human* lover = NULL;  //配偶, 爱人(聚合思想)
	vector<Human*> friends;
};

