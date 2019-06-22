/*******************************************************************************
** Program Name: Lab 7 - Circular Linked List: queue.hpp
** Author: Katrine Chow
** Date: February 22, 2018
** Description:	This is the header file for class Queue, which contains
**		function prototypes of class DoublyLinked.
*******************************************************************************/
#include "node.hpp"

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
	private:
		QueueNode* head; //Creates head pointer

	public:
		Queue(); //Default constructor
		~Queue(); //Destructor
		bool isEmpty();
		void addBack(int);
		int getFront();
		void removeFront();
		void printQueue();
};
#endif
