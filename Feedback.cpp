#include "Feedback.h"

bool Feedback::setUserName(char *userName)
{
	strcpy(m_userName, userName);
	return true; ///just to make it work
}

