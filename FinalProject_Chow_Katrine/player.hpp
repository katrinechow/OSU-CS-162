/*******************************************************************************
** Program Name: Final Project - Text-based Game: player.hpp
** Author: Katrine Chow
** Date: March 16, 2018
** Description:	This is the header file for class Player. This file identifies
**		the variables associated with the player's health and location.
**		There is also a container to store the player's inventory.
*******************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "space.hpp"
#include <vector>

using std::vector;

class Player
{
	private:
		int bodyTemp;
		int location;
		int total;
		Space* traverse = nullptr;
		vector <int> Bag;

	public:
		Player();
		~Player();
		void setTemp(int);
		int getTemp();
		void addItem(int);
	//	void removeItem(int);
		bool isEmpty();
		bool isComplete();
		void updateTotal();
		int getLocation();
		void setLocation(int);
		void printBag();
		vector<int>& getBag();
};

#endif
