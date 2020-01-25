/*
This class holds general user info (address, password, user name - info which is required for any user - buyer or seller)
*/

#ifndef __USER_H
#define __USER_H

#include <iostream>
#include <string.h>
#include <fstream>
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

	User(string& name, string& password, Address* address); //c'tor
	User(const User& otherUser); //copy c'tor
	virtual ~User(); // d'tor is virtual for inheritance purpose
	User(ifstream& in);//c'tor to load data from file

	void show() const; //print user's info

	friend ostream& operator<<(ostream& os, const User& user); //print << operator
	friend istream& operator >> (istream& in, User& user);

	virtual void toOs(ostream& os) const = 0;
	virtual void saveUser(ofstream& outFile) const;
	void saveType(ofstream& outFile) const;


protected:
	string		name;
	string		password;
	Address		*address;
};

#endif