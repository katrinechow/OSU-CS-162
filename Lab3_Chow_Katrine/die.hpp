/*******************************************************************************
** Program Name: Lab 3: War Game (dice): die.hpp
** Author: Katrine Chow
** Date: January 27, 2018
** Description:	This is the header file for the Die class. It declares member
**		variables and class functions that controls the behavior of a
**		regular die.
*******************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
	protected:
		int N = 0; //sides of die

	public:
		Die(); //Default constructor
		Die(int);
		int getSides(); //returns current N value
		virtual int returnRoll(); //returns random number from 1 through N



};

#endif
