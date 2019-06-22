/*******************************************************************************
** Program Name: Final Project - Text-based Game: pond.hpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the header file for class Pond, which contains data
**		members and Space pointers that will help traverse through
**		this Space. This class inherits from class Space
*******************************************************************************/
#include <string>
#include <vector>

#include "space.hpp"

using std::string;
using std::vector;

#ifndef POND_HPP
#define POND_HPP

class Pond : public Space
{
	private:
		bool s4 = false;
		bool s5 = false;
		bool keyRod = false;
		bool keyTwig = false;
		bool keyA = false;
		bool keyStream = false;
	public:
		Pond();
		bool winCondition() override;
		void printSpace() override;
		string Scenario1(vector <int>&, bool, bool, bool) override;
		void Scenario2(vector <int>&, bool, bool, bool) override;
		void Scenario3(vector <int>&, bool, bool, bool) override;
		void Scenario4(vector<int>&, bool, bool, bool) override;
		void Scenario5(vector <int>&, bool, bool, bool) override;	

};
#endif
