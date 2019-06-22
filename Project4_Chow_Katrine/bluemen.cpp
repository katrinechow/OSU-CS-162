/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: bluemen.hpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the header file for class BlueMen, which inherits from
**		base class Character. BlueMen has its own attack and defense
**		attributes.
*******************************************************************************/
#include "character.hpp"
#include "bluemen.hpp"
#include "die.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**			BlueMen::BlueMen
** Description:	This is the default constructor of class BlueMen.
*******************************************************************************/
BlueMen::BlueMen()
{
	armor = 3;
	sp = 12;
	type = 'x';
	dicecount = 3;
	role = false;
}


/*******************************************************************************
**			BlueMen::Attack(Character*)
** Description:	This function defines how BlueMen attack.
*******************************************************************************/
int BlueMen::Attack(Character* defender)
{
	role = true;

	int roll1 = rollDice(10);
	int roll2 = rollDice(10);

	roll = roll1+roll2;

	cout << "Blue Men remembers more peaceful times at Smurfs Village"
		<< endl;
	cout << "Blue Men hits for " << roll << " points of damage!"
		<< endl;

	return roll;

}


/*******************************************************************************
**			BlueMen::Defense(Character*, int)
** Description:	This function defines how BlueMen defend.
*******************************************************************************/
void BlueMen::Defense(Character* attacker, int atk1)
{
	role = false;

	setDiceCount(); //Updates dicecount based on current sp
	int count = getDiceCount();
	cout << "Current defender's dice count is: " << count << endl;
	cout << "Current sp is: " << sp << endl;
	roll = 0;

	for (int i = 0; i < count; i++)
	{
		roll = roll + rollDice(6);
	}

	damage = atk1 - roll - armor;

	if(damage > 0)
	{
		cout << "Blue Men takes " << roll << " points of damage!" 
			<< endl;
		oldsp = sp;
		sp = sp - damage;
	}
	else
	{
		oldsp = sp;
		damage = 0;
		cout << "Blue Men takes no damage this round!" << endl;
	}

	cout << "Blue Men now has " << sp << " strength points." << endl;	

}


/*******************************************************************************
**			BlueMen::setDiceCount()
** Description:	This function sets the number of dice BlueMen can use for
**		defense.
*******************************************************************************/
void BlueMen::setDiceCount()
{
	if(sp <= 8 && sp > 4)
	{
		dicecount = 2;
	}
	else if (sp <= 4 && sp >0)
	{
		dicecount = 1;
	}
}


/*******************************************************************************
**			BlueMen::getDiceCount()
** Description:	This function returns the number of defense dice.
*******************************************************************************/
int BlueMen::getDiceCount()
{
	return dicecount;
}
