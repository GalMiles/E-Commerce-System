#include "Feedback.h"

Feedback::Feedback(char *userName, char *content, char* date) //feedback c'tor
{
	this->userName = new char[strlen(userName) + 1];
	this->content = new char[strlen(content) + 1];
	setUserName(userName);
	setContent(content);
	setDate(date);
}

Feedback::Feedback(const Feedback& otherFeedback) {
	userName = *(new char*(otherFeedback.userName));
	strcpy(date, otherFeedback.date);
	content = *(new char*(otherFeedback.content));
}

Feedback::~Feedback() {
	delete this->userName;
	delete this->content;
}

void Feedback::setUserName(char* userName) {
	strcpy(this->userName, userName);
}

void Feedback::setDate(char* date) {
	strcpy(this->date, date);
}

void Feedback::setContent(char* content) {
	strcpy(this->content, content);
}

char *Feedback::getUserName()
{
	return this->userName;
}

char *Feedback::getDate()
{
	return this->date;
}

char *Feedback::getContent()
{
	return this->content;
}
