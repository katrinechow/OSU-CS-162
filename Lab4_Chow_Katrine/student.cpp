/*******************************************************************************
** Program Name: Lab 4 - OSU Information System: student.cpp
** Author: Katrine Chow
** Date: January 29, 2018
** Description:	This is the implementation file for the Student class. Its
**		doWork function generates a random number of hours student
**		spent doing homework.
*******************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "student.hpp"
#include "person.hpp"
//#include "university.hpp"

/*******************************************************************************
**			Student::Student()
** Description:	This is the default constructor of class Student, which
**		initializes the GPA to 0.0.
*******************************************************************************/

Student::Student()
{
	GPA = 0.0;
}


/*******************************************************************************
**			Student::Student(string, int, double)
** Description:	This constructor initializes GPA from user/file input.
*******************************************************************************/

Student::Student(string s, int a, double g)
{
	name = s;
	age = a;
	GPA = g;
	flag = 's';
}

	
/*******************************************************************************
**			Student::setGPA(double)
** Description:	This function sets a Student's GPA.
*******************************************************************************/

void Student::setGPA(double g)
{
	GPA = g;
}


/*******************************************************************************
**			Student::getGPA()
** Description:	This function gets a Student's GPA.
*******************************************************************************/

double Student::getGPA()
{
	return GPA;
}


/*******************************************************************************
**			Student::do_Work()
** Description:	This function generates a random number of hours a Student
**		spent on homework.
*******************************************************************************/

void Student::do_Work()
{
	int hours = rand() % 24;
	
	cout << name << " did " << hours << " hours of homework." << endl;

}

//Destructor
//Student::~Student(){}
