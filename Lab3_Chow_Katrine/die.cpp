/*******************************************************************************
** Program Name: Lab 3 -- War Game (dice): die.cpp
** Author: Katrine Chow
** Date: January 27, 2018
** Description:	This is the implementation file for the Die class, which
**		defines the member functions associated with a regular die.
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "die.hpp"

using std::cout;
using std::cin;
using std::endl;


/******************************************************************************
**				Die::Die()
** Description:	This is the default constructor of the Die class. It creates a
**		regular die of 3 sides.
*******************************************************************************/

Die::Die()
{
	N = 3;
}


/*******************************************************************************
**				Die::Die(int)
** Description:	This constructor takes user-specified die sides and records
**		this info to private variable N.
*******************************************************************************/

Die::Die(int sides)
{
	N = sides;
}


/*******************************************************************************
**				Die::getSides()
** Description:	This function gets user-specified number of sides.
*******************************************************************************/

int Die::getSides()
{
	return N;
}


/*******************************************************************************
**				Die::returnRoll()
** Description:	This function generates a random number between 1 and the number
**		of sides of the die.
*******************************************************************************/

int Die::returnRoll()
{
//	srand(time(0));

	int num =  rand() % N + 1;
	
	return num;
}
