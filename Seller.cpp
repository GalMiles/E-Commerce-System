#include "Seller.h"
#include "User.h"


Seller::Seller(User *sellerUser)
{
	cout << "In seller constructor" << endl;
	this->sellerUser = sellerUser;
}