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
	Feedback(string userName, string content, string date); //c'tor
	Feedback(const Feedback& otherFeedback); //copy c'tor
	void setUserName(string userName);
	void setDate(string date);
	void setContent(string content);
	string getUserName();
	string getDate();
	string getContent();

private:
	string userName;
	string date[DATE_LENGTH];
	string content;
};
#endif