/*******************************************************************************
** Program Name: Final Project - Text-based Game: player.cpp
** Author: Katrine Chow
** Date: March 16, 2018
** Description:	This is the implementation file for the player class. This file
**		defines the functions that will be used to update and retrieve
**		player's stats (body temp, location, inventory).
*******************************************************************************/
#include <iostream>
#include <vector>

#include "player.hpp"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**				Player::Player()
** Description: This is the default constructor for class Player, which
**		initializes player's attributes.
*******************************************************************************/
Player::Player()
{
	bodyTemp = 37;
	location = 1;
}


/*******************************************************************************
**				Player::~Player()
** Description:	This is the destructor for class Player.
*******************************************************************************/
Player::~Player()
{


}


/*******************************************************************************
**				Player::setTemp(int)
** Description:	This function updates player's body temp.
*******************************************************************************/
void Player::setTemp(int num)
{
	bodyTemp = bodyTemp + num;
}


/*******************************************************************************
**				Player::getTemp()
** Description:	This function returns the current body temperature.
*******************************************************************************/
int Player::getTemp()
{
	return bodyTemp;
}


/*******************************************************************************
**				Player::addItem(int)
** Description:	This function adds item to player's inventory.
*******************************************************************************/
void Player::addItem(int assetID)
{
	Bag.push_back(assetID);
}


/*******************************************************************************
**				Player::removeItem(int)
** Description:	This function removes a specified item from the Bag.
*******************************************************************************/
/*void Player::removeItem(int assetID)
{
	int index;
	for (int i = 0; i < Bag.size(); i++)
	{
		if(Bag.at(i) == assetID)
		{
			index = i;
		}
	}

	Bag.erase(index);

}

*/
/*******************************************************************************
**				Player::isEmpty()
** Description:	This function checks if inventory is empty.
*******************************************************************************/
bool Player::isEmpty()
{
	if(Bag.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*******************************************************************************
**				Player::isComplete()
** Description:	This function checks if player has collected all key items.
*******************************************************************************/
bool Player::isComplete()
{

	if(total == 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*******************************************************************************
**				Player::updateTotal()
** Description:	This function updates the total KeyItems count whenever player
**		receives a Key Item.
*******************************************************************************/
void Player::updateTotal()
{
	total++;
}


/*******************************************************************************
**				Player::getLocation()
** Description:	This function returns player's current location.
*******************************************************************************/
int Player::getLocation()
{
	return location;
}


/*******************************************************************************
**				Player::setLocation()
** Description:	This function sets the player's current location.
*******************************************************************************/
void Player::setLocation(int loc)
{
	location = loc;
}


/*******************************************************************************
**				Player::setTraverse(char)
** Description:	This function sets the player location as a Space pointer.
*******************************************************************************/
/*void Player::setTraverse(Space* current, char t)
{
	traverse = current;

	if(t == 'e')
	{
		traverse = traverse->getLeft();
	}
	else if (t == 'w')
	{
		traverse = traverse->getRight();
	}
	else if (t == 'n')
	{
		traverse = traverse->getTop();
	}
	else if (t == 'u')
	{
		traverse = traverse->getUp();
	}
	else if (t == 'd')
	{
		traverse = traverse->getDown();
	}
	else if (t == 'h')
	{
		traverse = current;
	}

}

*/
/*******************************************************************************
**				Player::printBag()
** Description:	This function prints the current inventory.
*******************************************************************************/
void Player::printBag()
{
	cout << "Your current inventory:" << endl;
	cout << endl;

	for (int i = 0; i < Bag.size(); i++)
	{
		cout << Bag.at(i) << " ";
	}

	cout << endl;
}


/*******************************************************************************
**				Player::getBag()
** Description:	This function returns the Bag vector by reference.
*******************************************************************************/
vector<int>& Player::getBag()
{
	return Bag;
}

