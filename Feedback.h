#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include <iostream>
#include <string.h>
using namespace std;

#include "User.h"
#include "Seller.h"

#pragma warning(disable: 4996)


class Feedback
{	
public:
	Feedback(char *userName, char *content);

	char *getUserName();
	char *getDate();
	char *getContent();

private:
	char *userName;
	char *date;
	Seller *seller;
	char *content;
};
#endif