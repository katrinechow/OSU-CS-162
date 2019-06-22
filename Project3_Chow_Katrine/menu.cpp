/*******************************************************************************
** Program Name: Project 3 - Fantasy Combat Game: menu.cpp
** Author: Katrine Chow
** Date: February 12, 2018
** Description:	This is the implementation file for namespace menu, which builds
**		a menu interface for the combat program.
*******************************************************************************/

#include "menu.hpp"
#include "character.hpp"
#include "die.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

using namespace Menu;

/*******************************************************************************
**				Menu::displayMenu1()
** Description:	This function displays a user interface with choices.
*******************************************************************************/

void Menu::displayMenu1()
{
	cout << "Welcome to Fantasy Mortal Combat!" << endl;;
	cout << "1) Start Game" << endl;
	cout << "2) Exit" << endl;
}


/*******************************************************************************
**			Menu::displayMenu2()
** Description:	This function displays 2 options after a combat round is over:
**		Play Again, or Exit.
*******************************************************************************/
void Menu::displayMenu2()
{
	cout << "1) Play Again?" << endl;
	cout << "2) Exit" << endl;
}



/*******************************************************************************
**			Menu::displayMenu3()
** Description:	This function displays a list of Characters to choose from
*******************************************************************************/

void Menu::displayMenu3()
{
	cout << "1) Vampire" << endl;
	cout << "2) Barbarian" << endl;
	cout << "3) Blue Men" << endl;
	cout << "4) Medusa" << endl;
	cout << "5) Harry Potter" << endl;
}

/*******************************************************************************
**				char Menu:getChoice(char)
** Description:	This function collects user's choice.
*******************************************************************************/

char Menu::getChoice(char max)
{
	char choice = cin.get();
	cin.ignore();

	while (choice < '1' || choice > max)
	{
		cout << "Please enter a valid number from 1 to " << max << endl;
		choice = cin.get();
		cin.ignore();
	}

	return choice;
}


/*******************************************************************************
**			Menu::play()
** Description:	This function collects info from the menus and manages gameflow.
*******************************************************************************/
int Menu::play()
{
	const char MENU3MAX = '5';

	Character* p1 = nullptr;
	Character* p2 = nullptr;

	cout << "Choose Character 1:" << endl;
	displayMenu3();
	char choice = getChoice(MENU3MAX);

	switch(choice)
	{
		case '1':
		{
			p1 = new Vampire;
			break;
		}
		case '2':
		{
			p1 = new Barbarian;
			break;
		}
		case '3':
		{
			p1 = new BlueMen;
			break;
		}
		case '4':
		{
			p1 = new Medusa;
			break;
		}
		case '5':
		{
			p1 = new HarryPotter;
			break;
		}
	}

	cout << endl;

	cout << "Choose Character 2:" << endl;
	displayMenu3();
	char choice3 = getChoice(MENU3MAX);

	switch(choice3)
	{
		case '1':
		{
			p2 = new Vampire;
			break;
		}
		case '2':
		{
			p2 = new Barbarian;
			break;
		}
		case '3':
		{
			p2 = new BlueMen;
			break;
		}
		case '4':
		{
			p2 = new Medusa;
			break;
		}
		case '5':
		{
			p2 = new HarryPotter;
			break;
		}
	}

	cout << endl;

	int round = 1;

	//Check if characters are alive
	while(p1->getSP() >= 0 && p2->getSP() >= 0)
	{
		cout << "Round " << round << " - Fight!" << endl;
		cout << endl;

		//Attack begins- Player 1 attacks first
		cout << "Player 1 Attacks!" << endl;
		int atk1 = p1->Attack(p2);
		p2->Defense(p1, atk1);
		cout << endl;
		
		displayStats(p1, p2);
		
		cout << endl;

		//Check on status
		if(p1->getSP() <= 0)
		{
			cout << "Player 1 K.O." << endl;
			delete p1;
			delete p2;
			return 7;
		}
		else if (p2->getSP() <= 0)
		{
			cout << "Player 2 K.O." << endl;
			delete p1;
			delete p2;
			return 7;
		}

		//Attack by player 2
		cout << "Player 2 Attacks!" << endl;
		atk1 = p2->Attack(p1);
		p1->Defense(p2, atk1);
		cout << endl;

		displayStats(p2, p1);

		cout << endl;

		//Check on status
		if(p1->getSP() <= 0)
		{
			cout << "Player 1 K.O." << endl;
			delete p1;
			delete p2;
			return 7;
		}
		else if (p2->getSP() <= 0)
		{
			cout << "Player 2 K.O." << endl;
			delete p1;
			delete p2;
			return 7;
		}
		cout << endl;

		round++;

	}

	if(p1->getSP() <= 0)
	{
		cout << "Player 1 K.O." << endl;
		return 7;
	}
	else if(p2->getSP() <= 0)
	{
		cout << "Player 2 K.O." << endl;
		return 7;
	}

	//Deallocate objects
	delete p1;
	p1 = nullptr;
	delete p2;
	p2 = nullptr;
}


/*******************************************************************************
**			Menu::displayStats()
** Description:	This function displays Attacker and Defender's stats after a
**		round.
*******************************************************************************/
void Menu::displayStats(Character* atk, Character* def)
{
	cout << "Attacker Type: " << atk->getType() << endl;
	cout << "Defender Type: " << def->getType() << endl;
	cout << "Defender Armor: " << def->getArmor() << endl;
	cout << "Defender Strength Point: " << def->getOldSP() << endl;
	cout << "Attacker's Dice Roll: " << atk->getRoll() << endl;
	cout << "Defender's Dice roll: " << def->getRoll() << endl;
	cout << "Total Damage: " << def->getDamage() << endl;
	cout << "Defender's Strength Point: " << def->getSP() << endl;

}
