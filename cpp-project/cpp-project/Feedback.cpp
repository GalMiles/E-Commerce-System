#include "Feedback.h"

Feedback::Feedback(string userName, string content, string date) //feedback c'tor
{
	setUserName(userName);
	setContent(content);
	setDate(date);
}

Feedback::Feedback(const Feedback& otherFeedback) {
	this->userName = otherFeedback.userName;
	this->content = otherFeedback.content;
}

void Feedback::setUserName(string userName) {
	this->userName = userName;
}

void Feedback::setDate(string date) {
	this->date = date;
}

void Feedback::setContent(string content) {
	this->content = content;
}

string Feedback::getUserName()
{
	return this->userName;
}

string Feedback::getDate()
{
	return this->date;
}

string Feedback::getContent()
{
	return this->content;
}
