/*******************************************************************************
** Program Name: Final Project = Text-based Game: menu.hpp
** Author: Katrine Chow
** Date:March 15, 2018
** Description:	This is the header file for namespace Menu, to be used to gather
**		user options in the circular program.
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
	char getChoice(char);	
	int intValidation(string s);
}
#endif
