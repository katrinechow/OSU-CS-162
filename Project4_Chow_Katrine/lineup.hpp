/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: lineup.hpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the header file for class Lineup, which contains
**		function prototypes and data members that identifies each
**		fighter in the tournament.
*******************************************************************************/
#include "node.hpp"

#ifndef LINEUP_HPP
#define LINEUP_HPP

class Lineup
{
	private:
		QueueNode* head; //Creates head pointer
		QueueNode* tail; //Creates tail pointer
		int size;
		int score;
	public:
		Lineup(); //Default constructor
		~Lineup(); //Destructor
		bool isEmpty();
		QueueNode* getHead();
		QueueNode* getTail();
		void setScore(int);
		int getScore();
		void setSize(int);
		int getSize();
		void enqueue(Character*);
		Character* getFront();
		void dequeue();
		void Recover();
		void printLineup();
};
#endif
