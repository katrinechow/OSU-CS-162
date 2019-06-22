/*******************************************************************************
** Program Name: Lab 4 - OSU Information System: instructor.hpp
** Author: Katrine Chow
** Date: January 29, 2018
** Description:	This is the header file for class Instructor, which inherits
**		from the Person class.
*******************************************************************************/
#include "person.hpp"

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

class Instructor : public Person
{
	private:
		double rating;

	public:
		Instructor(); //Default constructor
		Instructor(string, int, double);
		void setRating(double);
		double getRating() override;
		void do_Work() override;



};

#endif
