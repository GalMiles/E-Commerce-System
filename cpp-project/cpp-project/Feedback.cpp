#include "Feedback.h"

Feedback::Feedback(string& userName, string& content, char date[11]) //feedback c'tor
{
	setUserName(userName);
	setContent(content);
	setDate(date);
}

void Feedback::setUserName(string& userName) {
	this->userName = userName;
}

void Feedback::setDate(char*& date) {
	strcpy(this->date, date);
}

void Feedback::setContent(string& content) {
	this->content = content;
}

const string Feedback::getUserName()
{
	return this->userName;
}

const string Feedback::getDate()
{
	return this->date;
}

const string Feedback::getContent()
{
	return this->content;
}
