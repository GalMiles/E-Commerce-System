#include <iostream>
#include <string.h>

#include "Menu.h"
//dfgdfgd
using namespace std;

void main() {
	System system("AlmoGal");
	Menu mainMenu(&system);
	int choice;
	do {
		choice = mainMenu.initMenu();
		mainMenu.choiceCases(choice);
		system.showSellerArr();
	} while (choice >= 1 && choice <= 10);
}