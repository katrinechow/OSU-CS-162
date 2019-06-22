/*******************************************************************************
** Program Name: Final Project - Text-based Game: mainhall.hpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the header file for class Mainhall, which contains data
**		members and Space pointers that will help traverse through
**		this Space. This class inherits from class Space
*******************************************************************************/
#include <string>
#include <vector>

#include "space.hpp"

using std::vector;
using std::string;

#ifndef MAINHALL_HPP
#define MAINHALL_HPP

class Mainhall : public Space
{
	private:
		bool hammer = false;
		bool tape = false;
		bool axe = false;
	public:
		Mainhall();
		bool winCondition() override;
		void printSpace() override;
		string Scenario1(vector<int>&) override;
		string Scenario2a(vector<int>&) override;
		string Scenario3() override;
};
#endif
