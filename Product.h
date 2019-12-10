#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

#include "Feedback.h"


class Product
{
	
public:
	Product(char *productName, double price, Feedback *feedback);//c'tor
	//~d'tor

	enum eCategory {CHILDREN, CLOTHES, HOME, SPORT};

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
	Feedback  *feedback;
};


#endif