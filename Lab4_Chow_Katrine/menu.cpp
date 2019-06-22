/*******************************************************************************
** Program Name: Lab 4 - OSU Information System: menu.cpp
** Author: Katrine Chow
** Date: January 30, 2018
** Description:	This is the implementation file for namespace menu, which builds
**		a menu interface for the osu program.
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
	cout << "Welcome to the OSU Information System" << endl;;
	cout << "1) Building Directory" << endl;
	cout << "2) Student/Faculty Directory" << endl;
	cout << "3) Choose a person to do work" << endl;
	cout << "4) Exit" << endl;
}


/*******************************************************************************
**			Menu::displayMenu2(vector<Person>)
** Description:	This function displays a Person directory and allows user to
**		select the Person he/she wants to work with.
*******************************************************************************/

void Menu::displayMenu2(vector<Person*> pvec)
{
	int input = 0;

	cout << "Choose from the list below: " << endl;
	
	for (int i = 1; i < pvec.size(); i++)
	{
		cout << i << ") " << pvec[i]->getName() << endl; 
	}
	cout << "Enter your choice: " << endl;
	cin >> input;

	pvec[input]->do_Work();	

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
		cout << "Please enter a valid number from 1 to " << max << endl;
		choice = cin.get();
		cin.ignore();
	}

	return choice;
}
