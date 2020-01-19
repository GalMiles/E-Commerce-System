/*
This class holds info about sellers. It inherits from User
*/

#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <list> 
#include <iterator>
#include <string>
#include "User.h"
#include "Product.h"
using namespace std;

#pragma warning(disable: 4996)



//forward declaration
class Feedback;

class Seller : virtual public User
{
public:
	Seller(string name, string password, Address* address); //c'tor
	Seller(const Seller& otherSeller); //copy c'tor
	~Seller(); //d'tor

	//Product* getProducts();
	string getName();
	void addProduct(Product &product); //add product to productArr
	void addFeedback(Feedback &feedback); //add feedback to feedbackArr
	virtual void toOs(ostream& os) const override;


private:
	list<Product*> products;
	list<Feedback*> feedbackArr;

};

#endif 