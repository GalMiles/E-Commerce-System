#include <iostream>
#include <string.h>

#include "Menu.h"
//dfgdfgd
using namespace std;

void main() {
	Menu mainMenu;
	int choice = mainMenu.initMenu();
	mainMenu.choiceCases(choice);
}