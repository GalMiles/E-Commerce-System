#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include <iostream>
#include <string.h>
using namespace std;

#include "User.h"

#pragma warning(disable: 4996)


class Feedback
{
	
public:
	bool setUserName(char *userName);
	bool setDate(char *date);
	bool setContent(char *content);

	User getUser();
	char *getDate();
	char *getContent();

private:
	char   *m_userName;
	char  *m_date;
	char  *m_content;
};
#endif