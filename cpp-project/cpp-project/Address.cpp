#include "Address.h"

Address::Address(char* country, char* city, char* street, int homeNumber) {
	setCountry(country);
	setCity(city);
	setStreet(street);
	setHomeNumber(homeNumber);
}

Address::Address(const Address& otherAddress) {
	strcpy(this->city, otherAddress.city);
	strcpy(this->country, otherAddress.country);
	strcpy(this->street, otherAddress.street);
	homeNumber = *(new int(otherAddress.homeNumber));
}

char* Address::getCountry()
{
	return country;
}

char* Address::getCity()
{
	return city;
}

char* Address::getStreet()
{
	return street;
}

int Address::getHomeNumber()
{
	return homeNumber;
}

bool Address::setCountry(char *country)
{
	if (isAddressValid(country))
	{
		strcpy(this->country, country);
		return true;
	}
	else
		return false;
}

bool Address::setCity(char *city)
{
	if (isAddressValid(city))
	{
		strcpy(this->city, city);
		return true;
	}
	else
		return false;
}

bool Address::setStreet(char *street)
{
	if (isAddressValid(street))
	{
		strcpy(this->street, street);
		return true;
	}
	else
		return false;
}

void Address::setHomeNumber(int homeNumber)
{
	this->homeNumber = homeNumber;
}

bool Address::isAddressValid(char* addressStr) {
	int length = strlen(addressStr);
	for (int i = 0; i < length; i++) {
		if ((addressStr[i] < 'A' || (addressStr[i] > 'Z' && addressStr[i] < 'a') || addressStr[i] > 'z'))
			return false;
	}
	return true;
}

void Address::show() const
{
	cout << "The address is:" << homeNumber << " " << street << "," << city << "," << country << endl;
}