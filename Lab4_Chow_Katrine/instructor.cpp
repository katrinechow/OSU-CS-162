/*******************************************************************************
** Program Name: Lab 4 - OSU Information System: instructor.cpp
** Author: Katrine Chow
** Date: January 29, 2018
** Description:	This is the implementation file for the Instructor class, which
**		has a doWork function that generates a random number of hours
**		the instructor graded papers.
*******************************************************************************/

#include <iostream>
#include <cstdlib>

//#include "instructor.hpp"
#include "person.hpp"
//#include "university.hpp"
#include "instructor.hpp"

/*******************************************************************************
**			Instructor::Instructor()
** Description:	This is the default constructor that initializes rating.
*******************************************************************************/

Instructor::Instructor()
{
	rating = 0.0;
}


/*******************************************************************************
**			Instructor::Instructor(string, int, double)
** Description:	This constructor initializes rating from file/user input.
*******************************************************************************/

Instructor::Instructor(string n, int a, double r)
{
	name = n;
	age = a;
	rating = r;
	flag = 'i';
}


/*******************************************************************************
**			Instructor::setRating(double)
** Description:	This sets rating for an Instructor
*******************************************************************************/

void Instructor::setRating(double r)
{
	rating = r;
}


/*******************************************************************************
**			Instructor::getRating()
** Description:	This gets rating for an Instructor
*******************************************************************************/

double Instructor::getRating()
{
	return rating;
}


/*******************************************************************************
**			Instructor::do_Work()
** Description:	This function generates a randomized number of hours worked.
*******************************************************************************/

void Instructor::do_Work()
{
	int hours = rand() % 24;

	cout << name << " graded papers for " << hours << " hours." << endl;
}


//Destructor
//Instructor::~Instructor(){}
