/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: barbarian.hpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the header file for class Barbarian, which inherits from
**		base class Character. Barbarian has its own attack and defense
**		attributes.
*******************************************************************************/
#include "character.hpp"
#include "barbarian.hpp"
#include "die.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**			Barbarian::Barbarian
** Description:	This is the default constructor of class Barbarian.
*******************************************************************************/
Barbarian::Barbarian()
{
	armor = 0;
	sp = 12;
	type = 'b';
	role = false;
}


/*******************************************************************************
**			Barbarian::Attack(Character*)
** Description:	This function defines how Barbarians attack.
*******************************************************************************/
int Barbarian::Attack(Character* defender)
{
	role = true;

	int roll1 = rollDice(6);
	int roll2 = rollDice(6);

	roll = roll1 + roll2;

	cout << "Barbarian shouts: \"Conan never dies!\"" << endl;
	cout << "Barbarian charges!" << endl;
	cout << "Barbarian attacks for " << roll << " points of damage!" << endl;

	return roll;
	
}


/*******************************************************************************
**			Barbarian::Defense(Character* attacker)
** Description:	This function defines how Barbarians defend.
*******************************************************************************/
void Barbarian::Defense(Character* attacker, int atk1)
{
	role = false;

	int roll1 = rollDice(6);
	int roll2 = rollDice(6);

	roll = roll1 + roll2;

	damage = atk1 - (roll1 + roll2) - armor;

	if(damage > 0)
	{
		cout << "Barbarian takes " << damage << " points of damage!"
			<< endl;

		oldsp = sp;
		sp = sp - damage;
	}
	else
	{
		oldsp = sp;
		damage = 0;
		cout << "Barbarian takes no damage this round!" << endl;
	}

}
