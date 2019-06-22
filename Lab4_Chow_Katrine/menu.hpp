/*******************************************************************************
** Program Name: Lab 4 - OSU Information System: menu.hpp
** Author: Katrine Chow
** Date: January 30, 2018
** Description:	This is the header file for namespace Menu, to be used to gather
**		user options in the osu program.
**		Menu inspired by Gaddis text pp.472 - 474
*******************************************************************************/
#include "person.hpp"
#include <vector>

using std::vector;

#ifndef MENU_HPP
#define MENU_HPP

//Namespace Menu declaration
namespace Menu
{

	void displayMenu1();
	void displayMenu2(vector<Person*>);
	char getChoice(char);	

}
#endif
