/*******************************************************************************
** Program Name: Project 2 - Zoo Tycoon: menu.cpp
** Author: Katrine Chow
** Date: January 30, 2018
** Description:	This is the implementation file for namespace menu, which builds
**		a menu interface for the Zoo Tycoon program.
*******************************************************************************/

#include "menu.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

using namespace Menu;

/*******************************************************************************
**				Menu::displayMenu1()
** Description:	This function displays a user interface with choices.
*******************************************************************************/

void Menu::displayMenu1()
{
	cout << endl;
	cout << "####################" << endl;
	cout << "#                  #" << endl;
	cout << "#    Zoo Tycoon    #" << endl;
	cout << "#                  #" << endl;
	cout << "####################" << endl;
	cout << endl;
	cout << endl;
	cout << "1) Start Game" << endl;
	cout << "2) Quit" << endl;
}


/*******************************************************************************
**				Menu::displayMenu2()
** Description:	This menu asks user if they would like to play again or quit.
*******************************************************************************/

void Menu::displayMenu2()
{
	cout << "1) Continue? " << endl;
	cout << "2) I'm shutting down this zoo for good. " << endl;
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
