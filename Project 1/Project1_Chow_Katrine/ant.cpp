/*******************************************************************************
** Program name: Project 1: Langton's Ant - ant.cpp
** Author: Katrine Chow
** Date: January 15, 2018
** Description: This is the class Ant implementation file. It defines the class
**              member functions that set and get the ant's location and
**              orientation.
*******************************************************************************/

#include "ant.hpp"
#include "board.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**				Ant::Ant()
** Description:	This is the default constructor for the Ant class. It 
**		initializes the ant's location if none are specified.
*******************************************************************************/

Ant::Ant()
{
	longitude = 1;
	latitude = 1;
	
	char ant = '*';

	antptr[longitude][latitude] = ant;

	setOrientation(0);
}


/*******************************************************************************
**			Ant::Ant(int, int, char**, int, int)
** Description:	This initializes the ant with user-specified location.
*******************************************************************************/

Ant::Ant(int col, int row, char** bptr, int boardc, int boardr)
{
	//Sets Ant's pointer to the new game board
	setPointer(bptr);

	//Gets copy of board sizes
	getCoord(boardc, boardr);

	//Initializes with user specified location
	setLocation(col, row);

	antptr[col][row] = '*';

	//Initialize ant's orientation to North
	setOrientation(0);

	//Allocate color grid
	colorptr = new bool*[row+2];

	for (int k = 0; k < row+2; k++)
	{
		colorptr[k] = new bool[col+2];
	}

	//Initialize color grid to all true/white
	for (int i = 0; i < row+2; i++)
	{
		for (int j = 0; j < col+2; j++)
		{
			colorptr[i][j] = true;
		}
	}
	
}


/*******************************************************************************
**				Ant::setPointer(char**)
** Description:	This function receives pointer to the newly generated game
**		board and sets Ant class' own pointer to it.
*******************************************************************************/

void Ant::setPointer(char** bptr)
{
	//Sets Ant's pointer to the game board
	antptr = bptr;
}


/*******************************************************************************
**				Ant::getCoord(int, int)
** Description:	This function receives board size
*******************************************************************************/

void Ant::getCoord(int bcol, int brow)
{
	//Stores a copy of the Board's columns and rows
	boardcol = bcol;
	boardrow = brow;

}


/*******************************************************************************
**				Ant::setLocation(int, int)
** Description:	This function sets the location of the ant for each move.
*******************************************************************************/

void Ant::setLocation(int col, int row)
{
	//Location of the ant
	longitude = col;
	latitude = row;
		
}


/*******************************************************************************
** 				Ant::moveAnt()
** Description:	This function moves the ant according to Langton's Ant rules.
*******************************************************************************/

void Ant::moveAnt()
{

		if(colorptr[longitude][latitude] == false)
		{
			//Change tile to white
			if(getOrientation() == 0)
			{
				setOrientation(2);
			}
			else if (getOrientation() == 3)
			{
				setOrientation(1);
			}
			else if (getOrientation() == 2)
			{
				setOrientation(0);
			}
			else if (getOrientation() == 1)
			{
				setOrientation(3);
			}

			moveLeft();
		}

		else if (colorptr[longitude][latitude] == true)
		{
			//Because orientation is set at the end of each move,
			//need to turn ant 180 degrees before continuing.
			//This solves the conflict of ant not turning correctly
			//when changing from left to right turn and vice versa.
			if(flag)
			{
				if(getOrientation() == 0)
				{
					setOrientation(2);
				}
		
				else if (getOrientation() == 1)
				{
					setOrientation(3);
				}

				else if (getOrientation() == 2)
				{
					setOrientation(0);
				}
		
				else if (getOrientation() == 3)
				{
					setOrientation(1);
				}
			}

			//Change tile to black
			moveRight();
			flag = false;
		}


		antptr[longitude][latitude] = '*';
//	}

//	else
//	{
//		changeOrientation();
//	}
}



