/*******************************************************************************
** Program Name: Lab 3 - War Game (dice): loadeddie.cpp
** Author: Katrine Chow
** Date: January 27, 2018
** Description:	This is the implementation file for the loadedDie class. This
**		defines the member functions associated with a loaded die.
*******************************************************************************/

#include <iostream>
#include <cmath>

#include "die.hpp"
#include "loadeddie.hpp"

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**				loadedDie::loadedDie()
** Description:	This is the default constructor of the loadedDie class. It
**		initializes a loaded die with 3 sides.
*******************************************************************************/

loadedDie::loadedDie(): Die(N)
{
	N = 3;
}


/*******************************************************************************
**				loadedDie::loadedDie(int)
** Description:	This constructor takes a user-specified number of sides and
**		sets private variable loadedn to that number.
*******************************************************************************/

loadedDie::loadedDie(int sides): Die(N)
{
	N = sides;
}


/*******************************************************************************
**				loadedDie::returnRoll()
** Description:	This function defines a loaded die's roll, which would result
**		in higher than average results than a regular die with the same
**		number of sides.
*******************************************************************************/

int loadedDie::returnRoll()
{

	int num = (rand() % N + 1) * 30; //3 because min 3 sided-die

	//Random number cannot be larger than number of sides
	if (num > N)
	{
		return N;
	}

	else
	{
		return num;
	}

}
