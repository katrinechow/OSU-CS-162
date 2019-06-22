/*******************************************************************************
** Program Name: Lab 4 - OSU Information System: person.cpp
** Author: Katrine Chow
** Date: January 29, 2018
** Description:	This is the implementation file for class Person. This defines
**		the member function which generates a random number of hours
**		worked.
*******************************************************************************/

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

#include "person.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*******************************************************************************
**				Person::Person()
** Description:	This is the default constructor which initializes basic data of
**		a Person.
*******************************************************************************/
Person::Person()
{
	name = "";
	age = 0;
}


/*******************************************************************************
**			Person::Person(string, int)
** Description:	This constructor initializes Person data from input file or
**		user input.
*******************************************************************************/
Person::Person(string n, int a)
{
	name = n;
	age = a;
}


/*******************************************************************************
**			Person::setName(string)
** Description:	This function sets a Person's name with its parameter
*******************************************************************************/

void Person::setName(string n)
{
	name = n;
}


/*******************************************************************************
**			Person::getName()
** Description:	This is a getter function that returns a Person's name.
*******************************************************************************/

string Person::getName()
{
	return name;
}


/*******************************************************************************
**			Person::setAge(int)
** Description:	This function sets a Person's age.
*******************************************************************************/

void Person::setAge(int a)
{
	age = a;
}


/*******************************************************************************
**			Person::getAge()
** Description: This function returns a Person's age.
*******************************************************************************/

int Person::getAge()
{
	return age;
}


/*******************************************************************************
** 			Person::setFlag(char)
** Description:	This function identifies if this Person object is a "Student"
**		or "Instructor".
*******************************************************************************/

void Person::setFlag(char f)
{
	flag = f;
}


/*******************************************************************************
**			Person::getFlag()
** Description:	This function returns the type of Person this object is.
*******************************************************************************/

char Person::getFlag()
{
	return flag;
}


/*******************************************************************************
**			Person::do_Work()
** Description:	This function generates a random number that represents how
**		many hours a person worked. For Students: hours spent on
**		homework. For Instructors: hours spent grading papers.
*******************************************************************************/

void Person::do_Work()
{
	int hours;
	hours = rand() % 24;
}


