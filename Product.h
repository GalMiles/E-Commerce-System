#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)


class Product
{
	
public:
	enum eCategory {CHILDREN, CLOTHES, HOME, SPORT};
	static constexpr char* categories[] = { "Children", "Clothes", "Home", "Sport" };

	Product(char *productName, double price, eCategory category);//c'tor
	//~d'tor

	char *getName();
	double getPrice();
	//eCategory getCategory();
	int getProductId();
	
private:
	static int productCounter;
	char     *name;
	double    price;
	eCategory category;
	int       productId;
};


#endif