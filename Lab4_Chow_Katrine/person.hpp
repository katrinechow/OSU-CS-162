/*******************************************************************************
** Program Name: Lab 4 - OSU Information System: person.hpp
** Author: Katrine Chow
** Date: January 29, 2018
** Description:	This is the header file for class Person, which stores info
**		about a person's name and age, as well as hours of work.
*******************************************************************************/
#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

#ifndef PERSON_HPP
#define PERSON_HPP

class Person
{
	protected:
		string name;
		int age;
		char flag;
	public:
		Person(); //Default constructor
		Person(string, int);
		void setName(string);
		string getName();
		void setAge(int);
		int getAge();
		void setFlag(char);
		char getFlag();
		virtual double getGPA(){};
		virtual double getRating(){};
		virtual void do_Work();



};

#endif
