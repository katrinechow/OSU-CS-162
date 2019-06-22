/*******************************************************************************
** Program Name: Lab 4 - OSU Information System: university.hpp
** Author: Katrine Chow
** Date: January 29, 2018
** Description:	This is the header file that declares class University and its
**		member variables and functions.
*******************************************************************************/
#include <vector>
#include <string>
#include "building.hpp"
#include "person.hpp"

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

using std::string;
using std::vector;

class University
{
	private:
		string name = "Oregon State University";
		int bnum; //Number of Buildings
		int pnum; //Number of Persons
//		vector <Building> bptr;
//		vector <Person> pptr;

	public:
		University(); //Default constructor
		University(int, int);
		void printBuilding(vector<Building>&); //Prints all info on all buildings
		void printPerson(int, int, Person*&); //Prints all info on all Persons



};

#endif
