#include "Book.h"

Book::Book(float price, string isbn)
{
	this->price = price;
	this->ISBN = isbn;
}

Book::~Book()
{

}

float Book::getPrice() {
	return price;
}

string Book::getISBN() {
	return ISBN;
}