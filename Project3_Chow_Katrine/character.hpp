/*******************************************************************************
** Program Name: Project 3 - Fantasy Combat Game: character.hpp
** Author: Katrine Chow
** Date: February 12, 2018
** Description:	This is the header file for class Character, which serves as the
**		base class for all character types.
*******************************************************************************/
#include <string>

using std::string;

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
	protected:
		int armor = 0;
		int sp = 0;
		int oldsp = 0;
		char type;
		int roll = 0;
		int damage = 0;
		bool role; //False for defense, true for attack
	public:
		virtual int Attack(Character*) = 0;
		virtual void Defense(Character*, int) = 0;
		int rollDice(int);
		string getType();
		int getArmor();
		void setArmor(int);
		int getSP();
		void setSP(int);
		int getOldSP();
		bool getRole();
		void setRole(bool);
		void setRoll(int);
		int getRoll();
		void setDamage(int);
		int getDamage();
		~Character();

};
#endif
