/*******************************************************************************
** Program Name: Lab 7 - Circular Linked List: queue.cpp
** Author: Katrine Chow
** Date: February 22, 2018
** Description:	This is the implementation file for class Queue. It
**		defines the various functions that will add and remove nodes to
**		a circular linked list. It also has functions to check if list
**		is empty, as well as to display the current list.
*******************************************************************************/
#include <iostream>

#include "queue.hpp"
#include "node.hpp"

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**				Queue::Queue
** Description:	This is the default constructor, which sets the head pointer
**		to the first node of the list.
*******************************************************************************/
Queue::Queue()
{
	//If list is empty, point head to NULL
	head = nullptr;
}


/*******************************************************************************
**				Queue::~Queue
** Description:	This is the destructor of class Queue. 
*******************************************************************************/
Queue::~Queue(void)
{
	//Only 1 element
	if(isEmpty())
	{
		delete head;
	}
	else
	{
		//References Gaddis Text pp 1046
		//nptr points to tail
		QueueNode* nptr = head->prev;

		while(nptr != head) //while there are non-empty nodes
		{
			QueueNode* erase; //Create a temp ptr to process node
			erase = nptr;
			nptr = nptr->prev; //moves nptr backwards
			delete erase; //Bye bye node!
		}

		delete head;
	}
}


/*******************************************************************************
**				Queue::isEmpty()
** Description:	This function checks to see if the queue is currently empty.
*******************************************************************************/
bool Queue::isEmpty()
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
**			Queue::addBack(int)
** Description:	This function adds a new node to the back of the list
*******************************************************************************/
void Queue::addBack(int value)
{

	//References Gaddis text pp.1045
	//If list is currently empty
	if (isEmpty())
	{
		//Sets head pointer to new node
		head = new QueueNode(value);
		head->next = head; //To make this circular
		head->prev = head;
	}
	else
	{

		//References Gaddis text pp.1045
		QueueNode* nptr = head->prev; //head->prev would be the tail

		//If only 1 node / head->prev points to self
		if(nptr == head)
		{
			QueueNode* temp = new QueueNode(value);
			head->prev = temp;
			head->next = temp;
			temp->prev = head;
			temp->next = head;
		}
		else
		{
			//else nptr is pointer to last item in queue

			QueueNode* temp = new QueueNode(value);
			temp->next = head;
			head->prev = temp;
			temp->prev = nptr;
			nptr->next = temp;

		}
	}

}



/*******************************************************************************
**			Queue::getFront()
** Description:	This function returns the value at the head of the queue.
*******************************************************************************/
int Queue::getFront()
{
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		return head->Val;
	}
}


/*******************************************************************************
**			Queue::removeFront()
** Description: This function removes a node from the head of queue.
*******************************************************************************/
void Queue::removeFront()
{
	//References Gaddis pp. 1045
	if (isEmpty())
	{
		cout << "List is empty." << endl;
	}
	//If there is only 1 element in list
	else if (head->next == head && head->prev == head)
	{

		QueueNode* temp;
		temp = head;

		head = nullptr;

		delete temp;
	}
	else
	{
		//nptr points to end of queue
		QueueNode* nptr;
		nptr = head->prev;

		QueueNode* temp;
		//Points temp at head node
		temp = head;

		//Moves head pointer to the next node
		head = head->next;

		//Connects tail->next to new head node
		nptr->next = head;

		//Set current head->getPrev() to the end of queue
		head->prev = nptr;
		
		//Deletes temp
		delete temp;
	
	}
}



/*******************************************************************************
**			Queue::printQueue()
** Description:	This function displays the current values in the queue.
*******************************************************************************/
void Queue::printQueue()
{
	if(isEmpty())
	{
		cout << "List is empty." << endl;
	}

	else
	{
		cout << "Current list: ";

		//If only 1 element in queue
		if(head->prev == head && head->next == head)
		{
			cout << head->Val << " ";
		}
		else
		{
		
			QueueNode* nptr;
			nptr = head;

			//If at tail
			if(nptr->prev == head)
			{
				cout << (nptr->prev)->Val << " ";
				cout << "End of Queue" << endl;
			}
			else
			{
				//Print head node's value
				cout << nptr->Val << " ";

				nptr = nptr->next;
	
			//Stop at head or it will loop forever because this
			//is a circular list
				while (nptr != head)
				{	
					//Prints the value of current node
					cout << nptr->Val << " ";
					//Move onto the next node
					nptr = nptr->next;
				}

			}
		}	
	
		cout << endl;
	}
}
