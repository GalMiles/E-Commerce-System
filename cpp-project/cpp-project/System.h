#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "Menu.h"

const int MAX_LENGTH = 20;

class System
{
public:
	System();
	const char STORE_NAME[8] = "AlmoGal";
	void initSystem();
	void performChoice(int choice);
	void addBuyer();

private:
	Menu theMenu;
};

#endif