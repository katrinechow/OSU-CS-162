/*******************************************************************************
** Program Name: Project 3 - Fantasy Combat Game: bluemen.hpp
** Author: Katrine Chow
** Date: February 12, 2018
** Description:	This is the header file for class Bluemen, which inherits from
**		base class Character. BlueMen has its own attack and defense
**		attributes.
*******************************************************************************/
#include "character.hpp"

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Character
{
	private:
		int dicecount = 0;

	public:
		BlueMen();
		int Attack(Character*) override;
		void Defense(Character*, int) override;
		int getDiceCount();
		void setDiceCount();


};
#endif
