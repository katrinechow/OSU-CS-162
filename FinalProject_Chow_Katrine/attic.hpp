/*******************************************************************************
** Program Name: Final Project - Text-based Game: attic.hpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the header file for class Attic, which contains data
**		members and Space pointers that will help traverse through
**		this Space. This class inherits from class Space
*******************************************************************************/
#include <string>

#include "space.hpp"

#ifndef ATTIC_HPP
#define ATTIC_HPP

using std::string;

class Attic : public Space
{
	private:

	public:
		Attic();
		bool winCondition() override;	
		void printSpace() override;
		string Scenario1() override;
		void Scenario2() override;

};
#endif
