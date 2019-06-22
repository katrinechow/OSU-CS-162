/*******************************************************************************
** Program Name: Lab 5 - Recursive Functions: menu.cpp
** Author: Katrine Chow
** Date: February 6, 2018
** Description:	This is the implementation file for namespace menu, which builds
**		a menu interface for the recursion program.
*******************************************************************************/

#include "menu.hpp"
#include "recursion.hpp"
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
using namespace Recursion;

/*******************************************************************************
**				Menu::displayMenu1()
** Description:	This function displays a user interface with choices.
*******************************************************************************/

void Menu::displayMenu1()
{
	cout << "Choose a function: " << endl;
	cout << "1) Print a String in Reverse" << endl;
	cout << "2) Sum of Integers" << endl;
	cout << "3) Find the Triangular Number" << endl;
	cout << "4) Exit" << endl;
}


/*******************************************************************************
**				Menu::displayMenu2()
** Description:	This displays a sub-menu for function 1. Asks users to input
**		a string to be processed.
*******************************************************************************/

void Menu::displayMenu2()
{
	string input;
	cout << "Enter a string: " << endl;
	getline(cin, input);

	Recursion::runFunction1(input);
	cout << endl;

}



/*******************************************************************************
**			Menu::displayMenu3()
** Description:	This function displays a sub-menu for function 2. Asks user to
**		input size of array and to fill it with integers.
*******************************************************************************/

void Menu::displayMenu3()
{
	int size;
	
	string s = "Enter the size of the integer array: ";

	size = intValidation(s);
	cout << "size is: " << size << endl;

	int* intarray = new int[size];

	for(int i = 0; i < size; i++)
	{
		int validint;
		string str = "Enter an integer: ";
		validint = intValidation(str);
		intarray[i] = validint;
	
	}

	cout << "Sum is: " << Recursion::runFunction2(intarray, size) << endl;

	//Deallocate
	delete[] intarray;
	intarray = nullptr;

}


/*******************************************************************************
**			Menu::displayMenu4()
** Description:	This function displays a sub-menu for function 3. Asks user to
**		enter an integer.
*******************************************************************************/

void Menu::displayMenu4()
{
	int N;

	string s = "Enter an integer: ";

	N = intValidation(s);

	cout << "Triangular number is: " << Recursion::runFunction3(N) << endl;
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
