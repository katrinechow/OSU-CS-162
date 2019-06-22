/*******************************************************************************
** Program Name: Project 1: Langton's Ant - menu.cpp
** Author: Katrine Chow
** Date: January 10, 2018
** Description:	This is the implementation file for namespace menu, which builds
**		a menu interface for the Langton's Ant simulation.
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
	cout << "Go Ant or Go Home" << endl;;
	cout << "1) Start Langton's Ant simulation" << endl;
	cout << "2) Start simulation with Random Location" << endl;
	cout << "3) Quit" << endl;
}


/*******************************************************************************
**				Menu::displayMenu2()
** Description:	This displays the second menu after the game starts.
*******************************************************************************/

void Menu::displayMenu2()
{
	cout << "We're Not Quitters!" << endl;
	cout << "1) Play Again" << endl;
	cout << "2) Quit" << endl;
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
