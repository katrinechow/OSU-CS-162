/*******************************************************************************
** Program Name: Lab 3 - War Game (dice): loadeddie.hpp
** Author: Katrine Chow
** Date: January 27, 2018
** Description:	This is the header file of the loadedDie class, which declares
**		the member variables and functions that control the behavior of
**		a loaded die.
*******************************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "die.hpp"

class loadedDie: public Die
{
	public:
		loadedDie(); //Default constructor
		loadedDie(int N);
		int returnRoll() override;


};

#endif
