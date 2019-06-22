/*******************************************************************************
** Program Name: Lab 4 - OSU Information System: building.cpp
** Author: Katrine Chow
** Date: January 29, 2018
** Description:	This is the implementation file for class Building. This defines
**		the member functions related to setting and getting info.
*******************************************************************************/

#include <iostream>
#include <cstring>

#include "building.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*******************************************************************************
**				Building::Building()
** Description:	This is the default constructor of a class Building object.
**		It initializes the attributes of a Building.
*******************************************************************************/

Building::Building()
{
	name = "Memorial Union Building";
	size = 141600;
	address = "2501 SW JEFFERSON WAY, CORVALLIS, OR 97331";
}


/*******************************************************************************
**			Building::Building(string, size, string)
** Description:	This constructor builds a Building object based on parameters
**		passed (from file or user-specified).
*******************************************************************************/

Building::Building(string n, int s, string a)
{
	name = n;
	size = s;
	address = a;
}


/*******************************************************************************
**			Building::setName(string)
** Description:	This is a setter function to store name of building.
*******************************************************************************/

void Building::setName(string n)
{
	name = n;
}


/*******************************************************************************
**			Building::getName()
** Description:	This is the getter function to get the name of building.
*******************************************************************************/

string Building::getName()
{
	return name;
}


/*******************************************************************************
**			Building::setSize(int)
** Description:	This is the setter function to set building size.
*******************************************************************************/

void Building::setSize(int s)
{
	size = s;
}


/*******************************************************************************
**			Building::getSize()
** Description:	This is the getter function to get building size.
*******************************************************************************/

int Building::getSize()
{
	return size;
}


/*******************************************************************************
**			Building::setAddress(string)
** Description:	This is the setter function to store building address.
*******************************************************************************/

void Building::setAddress(string a)
{
	address = a;
}


/*******************************************************************************
**			Building::getAddress()
** Description:	This is the getter function to get building address.
*******************************************************************************/

string Building::getAddress()
{
	return address;
}
