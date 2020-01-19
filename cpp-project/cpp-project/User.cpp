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
	os << (typeid(user).name())+6 << "'s name: " << user.name << endl;
	user.toOs(os); //using buyer/seller method
	return os;
}