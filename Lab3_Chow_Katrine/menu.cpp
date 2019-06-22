/*******************************************************************************
** Program Name: Lab 3 - War Game (dice): menu.cpp
** Author: Katrine Chow
** Date: January 27, 2018
** Description:	This is the implementation file for namespace menu, which builds
**		a menu interface for the War program.
*******************************************************************************/

#include "menu.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

using namespace Menu;

/*******************************************************************************
**				Menu::displayMenu()
** Description:	This function displays a user interface with choices.
*******************************************************************************/

void Menu::displayMenu()
{
	cout << "The Most Honest Dice Game in the World" << endl;;
	cout << "1) Play game" << endl;
	cout << "2) Exit game" << endl;
}



/*******************************************************************************
**				char Menu:getChoice(char)
** Description:	This function collects user's choice.
*******************************************************************************/

char Menu::getChoice(char max)
{
	char choice = cin.get();
	cin.ignore();

	while (choice < '1' || choice > max)
	{
		cout << "Please enter 1 or " << max << endl;
		choice = cin.get();
		cin.ignore();
	}

	return choice;
}
