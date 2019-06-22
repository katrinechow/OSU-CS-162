/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: harrypotter.hpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the header file for class Harry Potter, which inherits
**		from base class Character. Harry Potter has his own attack and
**		defense attributes.
*******************************************************************************/
#include "character.hpp"

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter : public Character
{
	private:
		int hearts;

	public:
		HarryPotter();
		int Attack(Character*) override;
		void Defense(Character*, int) override;


};
#endif
