#include <iostream>
#include "Book.h"
#include "SellBook.h"

int main(void) {
	Book book1(98, "3240000-12");
	cout << "Price:" << book1.getPrice() << " ISBN:" << book1.getISBN() << endl;

	SellBook book2(98, "3240000-12");
	cout << "Price:" << book2.getPrice() << " ISBN:" << book2.getISBN() << endl;

	book2.setDiscount(5);
	cout << "Price:" << book2.getPrice() << " ISBN:" << book2.getISBN() << endl;
	cout << "Discount:" << book2.getDiscount() << endl;

	system("pause");
	return 0;
}