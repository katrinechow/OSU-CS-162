/*******************************************************************************
** Program Name: Final Project - Text-based Game: game.hpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the header file for class Game, which contains
**		function prototypes that will run and manage gameplay.
*******************************************************************************/
#include "space.hpp"
#include "player.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
	private:

	public:
		Game(); //Default constructor
		~Game();
		int playGame();
};
#endif
