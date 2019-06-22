/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: harrypotter.hpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the header file for class HarryPotter, which inherits
**		from base class Character. HarryPotter has its own attack and
**		defense attributes.
*******************************************************************************/
#include "character.hpp"
#include "harrypotter.hpp"
#include "die.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*******************************************************************************
**			HarryPotter::HarryPotter
** Description:	This is the default constructo of class HarryPotter.
*******************************************************************************/
HarryPotter::HarryPotter()
{
	armor = 0;
	sp = 10;
	type = 'h';
	hearts = 1;	
	role = false;
}


/*******************************************************************************
**			HarryPotter::Attack(Character*)
** Description:	This function defines how HarryPotter attacks.
*******************************************************************************/
int HarryPotter::Attack(Character* defender)
{
	role = true;

	int roll1 = rollDice(6);
	int roll2 = rollDice(6);

	roll = roll1+roll2;

	cout << "Harry Potter has his wand at the ready." << endl;
	cout << "Expelliarmus!" << endl;
	cout << "Harry Potter disarms with " << roll << " damages"
		<< endl;

	return roll;
}


/*******************************************************************************
**			HarryPotter::Defense(Character*)
** Description:	This function defines how HarryPotter defends.
*******************************************************************************/
void HarryPotter::Defense(Character* attacker, int atk1)
{
	role = false;

	int roll1 = rollDice(6);
	int roll2 = rollDice(6);

	roll = roll1+roll2;

	damage = atk1 - roll - armor;

	if(damage > 0)
	{
		cout << "Harry Potter takes " << damage << " points of damage!" 
			<< endl;
		oldsp = sp;
		sp = sp - damage;
	}
	else
	{
		oldsp = sp;
		damage = 0;
		cout << "Harry Potter takes no damage this round!" << endl;
	}


	//Special Ability
	if(sp <= 0 && hearts == 1)
	{
		sp = 20;
		cout << "In a daze, Harry Potter sees a flicker of red gliding"
			<< " gently towards him." << endl;
		cout << "Fawkes gives its blessing!" << endl;
		cout << "Harry Potter now has 20 strength points!" << endl;
		hearts--;
	}

}
