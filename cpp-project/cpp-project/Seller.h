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
#include "Array.h"
using namespace std;

#pragma warning(disable: 4996)



//forward declaration
class Feedback;

class Seller : virtual public User
{
public:
	Seller(string& name, string& password, const Address& address); //c'tor
	Seller(const Seller& otherSeller); //copy c'tor
	~Seller(); //d'tor
	Seller(ifstream& inFile);

	list<Product*>& getProducts();
	const string getName();
	void addProduct(Product &product); //add product to productArr
	void addFeedback(Feedback &feedback); //add feedback to feedbackArr
	virtual void toOs(ostream& os) const override;



private:
	list<Product*> products;
	Array<Feedback*> feedbackArr;

};

#endif 