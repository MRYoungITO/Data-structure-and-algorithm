#pragma once
class Pork;
class Goat;
class Cow
{
public:
	Cow(int weight = 0);

	friend Pork operator+(const Cow& cow1, const Cow& cow2);
	friend Pork operator+(const Cow& cow, const Goat& goat);
	friend Pork operator+(const Goat& goat, const Cow& cow)
	// 使用运算符重载来实现: 一头牛 + 一只牛 = ?
	//Pork operator+(const Cow& cow);  // 一头牛 + 一只牛 
	// 使用运算符重载来实现: 一头牛 + 一只羊 = ?
	//Pork operator+ (const Goat& goat);  // 一头牛 + 一只羊
; private:
	int weight;  //牛的体重
};

