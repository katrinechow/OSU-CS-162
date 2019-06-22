/*******************************************************************************
** Program Name: Project 2 - Zoo Tycoon: tiger.cpp
** Author: Katrine Chow
** Date: January 30, 2018
** Description:	This is the implementation file for class Tiger, which defines
**		the specific member variables and functions for this class.
*******************************************************************************/

#include "animal.hpp"
#include "tiger.hpp"

/*******************************************************************************
**				Tiger::Tiger()
** Description:	This is the default constructor of class Tiger. It initializes
**		a tiger's attributes.
*******************************************************************************/
Tiger::Tiger()
{
	age = 1;
	cost = 10000;
	numberofbabies = 1;
	basefoodcost = basefoodcost * 5;
	payoff = cost * 0.2;
}
