#include "SellerBuyer.h"
#include "User.h"

SellerBuyer::SellerBuyer(const Seller& seller, const Buyer& buyer): User(seller),Seller(seller), Buyer(buyer)
{

}
SellerBuyer::SellerBuyer(Seller&& seller, Buyer&& buyer) : User(move(seller)), Seller(move(seller)), Buyer(move(buyer))
{

}
SellerBuyer::~SellerBuyer()
{

}

void SellerBuyer::toOs(ostream& os) const
{
	Seller::toOs(os);
	Buyer::toOs(os);
}

SellerBuyer::SellerBuyer(ifstream& inFile) :User(inFile), Seller(inFile), Buyer(inFile) { }




