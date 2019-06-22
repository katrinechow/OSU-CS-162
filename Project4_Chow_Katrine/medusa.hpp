/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: medusa.hpp
** Author: Katrine Chow
** Date: March 4, 2018
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
