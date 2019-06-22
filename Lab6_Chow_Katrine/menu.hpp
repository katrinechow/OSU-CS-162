/*******************************************************************************
** Program Name: Lab 6 - Doubly-Linked List: menu.hpp
** Author: Katrine Chow
** Date:February 12, 2018
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
	int userInput();
	char getChoice(char);	
	int intValidation(string s);
}
#endif
