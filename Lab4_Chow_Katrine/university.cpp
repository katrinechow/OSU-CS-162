/*******************************************************************************
** Program Name: Lab 4 - OSU Information System: university.cpp
** Author: Katrine Chow
** Date: January 29, 2018
** Description:	This is the implementation of class University. It defines the
**		member functions associated with storing campus information.
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>

#include "university.hpp"
#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setprecision;
using std::fixed;

/*******************************************************************************
**			University::University()
** Description:	This is the default constructor which initializes basic data
**		that are included in a University.
*******************************************************************************/

University::University()
{
	int bnum = 0;
	int pnum = 0;
}


/*******************************************************************************
**			University::University(int, int)
** Description:	This constructor initializes University's data from user/file
**		input.
*******************************************************************************/

University::University(int b, int p)
{
	bnum = b;
	pnum = p;
}


/*******************************************************************************
**			University::printBuilding(vector<Building>)
** Description:	This function prints all Buildings in the system.
*******************************************************************************/

void University::printBuilding(vector<Building>& bldgvector)
{
	//Code for looping through vector and printing name of each bldg.
	cout << "****************************************" << endl;
	cout << endl;

	for (int i = 0; i < bldgvector.size() ; i++)
	{
		cout << i+1 << ") Name is: " << bldgvector[i].getName() << endl;
		cout << "   Size is: " << bldgvector[i].getSize() << endl;
		cout << "   Address is: " << bldgvector[i].getAddress() <<
			endl;
		cout << endl;
		cout << "***************************************" << endl;
	} 	
}


/*******************************************************************************
**			University::printPerson(vector<Person>)
** Description:	This function prints all Persons in the system.
*******************************************************************************/

void University::printPerson(int size, int num, Person *&ppl)
{
	//Code for loop to print all Persons.
	cout << num << ") Name is: " << ppl->getName() << endl;
	cout << "   Age is: " << ppl->getAge() << endl;
	
	if(ppl->getFlag() == 's')
	{
		cout << "   GPA is: " << fixed << setprecision(1) << 
			ppl->getGPA() << endl;
	}

	else if(ppl->getFlag() == 'i')
	{
		cout << "   Rating: " << fixed << setprecision(1) << 
			ppl->getRating() << endl;
	}

	cout << endl;
	cout << "****************************************" << endl;
}

