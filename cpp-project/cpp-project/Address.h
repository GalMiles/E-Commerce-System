/*
This holds address info - country, city, street and home number
*/

#ifndef __ADDRESS_H
#define __ADDRESS_H

#include<iostream>
#include<string>
#include <fstream>
using namespace std;

#pragma warning(disable: 4996)


class Address
{
public:
	Address(string& country, string& city, string& street, int homeNumber);//c'tor
	~Address() {}
	bool setCountry(string& country);
	bool setCity(string& city);
	bool setStreet(string& street);
	void setHomeNumber(int homeNumber);

	string& getCountry();
	string& getCity();
	string& getStreet();
	int getHomeNumber();

	bool isAddressValid(string& addressStr); //validates the address
	void show() const; //prints the address
	const Address& operator=(const Address& address);


	friend ostream& operator<<(ostream& os, Address& address);
	friend istream& operator>>(istream& in, Address& address);


private:
	string country;
	string city;
	string street;
	int homeNumber;
};


#endif
