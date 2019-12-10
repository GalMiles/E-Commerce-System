#include "Feedback.h"

Feedback::Feedback(char *userName, char *content)//feedback c'tor

{
	int nameLength = strlen(userName);
	cout << "In Feedback constructor\n";
	this->userName = new char[nameLength + 1];
	strcpy(this->userName, userName);

	nameLength = strlen(date);
	this->date = new char[nameLength + 1];
	strcpy(this->date, date);


	/*
	nameLength = strlen(date);
	this->date = new char[nameLength + 1];
	strcpy(this->date, date);
*/
	nameLength = strlen(content);
	this->content = new char[nameLength + 1];
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