/*******************************************************************************
**				Ant::getLocation()
** Description:	This function gets the location of the ant.
*******************************************************************************/

char** Ant::getLocation()
{
	return antptr;
}



/*******************************************************************************
**				Ant::setOrientation(Direction)
** Description: This function receives an enum which tells which direction
**		the ant is facing.
*******************************************************************************/

void Ant::setOrientation(int dir)
{
	orientation = dir;
}



/*******************************************************************************
**				Ant::getOrientation()
** Description:	This function returns the current orientation the ant is facing.
*******************************************************************************/

int Ant::getOrientation()
{
	return orientation;
}


/*******************************************************************************
**				Ant::changeOrientation()
** Description:	This function changes the orientation of the ant.
*******************************************************************************/

void Ant::changeOrientation()
{
	if (getOrientation() == 0)
	{
		setOrientation(2);
	}

	else if (getOrientation() == 1)
	{
		setOrientation(3);
	}

	else if (getOrientation() == 2)
	{
		setOrientation(0);
	}

	else if (getOrientation() == 3)
	{
		setOrientation(1);
	}

}



/*******************************************************************************
**				Ant::moveLeft()
** Description:	This function changes the ant's orientation and moves it to left
*******************************************************************************/

void Ant::moveLeft()
{

	if(longitude >= 1 && longitude <= boardcol && latitude >= 1 && 
		latitude <= boardrow)
	{
	
		if (getOrientation() == 0)
		{
			colorptr[longitude][latitude] = true;
			antptr[longitude][latitude] = ' ';
			setLocation(longitude - 1, latitude);
			setOrientation(3);
		}
		else if (getOrientation() == 3)
		{
			colorptr[longitude][latitude] = true;
			antptr[longitude][latitude] = ' ';
			setLocation(longitude, latitude - 1);
			setOrientation(2);
		}

		else if (getOrientation() == 2)
		{
			colorptr[longitude][latitude] = true;
			antptr[longitude][latitude] = ' ';
			setLocation(longitude + 1, latitude);
			setOrientation(1);
		}

		else if (getOrientation() == 1)
		{
			colorptr[longitude][latitude] = true;
			antptr[longitude][latitude] = ' ';
			setLocation(longitude, latitude + 1);
			setOrientation(0);
		}

	}
	

	else
	{
		changeOrientation();
	}

	flag = true;
}



/*******************************************************************************
**				Ant::moveRight()
** Description:	This function changes the ant's orientation to the right.
*******************************************************************************/

void Ant::moveRight()
{

	if (longitude >=1 && longitude <= boardcol && latitude >= 1 && 
		latitude <= boardrow)
	{

		if (getOrientation() == 0)
		{
			colorptr[longitude][latitude] = false;
			antptr[longitude][latitude] = '#';
			setLocation(longitude - 1, latitude);
			setOrientation(1);
		}

		else if (getOrientation() == 1)
		{
			colorptr[longitude][latitude] = false;
			antptr[longitude][latitude] = '#';
			setLocation(longitude, latitude + 1);
			setOrientation(2);
		}
		else if (getOrientation() == 2)
		{
			colorptr[longitude][latitude] = false;
			antptr[longitude][latitude] = '#';
			setLocation(longitude + 1, latitude);
			setOrientation(3);
		}
		else if (getOrientation() == 3)
		{
			colorptr[longitude][latitude] = false;
			antptr[longitude][latitude] = '#';
			setLocation(longitude, latitude - 1);
			setOrientation(0);
		
		}

	}
	
	else
	{
		changeOrientation();
	}
}


/*******************************************************************************
**				Ant::deleteBoard()
** Description:	This functions deallocates the colorptr array
*******************************************************************************/

void Ant::deleteBoard()
{
	for (int i = 0; i < boardcol; i++)
	{
		delete [] colorptr[i];
	}

	delete [] colorptr;
	colorptr = nullptr;
}	
