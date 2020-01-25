/*
This class holds feedback info.
*/
#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include <iostream>
#include <string.h>
using namespace std;

#include "User.h"
#include "Seller.h"

#pragma warning(disable: 4996)

const int DATE_LENGTH = 11; //limit the date's string length

class Feedback
{
public:
	Feedback(string& userName, string& content, char date[11]); //c'tor
	void setUserName(string& userName);
	void setDate(char*& date);
	void setContent(string& content);
	const string getUserName();
	const string getDate();
	const string getContent();

private:
	string userName;
	char date[11];
	string content;
};
#endif