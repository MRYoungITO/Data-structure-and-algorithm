#pragma once
#include <string>
#include <vector>
#include "Single.h"

using namespace std;
class Boy;

class Girl :public Single
{
public:
	Girl();
	Girl(int age, string name, int yanZhi);
	~Girl();

	//int getAge() const;
	//string getName() const;
	int getYanzhi() const;
	bool satisfied(const Boy& Boys) const;
	string description() const;
	static void inputGirls(vector<Girl>& girls);
private:
	//int age;
	//string name;
	int yanZhi;
};
