/*******************************************************************************
** Program Name: Lab 6 - Doubly-Linked List: doublylinked.cpp
** Author: Katrine Chow
** Date: February 12, 2018
** Description:	This is the implementation file for class Doubly Linked. It
**		defines the various functions that will add and remove nodes to
**		a doubly-linked list. It also has functions to traverse and
**		reverse traverse the list.
*******************************************************************************/
#include <iostream>

#include "doublylinked.hpp"
#include "node.hpp"

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**				DoublyLinked::DoublyLinked
** Description:	This is the default constructor, which sets the head pointer
**		to the first node of the list.
*******************************************************************************/
DoublyLinked::DoublyLinked()
{
	//If list is empty, point head and tail to NULL
	head = nullptr;
	tail = nullptr;
}


/*******************************************************************************
**				DoublyLinked::~DoublyLinked
** Description:	This is the destructor of class DoublyLinked. 
*******************************************************************************/
DoublyLinked::~DoublyLinked(void)
{
	//References Gaddis Text pp 1046
	Node* nptr = head;

	while(nptr != nullptr) //while there are non-empty nodes
	{
		Node* erase = nptr; //Create a temp Node ptr to process node
		nptr = nptr->getNext(); //moves nptr to the next node
		delete erase; //Bye bye node!
	}

}


/*******************************************************************************
**			DoublyLinked::addNodeHead(int)
** Description:	This function adds a new node to the head of the list
*******************************************************************************/
void DoublyLinked::addNodeHead(int value)
{

	//References Gaddis text pp.1045
	//If list is currently empty
	if (head == nullptr)
	{
		//Sets head pointer to new node
		head = new Node(value);
		tail = head;
	}
	else
	{

		//References Gaddis text pp.1045
		Node* nptr = head;
		
		while(nptr->getPrev() != nullptr)
		{
			//Keep going back until reaches head of list
			nptr = nptr->getPrev();
		}

		//If there is more than 1 element in list
		//Create new node before current node
		nptr->setPrev(new Node(value));
		
		//set head pointer to the new node
		head = nptr->getPrev();
		//set next pointer to the original node
		head->setNext(nptr);
	}


	//Call function 6
	displayList();
}


/*******************************************************************************
**			DoublyLinked::addNodeTail(int)
** Description:	This function adds a new node to the tail end of the list.
*******************************************************************************/
void DoublyLinked::addNodeTail(int value)
{
	//If list is currently empty
	if (head == nullptr)
	{
		head = new Node(value);
		tail = head;
	}
	else
	{	
		//nptr will move through list to check for end/nullptr
		Node* nptr = head;

		while(nptr->getNext() != nullptr)
		{
			nptr = nptr->getNext();
		}

		nptr->setNext(new Node(value));
		tail = nptr->getNext();
		tail->setPrev(nptr);
	}

	//Call function 6
	displayList();
}	


/*******************************************************************************
**			DoublyLinked::removeNodeHead()
** Description: This function removes a node from the beginning of list.
*******************************************************************************/
void DoublyLinked::removeNodeHead()
{
	//References Gaddis pp. 1045
	if (head == nullptr)
	{
		cout << "List is already empty." << endl;
	}
	//If there is only 1 element in list
	else if (head->getNext() == nullptr)
	{
		Node* temp;
		temp = head;
		head = nullptr;
		delete temp;
	}
	else
	{
		Node* temp;
		//Points temp at head node
		temp = head;

		//Moves head pointer to the next node
		head = head->getNext();

		//Set current head->getPrev() to null
		head->setPrev(nullptr);
		
		//Deletes temp
		delete temp;
	

		//Call function 6
		displayList();
	}
}


/*******************************************************************************
**			DoublyLinked::removeNodeTail()
** Description:	This function removes a node from the end of list.
*******************************************************************************/
void DoublyLinked::removeNodeTail()
{
	if (head == nullptr)
	{
		cout << "List is already empty." << endl;
	}
	//When there is only 1 element in list
	else if (head->getNext() == nullptr)
	{
		Node* temp;
		temp = head;
		head = nullptr;
		delete temp;
	}
	else
	{
		Node* temp;
		//Points temp at tail node
		temp = tail;

		//Moves tail pointer to the previous node
		tail = tail->getPrev();

		//Set current tail->getNext() to null
		tail->setNext(nullptr);

		//Deletes temp
		delete temp;
	

		//Call function 6
		displayList();
	}
}


/*******************************************************************************
**			DoublyLinked::printHValue()
** Description:	This function returns the current value of the node that the
**		head pointer is pointing to.
*******************************************************************************/
void DoublyLinked::printHValue()
{

	if(head == nullptr)
	{
		cout << "The List is Empty!" << endl;
	}
	else
	{
		cout << "Value at Head is: " <<  head->getVal() << endl;
	}
}


/*******************************************************************************
**			DoublyLinked::printTValue()
** Description:	This function returns the current value of the node that the
**		tail pointer is pointing to.
*******************************************************************************/
void DoublyLinked::printTValue()
{
	if(head == nullptr)
	{
		cout << "The List is Empty!" << endl;
	}
	else
	{
		cout << "Value at Tail is: " <<  tail->getVal() << endl;
	}
}


/*******************************************************************************
**			DoublyLinked::reverseList()
** Description:	This function prints the entire List from tail to head.
*******************************************************************************/
void DoublyLinked::reverseList()
{

	if(head == nullptr)
	{
		cout << "List is empty. Feed it first!" << endl;
	}

	else
	{
		//Starts at the end of list
		Node* nptr = tail;

		cout << "Reversed List is: ";

		//References Gaddis text pp. 1045
		while (nptr)
		{
			cout << nptr->getVal() << " ";
			nptr = nptr->getPrev();
		}
		cout << endl;
	}
}


/*******************************************************************************
**			DoublyLinked::displayList()
** Description:	This function displays the entire list from head to tail.
*******************************************************************************/
void DoublyLinked::displayList()
{

	if(head == nullptr)
	{
		cout << "List is empty." << endl;
	}

	else
	{
		Node* nptr = head;
	
		cout << "Current list: ";
	
		while (nptr)
		{
			//Prints the value of current node
			cout << nptr->getVal() << " ";
			//Move onto the next node
			nptr = nptr->getNext();
		}
		cout << endl;
	}
}
