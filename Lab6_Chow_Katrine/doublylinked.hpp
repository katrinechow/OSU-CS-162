/*******************************************************************************
** Program Name: Lab 6 - Doubly-Linked List; doublylinked.hpp
** Author: Katrine Chow
** Date: February 12, 2018
** Description:	This is the header file for class DoublyLinked, which contains
**		function prototypes of class DoublyLinked.
*******************************************************************************/
#include "node.hpp"

#ifndef DOUBLYLINKED_HPP
#define DOUBLYLINKED_HPP

class DoublyLinked
{
	private:
		Node* head; //Creates head pointer
		Node* tail; //Creates tail pointer

	public:
		DoublyLinked(); //Default constructor
		~DoublyLinked(); //Destructor
		void addNodeHead(int);
		void addNodeTail(int);
		void removeNodeHead();
		void removeNodeTail();
		void printHValue();
		void printTValue();
		void reverseList();
		void displayList();

};
#endif
