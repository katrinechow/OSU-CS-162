/*******************************************************************************
** Program Name: Project 2 - Zoo Tycoon: animal.hpp
** Author: Katrine Chow
** Date: January 30, 2018
** Description:	This is the header file for class Animal. It keeps track of
**		each animal's data.
*******************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
	protected:
		int age;
		double cost;
		int numberofbabies;
		double basefoodcost = 10;
		double payoff;

	public:
		Animal(); //Default constructor
		void setAge(int);	
		int getAge();
		double getCost();
		int getNumberOfBabies();
		double getBaseFoodCost();
		double getPayoff();
		int getAgeType();
};

#endif
