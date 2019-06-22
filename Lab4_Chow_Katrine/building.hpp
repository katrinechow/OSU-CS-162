/*******************************************************************************
** Program Name: Lab 4 - OSU Information System: building.hpp
** Author: Katrine Chow
** Date: January 29, 2018
** Description:	This is the header file for class Building, which keeps track of
**		information related to buildings on OSU campus.
*******************************************************************************/
#include <string>

#ifndef BUILDING_HPP
#define BUILDING_HPP

using std::string;

class Building
{
	private:
		string name;
		int size;
		string address;

	public:
		Building(); //Default constructor
		Building(string, int, string);
		void setName(string);
		string getName();
		void setSize(int);
		int getSize();
		void setAddress(string);
		string getAddress();

};

#endif
