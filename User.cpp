#include "User.h"

User::User(char* name, char* password, Address *address, eUserType userType)
{
	int nameLength = strlen(name);
	cout << "In User constructor\n";
	this->name = new char[nameLength+1];
	strcpy(this->name, name);
	int passwordLength = strlen(password);
	this->password = new char[passwordLength + 1];
	strcpy(this->password, password);
	this->address = address;
	this->userType = userType;
}

/*
User::~User()
{

}
*/