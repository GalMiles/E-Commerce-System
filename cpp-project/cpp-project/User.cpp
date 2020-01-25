#include "User.h"

User::User(string& name, string& password, const Address& address): address(address) //c'tor
{
	setUserName(name);
	setPassword(password);
	
}

User::User(const User& otherUser) :address(otherUser.address)
{
	this->name = otherUser.name;
	this->password = otherUser.password;
	
}

User::~User() {

}

void User::setUserName(string name) {
	this->name = name;
}

void User::setPassword(string password) {
	this->password = password;
}

/*void User::setAddress(Address* address) {
	this->address = address;
}*/


string User::getUserName()
{
	return name;
}

Address User::getAddress()
{
	return address;
}


void User::show() const
{
	cout << "The name is: " << name << endl;
}

ostream& operator<<(ostream& os, const User& user)
{
	if (typeid(os) == typeid(ofstream))//write to file
		os << user << endl;

	else // write to screen
	{
		os << (typeid(user).name()) + 6 << "'s name: " << user.name << endl;
		user.toOs(os); //using buyer/seller method
	}
	
	return os;
}

User::User(ifstream& in) : address(in)
{
	in >> this->name;
	in >> this->password;

}//c'tor that gets file

istream& operator>>(istream& in, User& user)
{

	in >> user.name >> user.password;
	in >> user.address;

	
	return in;
}

void User::saveType(ofstream& outFile) const
{
	//only 3 letters of type
	char type[4];
	if (strcmp(typeid(*this).name() + 6, "SellerBuyer") == 0)
		strncpy(type,"SeB",3);
	else //if its seller or buyer
	{
		strncpy(type, typeid(*this).name() + 6, 3);
	}
	outFile.write(type, 3);
	outFile.write(" ", 1);
}

void User::saveUser(ofstream& outFile) const
{
	outFile << this->address << " ";
	outFile << this->name << " ";
	outFile << this->password << " ";

}

