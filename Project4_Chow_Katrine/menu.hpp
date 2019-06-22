/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: menu.hpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the header file for namespace Menu, to be used to gather
**		user options in the osu program.
**		Menu inspired by Gaddis text pp.472 - 474
*******************************************************************************/
#include "character.hpp"
#include "lineup.hpp"
#include "loser.hpp"

#ifndef MENU_HPP
#define MENU_HPP

//Namespace Menu declaration
namespace Menu
{

	void displayMenu1();
	void displayMenu2(Lineup&, Lineup&);
	void displayMenu3();
	void displayMenu4();
	void displayMenu5();
	char getChoice(char);	
	int intValidation(string);
	void play();
	void displayStats(Character*, Character*);

}
#endif
