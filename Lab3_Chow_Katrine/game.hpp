/*******************************************************************************
** Program Name: Lab 3 - War Game (dice): game.hpp
** Author: Katrine Chow
** Date: January 27, 2018
** Description:	This is the header file for the Game class, which declares the
**		member variables and functions that run the game.
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "die.hpp"
#include "loadeddie.hpp"

class Game
{
	private:
		int rounds = 0;
		int p1 = 0;
		int p2 = 0;
		int score1 = 0;
		int score2 = 0;
		int sides1 = 0;
		int sides2 = 0;
		int die1 = 0;
		int die2 = 0;
		
	public:
		int callMenu(); //Displays menu selections
		void initialize(); //Create dice objects and initialize values
		int getSides(int); //Returns player's die sides
		void keepScore(int); //Keep each player's score
		int getScore(int); //Gets player's score
		void printScore(); //Displays each player's score
		void printResults(); //Display results each round
		

};
#endif
