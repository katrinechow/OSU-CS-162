/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: node.hpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the header file for struct QueueNode, which contains a 
**		Character pointer, a pointer to a previous node, and a pointer 
**		to the next node.
*******************************************************************************/
#include "character.hpp"

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

struct QueueNode
{
	Character* fighter;
	QueueNode* prev = nullptr;
	QueueNode* next = nullptr;

	QueueNode(Character* f)
	{
		fighter = f;
	}

};
#endif
