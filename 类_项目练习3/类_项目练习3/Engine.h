#pragma once
#include <string>

using namespace std;

class Engine
{
public:
	Engine();
	Engine(const string& brand, float verison);  //const string& brand, 这样定义不会改变参数所带入的值
	~Engine();

	string description() const;

private:
	string brand;  //发动机品牌
	float verison;  //发动机型号:  x. x升
};

