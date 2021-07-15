#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class girl;

class boy {
public:
	boy() {
		cout << "boy construct!" << endl;
	}
	~boy() {
		cout << "boy destruct!" << endl;
	}

	void set_girl_friend(shared_ptr<girl>& girl_friend) {
		this->girl_friend = girl_friend;
	}

private:
	shared_ptr<girl> girl_friend;
};

class girl {
public:
	girl() {
		cout << "girl construct!" << endl;
	}
	~girl() {
		cout << "giel destruct!" << endl;
	}

	void set_boy_friend(shared_ptr<boy>& boy_friend) {
		this->boy_friend = boy_friend;
	}

private:
	shared_ptr<boy> boy_friend;
};

void use_trap() {
	shared_ptr<girl> sp_girl(new girl()); //°×Äï×Ó
	shared_ptr<boy> sp_boy(new boy());	  //ÐíÏÉ

	sp_girl->set_boy_friend(sp_boy);
	//sp_boy->set_girl_friend(sp_girl);
}

int main(void) {

	use_trap();

	system("pause");
	return 0;
}