#include "Menu.h"

int Menu::initMenu() {
	cout << "Welcome to storeName" << endl;
	cout << "Please select the desired option from the following:" << endl;
	for (int i = 0; i < OPTIONS_LENGTH; i++) {
		cout << "[" << i + 1 << "] " << options[i] << endl;
	}
}