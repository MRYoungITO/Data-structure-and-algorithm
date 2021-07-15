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
	shared_ptr<girl> sp_girl(new girl()); //白娘子
	shared_ptr<boy> sp_boy(new boy());	  //许仙

	//弱指针的使用
	weak_ptr<girl> wp_girl1;			//定义空的弱指针
	weak_ptr<girl> wp_girl2(sp_girl);	//使用共享构造
	wp_girl1 = sp_girl;					//允许共享指针赋值给弱指针
	
	sp_girl->set_boy_friend(sp_boy);
	//sp_boy->set_girl_friend(sp_girl);
}

int main(void) {

	use_trap();

	system("pause");
	return 0;
}