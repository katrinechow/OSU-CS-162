/*******************************************************************************
** Program Name: Lab 7 - Circular Linked List: node.hpp
** Author: Katrine Chow
** Date: February 22, 2018
** Description:	This is the header file for struct QueueNode, which contains a 
**		value,a pointer to a previous node, and a pointer to the next 
**		node.
*******************************************************************************/

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

struct QueueNode
{
	int Val;
	QueueNode* prev = nullptr;
	QueueNode* next = nullptr;

	QueueNode(int v)
	{
		Val = v;
	}

};
#endif
