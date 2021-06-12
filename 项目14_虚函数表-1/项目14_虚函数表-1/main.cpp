#include <iostream>

using namespace std;
class Father
{
public:
	virtual void func1() { cout << "Father::func1" << endl; }
	virtual void func2() { cout << "Father::func2" << endl; }
	virtual void func3() { cout << "Father::func3" << endl; }
	void func4() { cout << "·ÇÐéº¯Êý: Father::func4" << endl; }
private:
	int x = 200;
	int y = 300;
	static int z;
};

int Father::z = 0;

int main(void) {
	Father father;
}