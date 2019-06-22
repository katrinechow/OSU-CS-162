/*******************************************************************************
** Program Name: Project 3 - Fantasy Combat Game: medusa.hpp
** Author: Katrine Chow
** Date: February 12, 2018
** Description:	This is the header file for class Medusa, which inherits from
**		base class Character. Medusa has its own attack and defense
**		attributes.
*******************************************************************************/
#include "character.hpp"

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa : public Character
{
	public:
		Medusa();
		int Attack(Character*) override;
		void Defense(Character*, int) override;


};
#endif
