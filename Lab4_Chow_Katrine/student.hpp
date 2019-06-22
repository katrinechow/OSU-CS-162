/*******************************************************************************
** Program Name: Lab 4 - OSU Information System: student.hpp
** Author: Katrine Chow
** Date: January 29, 2018
** Description:	This is the header file for class Student, which keeps track of 
**		the student's information and hours worked. This class inherits
**		from the Person class.
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

#include "person.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

#ifndef STUDENT_HPP
#define STUDENT_HPP

class Student: public Person
{
	private:
		double GPA;

	public:
		Student(); //Default constructor
		Student(string, int, double);
		void setGPA(double); //Sets GPA
		double getGPA() override; //Gets GPA
		void do_Work() override; //Randomizer



};

#endif
