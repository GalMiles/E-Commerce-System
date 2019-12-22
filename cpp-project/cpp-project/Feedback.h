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
	Feedback(char *userName, char *content, char *date); //c'tor
	Feedback(const Feedback& otherFeedback); //copy c'tor
	~Feedback(); //d'tor
	void setUserName(char* userName);
	void setDate(char* date);
	void setContent(char* content);
	char *getUserName();
	char *getDate();
	char *getContent();

private:
	char *userName;
	char date[DATE_LENGTH];
	char *content;
};
#endif