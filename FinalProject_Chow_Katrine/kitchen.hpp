/*******************************************************************************
** Program Name: Final Project - Text-based Game: kitchen.hpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the header file for class Kitchen, which contains data
**		members and Space pointers that will help traverse through
**		this Space. This class inherits from class Space
*******************************************************************************/
#include "space.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

class Kitchen : public Space
{
	public:
		bool keyCout = false;
		bool keyD = false;
		bool s2 = false;
		bool s3 = false;
	public:
		Kitchen();
		bool winCondition() override;
		void printSpace() override;
		string Scenario1(vector<int>&) override;
		void Scenario2(vector<int>&) override;
		void Scenario3(vector<int>&) override;

};
#endif
