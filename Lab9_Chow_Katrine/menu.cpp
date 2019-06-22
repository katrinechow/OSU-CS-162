/*******************************************************************************
** Program Name: Lab 9 - Stack and Queue STL Containers: menu.cpp
** Author: Katrine Chow
** Date: March 9, 2018
** Description:	This is the implementation file for namespace menu, which builds
**		a menu interface for the recursion program.
*******************************************************************************/

#include "menu.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using namespace Menu;

/*******************************************************************************
**				Menu::displayMenu1()
** Description:	This function displays a user interface with choices.
*******************************************************************************/

void Menu::displayMenu1()
{
	cout << "Choose a function: " << endl;
	cout << endl;
	cout << "1) Start Buffer Simulation (Queue)" << endl;
	cout << "2) Create a Palindrome (Stack)" << endl;
	cout << "3) Exit" << endl;
}


/*******************************************************************************
**			char Menu:getChoice(char)
** Description:	This function collects user's choice.
*******************************************************************************/

char Menu::getChoice(char max)
{
	char choice = cin.get();
	cin.ignore();

	while (choice < '0' || choice > max)
	{
		cout << "Please enter a valid number from 1 to " << max << endl;
		choice = cin.get();
		cin.ignore();
	}
	return choice;
}


