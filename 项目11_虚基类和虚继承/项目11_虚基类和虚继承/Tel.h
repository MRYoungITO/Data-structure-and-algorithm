#pragma once
#include <string>

using namespace std;

//电话类
//此时共同的祖先Tel类, 就成为虚基类
class Tel  //虚基类
{
public:
	Tel();
protected:
	string number;  //电话号码
};

