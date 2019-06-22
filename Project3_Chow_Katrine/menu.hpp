/*******************************************************************************
** Program Name: Project 3 - Fantasy Combat Game: menu.hpp
** Author: Katrine Chow
** Date: February 12, 2018
** Description:	This is the header file for namespace Menu, to be used to gather
**		user options in the osu program.
**		Menu inspired by Gaddis text pp.472 - 474
*******************************************************************************/
#include "character.hpp"

#ifndef MENU_HPP
#define MENU_HPP

//Namespace Menu declaration
namespace Menu
{

	void displayMenu1();
	void displayMenu2();
	void displayMenu3();
	char getChoice(char);	
	int play();
	void displayStats(Character*, Character*);

}
#endif
