/*******************************************************************************
** Program Name: Project 3 - Fantasy Combat Game: barbarian.hpp
** Author: Katrine Chow
** Date: February 12, 2018
** Description:	This is the header file for class Barbarian, which inherits from
**		base class Character. Barbarian has its own attack and defense
**		attributes.
*******************************************************************************/
#include "character.hpp"

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian : public Character
{
	public:
		Barbarian();
		int Attack(Character*) override;
		void Defense(Character*, int) override;


};
#endif
