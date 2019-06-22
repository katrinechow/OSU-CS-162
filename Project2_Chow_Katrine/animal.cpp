/*******************************************************************************
** Program Name: Project 2 - Zoo Tycoon: animal.cpp
** Author: Katrine Chow
** Date: January 30, 2018
** Description:	This is the implementation file for class Animal. It defines the
**		storage and display of animal data, its feed costs, and payoff.
*******************************************************************************/

#include <iostream>

#include "animal.hpp"

/*******************************************************************************
**				Animal::Animal()
** Description:	This is the default constructor for class Animal.
*******************************************************************************/

Animal::Animal()
{
	age = 0;
}


/*******************************************************************************
**				Animal::setAge(int)
** Description:	This is the setter function for an animal's age attribute.
*******************************************************************************/

void Animal::setAge(int a)
{
	age = age + a;
}


/*******************************************************************************
**				Animal::getAge()
** Description:	This is the getter function for an animal's age.
*******************************************************************************/

int Animal::getAge()
{
	return age;
}


/*******************************************************************************
**				Animal::getCost()
** Description:	This is the getter function for an animal's cost.
*******************************************************************************/

double Animal::getCost()
{
	return cost;
}


/*******************************************************************************
**				Animal::getNumberOfBabies()
** Description:	This is the getter function for an animal's number of babies.
*******************************************************************************/

int Animal::getNumberOfBabies()
{
	return numberofbabies;
}


/*******************************************************************************
**				Animal::getBaseFoodCost()
** Description:	This is the getter function for an animal's base food cost.
*******************************************************************************/

double Animal::getBaseFoodCost()
{
	return basefoodcost;
}


/*******************************************************************************
**				Animal::getPayoff()
** Description:	This is the getter function for an animal's payoff.
*******************************************************************************/

double Animal::getPayoff()
{
	return payoff;
}


/*******************************************************************************
**				Animal::getAgeType()
** Description:	This is the getter function for an animal's age status. It will
**		determine whether an animal is a baby or adult.
*******************************************************************************/

int Animal::getAgeType()
{
	if(age >= 3)
	{
		return 97;
	}
	else
	{
		return 98;
	}
}



