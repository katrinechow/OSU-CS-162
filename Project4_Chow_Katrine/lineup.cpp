/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: lineup.cpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the implementation file for class Lineup. It
**		defines the various functions that will add and remove nodes to
**		a queue-style linked list. It also has functions to check if list
**		is empty, as well as to display the current list.
*******************************************************************************/
#include <iostream>

#include "character.hpp"
#include "lineup.hpp"
#include "node.hpp"

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**				Lineup::Lineup
** Description:	This is the default constructor, which sets the head pointer
**		to the first node of the list.
*******************************************************************************/
Lineup::Lineup()
{
	//If list is empty, point head to NULL
	head = nullptr;
	tail = nullptr;
	size = 0;
	score = 0;
}


/*******************************************************************************
**				Lineup::~Lineup
** Description:	This is the destructor of class Lineup. 
*******************************************************************************/
Lineup::~Lineup(void)
{
	if(isEmpty())
	{
		delete head;
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
			nptr = nptr->next; //moves nptr to next node
			delete erase->fighter;
			delete erase; //Bye bye node!
		}
		delete nptr;
		nptr = nullptr;
	}
}


/*******************************************************************************
**				Lineup::isEmpty()
** Description:	This function checks to see if the queue is currently empty.
*******************************************************************************/
bool Lineup::isEmpty()
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
**			Lineup::getScore()
** Description:	This function returns the current team score.
*******************************************************************************/
int Lineup::getScore()
{
	return score;
}


/*******************************************************************************
**			Lineup::setScore(int)
** Description:	This function sets the current team score.
*******************************************************************************/
void Lineup::setScore(int s)
{
	score = score + s;
}


/*******************************************************************************
**			Lineup::getSize()
** Description: This function returns the size of the lineup.
*******************************************************************************/
int Lineup::getSize()
{
	return size;
}


/*******************************************************************************
**			Lineup::setSize(int)
** Description:	This function sets the size of the lineup.
*******************************************************************************/
void Lineup::setSize(int s)
{
	size = size + s;
}



/*******************************************************************************
**			Lineup::enqueue(Character*)
** Description:	This function adds a new node to the back of the list
*******************************************************************************/
void Lineup::enqueue(Character* c)
{
	//References Gaddis text pp.1045
	//If list is currently empty
	if (isEmpty())
	{
		//Sets head pointer to new node
		head = new QueueNode(c);
		tail = head;
	}
	else
	{
		//References Gaddis text pp.1045
		QueueNode* temp = new QueueNode(c);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}

}



/*******************************************************************************
**			Lineup::getFront()
** Description:	This function returns the Character at the head of the queue.
*******************************************************************************/
Character* Lineup::getFront()
{
	if(!isEmpty())
	{
		return head->fighter;
	}
	else
	{
		cout << "Team is empty" << endl;;
	}
}


/*******************************************************************************
**			Lineup::dequeue()
** Description: This function removes a node from the head of queue.
*******************************************************************************/
void Lineup::dequeue()
{
	//References Gaddis pp. 1045
	if (isEmpty())
	{
		cout << "Team is empty." << endl;
	}
	else
	{
		
		QueueNode* temp;
		//Points temp at head node
		temp = head;

		//Moves head pointer to the next node
		head = head->next;
		
		//Deletes temp
		delete temp;
		temp = nullptr;
	}
}



/*******************************************************************************
**			Lineup::printLineup()
** Description:	This function displays the current fighters in the queue.
*******************************************************************************/
void Lineup::printLineup()
{
	if(isEmpty())
	{
		cout << "Team is empty." << endl;
	}

	else
	{
		cout << "Current lineup: ";

		QueueNode* nptr = head;

		while(nptr != nullptr)
		{
			cout << (nptr->fighter)->getName() << " ";

			nptr = nptr->next;
		}
	
	
		cout << endl;
	}
}
