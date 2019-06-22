/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament - character.cpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the implementation file for class Character, which
**		defines its data members and attach and defense functions.
*******************************************************************************/
#include "character.hpp"
#include "die.hpp"

#include <string>

using std::string;

/*******************************************************************************
**			Character::getName()
** Description:	This function returns the name of the Character.
********************************************************************************/
string Character::getName()
{
	return name;
}


/*******************************************************************************
**			Character::setName(string)
** Description:	This function sets the name of the Character.
*******************************************************************************/
void Character::setName(string n)
{
	name = n;
}



/*******************************************************************************
**			Character::rollDice(int)
** Description:	This function rolls one die and returns the result.
*******************************************************************************/
int Character::rollDice(int sides)
{
	Die d(sides);

	int result = d.returnRoll();

	return result;
}


/*******************************************************************************
**			Character::getType()
** Description:	This function returns the type of character.
*******************************************************************************/
string Character::getType()
{
	if (type == 'v')
	{
		return "Vampire";
	}
	else if (type == 'b')
	{
		return "Barbarian";
	}
	else if (type == 'x')
	{
		return "Blue Men";
	}
	else if (type == 'm')
	{
		return "Medusa";
	}
	else if (type == 'h')
	{
		return "Harry Potter";
	}

}



/*******************************************************************************
**			Character::getArmor()
** Description:	This function returns the character's current Armor value.
*******************************************************************************/
int Character::getArmor()
{
	return armor;
}


/*******************************************************************************
**			Character::setArmor(int)
** Description:	This function sets the character's Armor value.
*******************************************************************************/
void Character::setArmor(int a)
{
	armor = a;
}

/*******************************************************************************
**			Character::getOldSP()
** Description:	This function gets the oldsp value, which stores defender's sp
**		before damages are applied to it.
*******************************************************************************/
int Character::getOldSP()
{
	return oldsp;
}


/*******************************************************************************
**			Character::getSP()
** Description:	This function returns the character's current SP value.
*******************************************************************************/
int Character::getSP()
{
	return sp;
}


/*******************************************************************************
**			Character::setSP(int)
** Description:	This function sets the character's strength value.
*******************************************************************************/
void Character::setSP(int s)
{
	sp = s;
}


/*******************************************************************************
**			Character::getRole()
** Description:	This function returns the current role of the character. False
**		means it is defending; True means it is attacking.
*******************************************************************************/
bool Character::getRole()
{
	return role;
}


/*******************************************************************************
**			Character:;setRole()
** Description:	This function sets the character's current role.
*******************************************************************************/
void Character::setRole(bool r)
{
	role = r;
}


/*******************************************************************************
**			Character::setRoll(int)
** Description:	This function stores the current dice roll.
*******************************************************************************/
void Character::setRoll(int r)
{
	roll = r;
}


/*******************************************************************************
**			Character::getRoll()
** Description:	This function returns the current dice roll.
*******************************************************************************/
int Character::getRoll()
{
	return roll;
}


/*******************************************************************************
**			Character::setDamage(int)
** Description:	This function stores the current damage incurred.
*******************************************************************************/
void Character::setDamage(int d)
{
	damage = d;
}


/*******************************************************************************
**			Character::getDamage()
** Description:	This function gets the current damage.
*******************************************************************************/
int Character::getDamage()
{
	return damage;
}


/*******************************************************************************
**			Character::recover()
** Description:	This function recovers a percentage of the damage to the
**		character's sp. This is called when character wins in the
**		tournament.
*******************************************************************************/
void Character::recover()
{
	//Add random percentage of damage back to sp
	int roll = rand() % 6 + 1;
	int add = 0;

	if (roll == 1)
	{
		add = damage * 0.1;
	}
	else if (roll == 2)
	{
		add = damage * 0.2;
	}
	else if (roll == 3)
	{
		add = damage * 0.3;
	}
	else if (roll == 4)
	{
		add = damage * 0.4;
	}
	else if (roll == 5)
	{
		add = damage * 0.5;
	}
	else
	{
		add = damage * 0.6;
	}
		
	sp = sp + add;
}


/*******************************************************************************
**			Character::~Character
** Description:	This is the destructor of class Character.
*******************************************************************************/
//Character::~Character()
//{
	
//}

