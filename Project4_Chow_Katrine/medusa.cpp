/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: medusa.hpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the header file for class Medusa, which inherits from
**		base class Character. Medusa has its own attack and defense
**		attributes.
*******************************************************************************/
#include "character.hpp"
#include "medusa.hpp"
#include "die.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**			Medusa::Medusa
** Description:	This is the default constructor of class Medusa.
*******************************************************************************/
Medusa::Medusa()
{
	armor = 3;
	sp = 8;
	type = 'm';
	role = false;
}


/*******************************************************************************
**			Medusa::Attack(Character*)
** Description:	This function defines how Medusa attacks.
*******************************************************************************/
int Medusa::Attack(Character* defender)
{
	role = true;

	int roll1 = rollDice(6);
	int roll2 = rollDice(6);

	roll = roll1+roll2;

	cout << "Medusa's snake-hair twirls wildly!" << endl;
	
	//Special Ability
	if(roll == 12)
	{
		if(defender->getType() == "Vampire")
		{
			cout << "Medusa glares hungrily at her prey..." << endl;
			cout << "Will Vampire Charm her in time?" << endl;
		}
		else
		{
			defender->setSP(0);
			cout << "Medusa glares hungrily at her prey..." << endl;
			cout << "Medusa turns prey into stone!" << endl;
		}
	}
	else
	{
		cout << "Medusa hits for " << roll << " points of"
			<< " damage!" << endl;
	}

	return roll;
}


/*******************************************************************************
**			Medusa::Defense(Character*, int)
** Description:	This function defines how Medusa defends.
*******************************************************************************/
void Medusa::Defense(Character* attacker, int atk1)
{
	role = false;

	roll = rollDice(6);

	cout << "Medusa defends for " << roll << " points" << endl;

	damage = atk1 - roll - armor;

	if(damage > 0)
	{
		cout << "Medusa takes " << damage << " points of total damage!" 
			<< endl;
		oldsp = sp;
		sp = sp - damage;
	}
	else
	{
		oldsp = sp;
		damage = 0;
		cout << "Medusa takes no damage this round!" << endl;
	}


	cout << "Medusa now has " << sp << " strength points." << endl;
}

