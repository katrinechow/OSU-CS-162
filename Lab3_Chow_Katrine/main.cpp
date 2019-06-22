/*******************************************************************************
** Program Name: Lab 3 - War Game (Dice): main.cpp
** Author: Katrine Chow
** Date January 27, 2018
** Description:	This program simulates the War game played with dice. 2 players
**		each gets a choice of regular or loaded die. They can also
**		specify the number of sides of the die, and number of rounds.
**		The program calculates and keeps score for each player and will
**		print the final winner after completing all rounds.
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "die.hpp"
#include "loadeddie.hpp"
#include "game.hpp"
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Game game;
	int menustatus;

	//Display menu
	menustatus = game.callMenu();

	if (menustatus == 7)
	{
		//Seeds rand()
		srand(time(0));
		
		//Starts game
		game.initialize();

	}

	else
	{
		return 0;
	}
}
