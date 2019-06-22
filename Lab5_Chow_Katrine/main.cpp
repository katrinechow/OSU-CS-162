/*******************************************************************************
** Program Name: Lab 5 - Recursive Functions: main.cpp
** Author: Katrine Chow
** Date: February 6, 2018
** Description:	Here is the main/client code for the recursion program. Users
**		are asked to select 1 out of 3 functions to perform. Once the
**		function completes, the program will loop back to the start menu
**		to see if user would like to continue.
*******************************************************************************/
#include <iostream>
#include <string>

#include "recursion.hpp"
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;

using std::getline;

using namespace Menu;
using namespace Recursion;

int main()
{
	const char MENU1MAX = '4';
	char ch = '0';


	do{
	
		//Display first menu
		Menu::displayMenu1();
		char choice = Menu::getChoice(MENU1MAX);

		//Choice 4 to quit the program
		switch (choice)
		{
			case '1':
			{	
				displayMenu2();
				break;
			}
			case '2':
			{
				displayMenu3();
				break;
			}
			case '3':
			{
				displayMenu4();
				break;
			}
			case '4':
				return 0;
		}

		cout << "\n";

	}while(ch == '0');
		

	return 0;

}
