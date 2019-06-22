/*******************************************************************************
** Program Name: Lab 5 - Recursive Functions: menu.hpp
** Author: Katrine Chow
** Date:February 6, 2018
** Description:	This is the header file for namespace Menu, to be used to gather
**		user options in the recursion program.
**		Menu inspired by Gaddis text pp.472 - 474
*******************************************************************************/
#include <string>

using std::string;

#ifndef MENU_HPP
#define MENU_HPP

//Namespace Menu declaration
namespace Menu
{

	void displayMenu1();
	void displayMenu2();
	void displayMenu3();
	void displayMenu4();
	void displayMenu5();
	char getChoice(char);	
	int intValidation(string s);
}
#endif
