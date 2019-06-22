/*******************************************************************************
** Program Name: Project 1: Langton's Ant - ant.hpp
** Author: Katrine Chow
** Date: January 15, 2018
** Description: This is the class Ant specification file. It declares class
**              member variables and functions related to setting and getting
**              the location and orientation of the ant.
*******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "board.hpp"

//Ant class declaration
class Ant
{
	private:
		int longitude = 0;
		int latitude = 0;
		int boardcol = 0;
		int boardrow = 0;
		char** antptr = nullptr;
		int orientation = 0;
		bool currentcolor = true;
		bool** colorptr = nullptr;
		bool flag = false;
	
	public:
		Ant(); //Default constructor
		Ant(int, int, char**, int, int);
		void setPointer(char**);
		void getCoord(int, int);
		void setLocation(int, int);
		char** getLocation();
		void setOrientation(int);
		int getOrientation();
		void changeOrientation();
		void moveLeft();
		void moveRight();
		void moveAnt();
		void deleteBoard();

};
#endif
