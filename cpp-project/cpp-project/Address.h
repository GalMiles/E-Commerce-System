/*
This holds address info - country, city, street and home number
*/

#ifndef __ADDRESS_H
#define __ADDRESS_H

#include<iostream>
#include<string>
using namespace std;

#pragma warning(disable: 4996)

const int MAX_LENGTH = 20; //length limit for strings

class Address
{
public:
	Address(string& country, string& city, string& street, int homeNumber); //c'tor
	bool setCountry(string& country);
	bool setCity(string& city);
	bool setStreet(string& street);
	void setHomeNumber(int homeNumber);

	string getCountry();
	string getCity();
	string getStreet();
	int getHomeNumber();

	bool isAddressValid(string& addressStr); //validates the address
	void show() const; //prints the address

	friend ostream& operator<<(ostream& os, const Address& adress);

private:
	string country;
	string city;
	string street;
	int homeNumber;
};

#endif
