/*******************************************************************************
** Program Name: Project 2 - Zoo Tycoon: turtle.cpp
** Author: Katrine Chow
** Date: January 30, 2018
** Description:	This is the implementation file for class Turtle. It defines the
**		member variables and functions associated with this animal.
*******************************************************************************/

#include <iostream>

#include "animal.hpp"
#include "turtle.hpp"

/*******************************************************************************
**				Turtle::Turtle()
** Description:	This is the default constructor of class Turtle. It initializes
**		a turtle's attributes.
*******************************************************************************/
Turtle::Turtle()
{
	age = 1;
	cost = 100;
	numberofbabies = 10;
	basefoodcost = basefoodcost * 0.5;
	payoff = cost * 0.05;
}
