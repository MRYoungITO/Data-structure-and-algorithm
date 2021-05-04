#pragma once
#include <string>

using namespace std;
class Boy;

class Girl
{
public:
	Girl();
	Girl(int age, string name, int yanZhi);
	~Girl();

	int getAge() const;
	string getName() const;
	int getYanZhi() const;
	bool satisfied(const Boy& boy);
	string description() const;
private:
	int age;
	string name;
	int yanZhi;	//—’÷µ
};

