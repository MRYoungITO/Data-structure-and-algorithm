#pragma once
#include <string>

using namespace std;

class Book
{
public:
	Book(float price, string isbn);
	~Book();

	float getPrice();  //查看价格
	string getISBN();  //查看书号

protected:
	float price;
	string ISBN; //书号
};