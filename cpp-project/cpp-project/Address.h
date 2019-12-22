/*
This holds address info - country, city, street and home number
*/

#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

const int MAX_LENGTH = 20; //length limit for strings

class Address
{
public:
	Address(char* country, char* city, char* street, int homeNumber); //c'tor
	Address(const Address& otherAddress); //copy c'tor
	bool setCountry(char *country); 
	bool setCity(char *city);
	bool setStreet(char *street);
	void setHomeNumber(int homeNumber);

	char *getCountry();
	char *getCity();
	char *getStreet();
	int getHomeNumber();

	bool isAddressValid(char* addressStr); //validates the address
	void show() const; //prints the address

private:
	char country[MAX_LENGTH];
	char city[MAX_LENGTH];
	char street[MAX_LENGTH];
	int homeNumber;
};

#endif
