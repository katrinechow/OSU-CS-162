/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: loser.hpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the header file for class loser, which is a stack
**		container that holds losing fighters.
*******************************************************************************/
#include "node.hpp"

#ifndef LOSER_HPP
#define LOSER_HPP

class Loser
{
	private:
		QueueNode* head; //Creates head pointer
		QueueNode* tail; //Creates tail pointer
	public:
		Loser(); //Default constructor
		~Loser(); //Destructor
		bool isEmpty();
		void push(Character*);
		void printPile();
};
#endif
