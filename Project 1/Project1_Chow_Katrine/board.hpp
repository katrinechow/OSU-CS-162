/*******************************************************************************
** Program Name: Project 1: Langton's Ant - board.hpp
** Author: Katrine Chow
** Date: January 15, 2018
** Description: This is the Board class specification file. It declares class
**              member variables and functions related to the creation and
**              changes to the Langton's Ant game board.
*******************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

//Board class declaration
class Board
{
	private:
		char** bptr = nullptr;
		int boardc = 0;
		int boardr = 0;	

	public:
		Board(); //Default constructor
		Board(int, int);
		void setPointer(char**);
		char** getPointer();
		void setColumn(int);
		int getColumn();
		void setRow(int);
		int getRow();
		void printBoard(char**);
		void deleteBoard(char**);
};
#endif
