/*******************************************************************************
** Program Name: Project 3 - Fantasy Combat Game: vampire.hpp
** Author: Katrine Chow
** Date: February 12, 2018
** Description:	This is the header file for class Vampire, which inherits from
**		base class Character. Vampire has its own attack and defense
**		attributes.
*******************************************************************************/
#include "character.hpp"

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Vampire : public Character
{
	public:
		Vampire();
		int Attack(Character*) override;
		void Defense(Character*, int) override;


};
#endif
