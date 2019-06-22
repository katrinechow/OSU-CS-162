/*******************************************************************************
** Program Name: Lab 3 - War Game (dice): game.cpp
** Author: Katrine Chow
** Date: January 27, 2018
** Description:	This is the implementation file for the Game class, which
**		defines the member functions that generate the game menu, keep
**		players' scores, and print out game results after each round.
*******************************************************************************/

#include <iostream>

#include "game.hpp"
#include "die.hpp"
#include "loadeddie.hpp"
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**				Game::callMenu()
** Description:	This function displays the menu for users to start or exit the
**		game.
*******************************************************************************/

int Game::callMenu()
{
	const char MENUMAX = '2';

	//Display initial menu
	Menu::displayMenu();
	char choice = Menu::getChoice(MENUMAX);

	//Choice 2 is to quit the program
	switch (choice)
	{
		case '1':
			return 7;
		case '2':
			return 0;
	}
}


/*******************************************************************************
**				Game::initialize()
** Description:	This function creates the dice objects and initialize values.
*******************************************************************************/
void Game::initialize()
{
	//Die class pointers
	Die *dptr1;
	Die *dptr2;
	loadedDie *lptr1;
	loadedDie *lptr2;


	//At least 1 round should be played
	while (rounds < 1)
	{
		cout << "How many rounds? Minimum is 1." << endl;
		while (!(cin >> rounds))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Invalid data type. Please try again." << endl;
		}
	}


	//Must choose 1 or 2
	while (die1 <= 0 || die1 > 2)
	{
		//Players choose their die
		cout << "Player 1: Which type of die? Type 1 for Regular, " 
			"type 2 for Loaded." << endl;
		while (!(cin >> die1))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Invalid data type. Please try again." << endl;
		}
	}

	while (die2 <= 0 || die2 > 2)
	{

		cout << "Player 2: Which type of die? Type 1 for Regular, "
			"type 2 for Loaded." << endl;
		while (!(cin >> die2))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Invalid data type. Please try again." << endl;
		}
	}

	//Players choose die size. Must be at least 3
	while (sides1 < 3)
	{
		cout << "Player 1: How many sides does your die have? " << 
			"Minimum is 3." << endl;
		while (!(cin >> sides1))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Invalid data type. Please try again." << endl;
		}
	}

	while (sides2 < 3)
	{
		cout << "Player 2: How many sides does your die have? " <<
			"Minimum is 3." << endl;
		while (!(cin >> sides2))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Invalid data type. Please try again." << endl;
		}
	}

	cout << endl;
	cout << endl;
	cout << "****************************************" << endl;
	cout << "Game Starts in 3.. 2.. 1!" << endl;
	cout << endl;

	//Create die instances here
	if (die1 == 1)
	{
		Die player1(sides1);
		dptr1 = &player1;
	}
	else if (die1 == 2)
	{
		loadedDie player1(sides1);
		lptr1 = &player1;
	}

	if (die2 == 1)
	{
		Die player2(sides2);
		dptr2 = &player2;
	}
	else if (die2 == 2)
	{
		loadedDie player2(sides2);
		lptr2 = &player2;
	}

	//Start game rolls

	for (int i = 0; i < rounds; i++)
	{
	
		if (die1 == 1)
		{
			p1 = dptr1->returnRoll();
		}
		else if (die1 == 2)
		{
			p1 = lptr1->returnRoll();
		}
		
		if (die2 == 1)
		{
			p2 = dptr2->returnRoll();
		}
		else if (die2 == 2)
		{
			p2 = lptr2->returnRoll();
		}

		if (p1 > p2)
		{
			keepScore(1);
		}

		else if (p2 > p1)
		{
			keepScore(2);
		}

		printResults();

	}

	cout << endl;
	cout << endl;
	cout << "****** WINNER * WINNER * WINNER *******" 
		<< endl;
	cout << endl;

	//Determine Final Winner
	cout << "Player 1's final score is: " << score1 << endl;
	cout << "Player 2's final score is: " << score2 << endl;
	cout << endl;
	cout << endl;

	if (score1 > score2)
	{
		cout << "### Congratulations! Player 1 is the winner! ###" 
			<< endl;
		cout << endl;
	}

	else if (score2 > score1)
	{
		cout << "### Congratulations! Player 2 is the winner! ###" 
			<< endl;
		cout << endl;
	}
	

	else
	{
		cout << ">>> It's a draw! This game is rigged grr! <<<" << endl;
		cout << endl;
	}	
}


/*******************************************************************************
**				Game::getSides(int)
** Description:	This function gets the number of sides of a die.
*******************************************************************************/

int Game::getSides(int s)
{
	if (s == 1)
	{
		return sides1;
	}

	else
	{
		return sides2;
	}
}


/*******************************************************************************
**				Game::keepScore(int)
** Description:	This function keeps each player's score.
*******************************************************************************/

void Game::keepScore(int winner)
{
	if (winner == 1)
	{
		score1 ++;
	}

	else if (winner == 2)
	{
		score2 ++;
	}
}


/*******************************************************************************
**				Game::getScore(int)
** Description:	This function returns each player's score.
*******************************************************************************/

int Game::getScore(int player)
{
	if (player == 1)
	{
		return score1;
	}

	else if (player == 2)
	{
		return score2;
	}
}


/*******************************************************************************
**				Game::printResults()
** Description:	This function prints results of the game.
*******************************************************************************/

void Game::printResults()
{
	//Report for Player 1
	if (die1 == 1)
	{
		cout << "Player 1's die is: Regular" << endl;
	}

	else if (die1 == 2)
	{
		cout << "Player 1's die is: Loaded" << endl;
	}

	cout << "Player 1's die has: " << getSides(1) << " sides"
		<< endl;

	cout << "Player 1 rolled: " << p1 << endl;

	cout << "Player 1's score is: " << getScore(1) << endl;

	cout << endl;
	cout << endl;

	//Report for Player 2
	if (die2 == 1)
	{
		cout << "Player 2's die is: Regular" << endl;
	}

	else if (die2 == 2)
	{
		cout << "Player 2's die is: Loaded" << endl;
	}

	cout << "Player 2's die has: " << getSides(2) << " sides"
		<< endl;

	cout << "Player 2 rolled: " << p2 << endl;

	cout << "Player 2's score is: " << getScore(2) << endl;

	cout << endl;
	cout << "****************************************" << endl;
	cout << endl;
}
