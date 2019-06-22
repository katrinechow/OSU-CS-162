/*******************************************************************************
** Program Name: Lab 6 - Doubly-Linked List: node.hpp
** Author: Katrine CHow
** Date: February 12, 2018
** Description:	This is the header file for class Node, which contains a value,
**		a pointer to a previous node, and a pointer to the next node.
*******************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

class Node
{
	private:
		int Val;
		Node* prev = nullptr;
		Node* next = nullptr;

	public:
		Node(); //Default Constructor
		Node(int);
		void setVal(int);
		int getVal();
		void setPrev(Node*);
		Node* getPrev();
		void setNext(Node*);
		Node* getNext();

};
#endif
