/*******************************************************************************
** Program Name: Project 3 - Fantasy Combat Game: vampire.cpp
** Author: Katrine Chow
** Date: February 12, 2018
** Description:	This is the implementation file for class Vampire. It defines
**		the attack and defense functions unique to Vampires.
*******************************************************************************/
#include "character.hpp"
#include "vampire.hpp"
#include "die.hpp"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**			Vampire::Vampire
** Description:	This is the default constructor of class Vampire.
*******************************************************************************/
Vampire::Vampire()
{
	armor = 1;
	sp = 18;
	type = 'v';
	role = false;
}


/*******************************************************************************
**			Vampire::Attack(Character*)
** Description:	This function defines how Vampires attack.
*******************************************************************************/
int Vampire::Attack(Character* defender)
{
	role = true;
	
	roll = rollDice(12);

	cout << "Vampire sparkles! Attacks for " << roll << " points!" << endl;

	return roll;
}


/*******************************************************************************
**			Vampire::Defense(Character*)
** Description:	This function defines how Vampires defend.
*******************************************************************************/
void Vampire::Defense(Character* attacker, int atk)
{
	role = false;
	damage = 0;

	roll = rollDice(6);

	cout << "Vampire uses Charm!" << endl;

	//Charm
	int chance = rand() %2 + 1;

	if(chance == 2)
	{
		damage = 0;
		cout << "Charm is effective! 0 Damage taken!" << endl;
	}
	else
	{
		damage = atk - roll - armor;
	}

	if(damage > 0)
	{
		cout << "Charm failed!" << endl;
		cout << "Vampire takes " << damage << " points of damage!"
			<< endl;
		oldsp = sp;
		sp = sp - damage;
	}
	else
	{
		damage = 0;
		oldsp = sp;
		cout << "Vampire takes no damage this round!" << endl;
	}

}


