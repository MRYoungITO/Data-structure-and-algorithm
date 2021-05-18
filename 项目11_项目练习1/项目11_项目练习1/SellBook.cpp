#include "SellBook.h"

SellBook::SellBook(float price, string isbn, float discount) :Book(price, isbn)
{
	this->discount = discount;
}

SellBook::~SellBook()
{

}

float SellBook::getDiscount() 
{
	return discount;
}

void SellBook::setDiscount(float discount) 
{
	this->discount = discount;
}

float SellBook::getPrice() 
{
	float ret = price * discount / 10.0;
	return ret;
}