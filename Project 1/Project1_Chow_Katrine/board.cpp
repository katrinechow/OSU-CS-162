/*******************************************************************************
** Program Name: Project 1: Langton's Ant - board.cpp
** Author: Katrine Chow
** Date: January 15, 2018
** Description: This is the class Board implementation file. It defines the
**              member functions of the class, which create the board, prints
**              the board, and sets color of board tiles.
*******************************************************************************/

#include "board.hpp"
#include "ant.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;


/*******************************************************************************
**				Board::Board()
** Description:	This is the default constructor of class Board. It initializes
**		a 2x2 board if no user input is received.
*******************************************************************************/

Board::Board()
{
	char** ptr = new char*[2];
	for (int i = 0; i < 2; i++)
	{
		ptr[i] = new char[2];
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ptr[i][j] = ' ';
		}
	}

	setPointer(ptr);			
}



/*******************************************************************************
**			Board::Board(int, int)
** Description:	This function accepts a 2D array pointer for the board, and
**		user-specified number of rows and columns. It initializes the
**		game board using this information.
*******************************************************************************/

Board::Board(int col, int row)
{
	//Sets column and row number for this session	
	setColumn(col);
	setRow(row);

	//Dynamically allocate space for user defined board size
	char** newptr = new char*[row+2];
	
	for (int k = 0; k < row+2; k++)
	{
		newptr[k] = new char[col+2];
	}


	//Initializes board with white spaces
	for (int i = 0; i < row+2; i++)
	{	
		for (int j = 0; j < col+2; j++)
		{
			newptr[i][j] = ' ';
		}
	}


	//Sets up border
	for (int i = 0; i < row+1; i++)
	{
		for (int j = 0; j < col+2; j++)
		{
			newptr[i][0] = '|';
			newptr[i][col+1] = '|';
			newptr[0][j] = '-';
			newptr[row+1][j] = '-';
		}
	}
 

	//Sets board pointer for this session
	setPointer(newptr);

}


/*******************************************************************************
**			Board::setPointer(char**)
** Description: This function sets the board pointer.
*******************************************************************************/

void Board::setPointer(char** ptr)
{
	bptr = ptr;
}


/*******************************************************************************
**			Board::getPointer()
** Description: This function gets the board pointer.
*******************************************************************************/

char** Board::getPointer()
{
	return bptr;
}



/*******************************************************************************
**			Board::setColumn(int)
** Description:	This function sets the board columns as specified by user.
*******************************************************************************/

void Board::setColumn(int col)
{
	boardc = col;
}


/*******************************************************************************
**			Board::getColumn(int)
** Description:	This function gets the board column number.
*******************************************************************************/

int Board::getColumn()
{
	return boardc;
}


/*******************************************************************************
**			Board::setRow(int)
** Description:	Thisfunction sets the board rows as specified by user.
*******************************************************************************/

void Board::setRow(int row)
{
	boardr = row;
}



/*******************************************************************************
**			Board::getRow()
** Description:	This function gets the board row number.
*******************************************************************************/

int Board::getRow()
{
	return boardr;
}


	
/*******************************************************************************
**			Board::printBoard()
** Description:	This function prints board to output.
*******************************************************************************/

void Board::printBoard(char** ptr)
{
	int col = getColumn();
	int row = getRow();

	for (int i = 0; i < row+2; i++)
	{
		for (int j = 0; j < col+2; j++)
		{
			cout << ptr[i][j];			
		}
		cout << endl;
	}
}


/*******************************************************************************
**			Board::deleteBoard()
** Description: This function frees the dynamically allocated board in memory.
*******************************************************************************/

void Board::deleteBoard(char** bptr)
{
	int boardc = getColumn();
	int boardr = getRow();

	for(int i = 0; i < boardc; i++)
	{
		delete [] bptr[i];
	}
	
	delete [] bptr;
	bptr = nullptr;
}
