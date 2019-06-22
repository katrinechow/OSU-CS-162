/*******************************************************************************
** Program Name: Lab 7 - Circular Linked List: menu.cpp
** Author: Katrine Chow
** Date: February 22, 2018
** Description:	This is the implementation file for namespace menu, which builds
**		a menu interface for the circular program.
*******************************************************************************/

#include "menu.hpp"
#include "node.hpp"
#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

using namespace Menu;

/*******************************************************************************
**				Menu::displayMenu1()
** Description:	This function displays a user interface with choices.
*******************************************************************************/

void Menu::displayMenu1()
{
	cout << "Choose a function: " << endl;
	cout << endl;
	cout << "1) Add a value to the back of queue" << endl;
	cout << "2) Display the front value" << endl;
	cout << "3) Remove the front node" << endl;
	cout << "4) Display the queue's content" << endl;
	cout << "5) Exit" << endl;
}



/*******************************************************************************
**			Menu::userInput()
** Description:	This function collects user input and validates it.
*******************************************************************************/

int Menu::userInput()
{
	int num;
	
	string n = "Enter a number: ";

	//Integer input validation
	num = intValidation(n);
	
	return num;

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


/*******************************************************************************
**			int Menu::intValidation(string)
** Description:	This function serves as input validation for integers. I
**		references SkyeShatter's YouTube video at:
**		https://youtube.com/watch?v=S3_jCTb3fm0  , as well as @86 on
**		Piazza.
*******************************************************************************/

int Menu::intValidation(string s)
{
	string str;
	int valid;
	bool flag = false;

	while(flag == false)
	{
		cout << s << endl;
		getline(cin, str);
		stringstream ss(str);

		if (ss >> valid && !(ss >> str)) //Referenced Piazza @86
		{
			flag = true;
		}

		else
		{
			cout << ">>> Please enter an integer only <<< " << endl;
			cout << endl;
		}

	}
	

	return valid;
}
