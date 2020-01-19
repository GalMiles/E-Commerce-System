/*
This class holds general user info (address, password, user name - info which is required for any user - buyer or seller)
*/

#ifndef __USER_H
#define __USER_H

#include <iostream>
#include <string.h>
#include "Address.h"

using namespace std;

#pragma warning(disable: 4996)

class User
{
public:

	string getUserName();
	void setUserName(string name);
	void setPassword(string password);
	void setAddress(Address* address);
	Address* getAddress();

	User(string name, string password, Address* address); //c'tor
	User(const User& otherUser); //copy c'tor
	virtual ~User(); // d'tor is virtual for inheritance purpose

	void show() const; //print user's info

	friend ostream& operator<<(ostream& os, const User& user); //print << operator
	virtual void toOs(ostream& os) const = 0;


protected:
	string		name;
	string		password;
	Address		*address;
};

#endif