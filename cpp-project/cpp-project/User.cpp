#include "User.h"

User::User(string name, string password, Address *address)
{
	setUserName(name);
	setPassword(password);
	setAddress(address);
}

User::User(const User& otherUser) {
	this->name = otherUser.name;
	this->password = otherUser.password;
	address = otherUser.address;
}

User::~User() {

}

void User::setUserName(string name) {
	this->name = name;
}

void User::setPassword(string password) {
	this->password = password;
}

void User::setAddress(Address* address) {
	this->address = address;
}


string User::getUserName()
{
	return name;
}

Address* User::getAddress()
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

User::User(ifstream& in) { in >> *this; }//c'tor that gets file

istream& operator>>(istream& in, User& user)
{
	if (typeid(in) == typeid(ifstream))//write from file
		in >> user;

	else // cin>> user
	{
		in >> user.name >> user.password;
		in >> *(user.address);

	}
	return in;
}