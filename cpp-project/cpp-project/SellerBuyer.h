/*
This is a class for sellers who are also buyers.
It inherits from Seller and from Buyer. Both of these classes inherit from User.
*/

#ifndef  __SELLERBUYER_H
#define  __SELLERBUYER_H


#include "Seller.h"
#include "Buyer.h"

class SellerBuyer : public Seller, public Buyer
{
public:
	SellerBuyer(const Seller& seller, const Buyer& buyer);//c'tor
	SellerBuyer(Seller&& seller, Buyer&& buyer); //copy c'tor
	~SellerBuyer();//d'tor



	virtual void toOs(ostream& os) const override;

};

#endif // ! __SELLERBUYER_H
