#include "User.h"

User::User(char* name, char* password, Address *address, eUserType userType)
{
	cout << "In User constructor\n";
	this->name = new char[strlen(name) + 1];
	this->password = new char[strlen(password) + 1];
	setUserName(name);
	setPassword(password);
	setAddress(address);
	setUserType(userType);
}

User::~User()
{
	cout << "in user d'tor" << endl;
}

void User::setUserName(char* name) {
	new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void User::setPassword(char* password) {
	strcpy(this->password, password);
}
void User::setAddress(Address* address) {
	this->address = address;
}
void User::setUserType(eUserType userType) {
	this->userType = userType;
}

char* User::getUserName()
{
	return name;
}

Address* User::getAddress()
{
	return address;
}

/*
eUserType User::getUserType()
{
	return userType;
}
*/

void User::show() const
{
	cout << "The name is:" << name << endl;
	address->show(); // using Address method
	cout << "The user is:" << userType << endl;
}