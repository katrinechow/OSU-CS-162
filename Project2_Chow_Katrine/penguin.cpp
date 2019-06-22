/*******************************************************************************
** Program Name: Project 2 - Zoo Tyocoon: penguin.cpp
** Author: Katrine Chow
** Date: Januar 30, 2018
** Description:	This is the header file for class Penguin, which defines its own
**		member variables and functions.
*******************************************************************************/

#include <iostream>

#include "animal.hpp"
#include "penguin.hpp"

/*******************************************************************************
**				Penguin::Penguin()
** Description:	This is the default constructor of class Penguin. It initializes
**		a penguin's attributes.
*******************************************************************************/
Penguin::Penguin()
{
	age = 1;
	cost = 1000;
	numberofbabies = 5;
	basefoodcost = 10;
	payoff = cost * 0.1;
}

