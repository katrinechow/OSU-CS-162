/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: loser.cpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the implementation file for class Loser. It
**		defines the various functions that will add and remove nodes to
**		a stack-style linked list. It also has functions to check if list
**		is empty, as well as to display the current list.
*******************************************************************************/
#include <iostream>

#include "character.hpp"
#include "loser.hpp"
#include "node.hpp"

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**				Loser::Loser
** Description:	This is the default constructor, which sets the head pointer
**		to the first node of the list.
*******************************************************************************/
Loser::Loser()
{
	//If list is empty, point head to NULL
	head = nullptr;
	tail = nullptr;
}


/*******************************************************************************
**				Loser::~Loser
** Description:	This is the destructor of class Loser. 
*******************************************************************************/
Loser::~Loser(void)
{
	if(isEmpty())
	{
		delete head;
		delete tail;
	}
	else
	{
		//References Gaddis Text pp 1046
		//nptr points to tail
		QueueNode* nptr = head;

		while(nptr != nullptr) //while there are non-empty nodes
		{
			QueueNode* erase; //Create a temp ptr to process node
			erase = nptr;
			nptr = nptr->next; //moves nptr backwards
			delete erase; //Bye bye node!
		}
		delete nptr;
		nptr = nullptr;
	}
}


/*******************************************************************************
**				Loser::isEmpty()
** Description:	This function checks to see if the stack is currently empty.
*******************************************************************************/
bool Loser::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}



/*******************************************************************************
**			Loser::push(Character*)
** Description:	This function adds a new node to the back of the list
*******************************************************************************/
void Loser::push(Character* c)
{

	//References Gaddis text pp.1045
	//If list is currently empty
	if (isEmpty())
	{
		//Sets head pointer to new node
		tail = new QueueNode(c);
		head = tail;
	}
	else
	{
		//References Gaddis text pp.1045
		QueueNode* temp = new QueueNode(c);
		
		head->prev = temp;
		temp->next = head;
		head = temp;
	}

}



/*******************************************************************************
**			Loser::printPile()
** Description:	This function displays the current fighters in the queue.
*******************************************************************************/
void Loser::printPile()
{
	if(isEmpty())
	{
		cout << "Loser pile is empty." << endl;
	}

	else
	{
		QueueNode* nptr;
		nptr = head;
	
		while(nptr != nullptr)
		{

			Character* temp;
			temp = nptr->fighter;
			cout << temp->getName() << " ";

			nptr = nptr->next;
			
		}

	
		cout << endl;
	}

}
