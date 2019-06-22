/*******************************************************************************
** Program Name: Lab 6 - Doubly-Linked List: node.cpp
** Author: Katrine Chow
** Date: February 12, 2018
** Description:	This is the implementation file for class Node, which defines
**		the pointers included in the class. Please note that this
**		program references skills learned in Chapter 17 of Tony Gaddis'
**		Textbook "Starting Out with C++: Early Objects 9th Edition"
*******************************************************************************/

#include "node.hpp"

/*******************************************************************************
**				Node::Node
** Description:	This is the default constructor of class Node. It initializes
**		the starting integer to 0.
*******************************************************************************/
Node::Node()
{
	setVal(0);
	setPrev(0);
	setNext(0);
}


/*******************************************************************************
**				Node::Node(int, Node*)
** Description: This constructor initializes value to the int parameter passed
**		in, sets the previous pointer to the node, and the next pointer
**		to the next node (nullptr). 
*******************************************************************************/
Node::Node(int input)
{
	//Referenced Gaddis Textbook pp.1040
	setVal(input);
	Node* nexttemp = nullptr;
	Node* prevtemp = nullptr;

	setNext(nexttemp);
	setPrev(prevtemp);
}


/*******************************************************************************
**				Node::setVal(int)
** Description:	This function sets the value of the node.
*******************************************************************************/
void Node::setVal(int v)
{
	Val = v;
}


/*******************************************************************************
**				Node::getVal()
** Description:	This functions returns the Value of the node.
*******************************************************************************/
int Node::getVal()
{
	return Val;
}


/*******************************************************************************
**				Node::setPrev(Node*)
** Description:	This function sets the node's prev pointer.
*******************************************************************************/
void Node::setPrev(Node* p)
{
	prev = p;
}


/*******************************************************************************
**				Node::getPrev()
** Description:	This function returns the node's prev pointer
*******************************************************************************/
Node* Node::getPrev()
{
	return prev;
}


/*******************************************************************************
**				Node::setNext(Node*)
** Description:	This function sets the node's next pointer.
*******************************************************************************/
void Node::setNext(Node* n)
{
	next = n;
}


/*******************************************************************************
**				Node::getNext()
** Description:	This function returns the node's next pointer.
*******************************************************************************/
Node* Node::getNext()
{
	return next;
}
