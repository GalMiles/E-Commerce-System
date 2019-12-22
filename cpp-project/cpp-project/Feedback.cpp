#include "Feedback.h"

Feedback::Feedback(char *userName, char *content) //feedback c'tor
{
	this->userName = new char[strlen(userName) + 1];
	//this->date = new char[strlen(date) + 1];
	this->content = new char[strlen(content) + 1];
	setUserName(userName);
	//setDate(date); // TODO: Implement this
	setContent(content);
}

Feedback::Feedback(const Feedback& otherFeedback) {
	userName = *(new char*(otherFeedback.userName));
	//date = *(new char*(otherFeedback.date));
	content = *(new char*(otherFeedback.content));
}

void Feedback::setUserName(char* userName) {
	strcpy(this->userName, userName);
}
/*
void Feedback::setDate(char* date) { // TODO: Implement this
	strcpy(this->date, date);
}
*/
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
