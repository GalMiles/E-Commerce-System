#include "Address.h"

Address::Address(string& country, string& city, string& street, int homeNumber) {
	setCountry(country);
	setCity(city);
	setStreet(street);
	setHomeNumber(homeNumber);
}

string& Address::getCountry() { return country; }

string& Address::getCity() { return city; }

string& Address::getStreet() { return street; }

int Address::getHomeNumber() { return homeNumber; }


bool Address::setCountry(string& country)
{
	if (isAddressValid(country))
	{
		this->country = country;
		return true;
	}
	else
		return false;
}

bool Address::setCity(string& city)
{
	if (isAddressValid(city))
	{
		this->city = city;
		return true;
	}
	else
		return false;
}

bool Address::setStreet(string& street)
{
	if (isAddressValid(street))
	{
		this->street = street;
		return true;
	}
	else
		return false;
}

void Address::setHomeNumber(int homeNumber)
{
	this->homeNumber = homeNumber;
}

bool Address::isAddressValid(string& addressStr) {
	int length = addressStr.length();
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



istream& operator >> (istream& in, Address& address)
{
	in >> address.country >> address.city >> address.street >> address.homeNumber;

	return in;
}

ostream& operator<<(ostream& os, Address& address)
{
	os << "blabla";

	return os;

}

const Address& Address::operator=(const Address& address)
{
	this->country = address.country;
	this->city = address.city;
	this->street = address.street;
	this->homeNumber = address.homeNumber;

	return *this;
}