/*******************************************************************************
** Program Name: Final Project - Text-based Game: gym.hpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the header file for class Gym, which contains data
**		members and Space pointers that will help traverse through
**		this Space. This class inherits from class Space
*******************************************************************************/
#include <string>
#include <vector>

#include "space.hpp"

using std::vector;
using std::string;

#ifndef GYM_HPP
#define GYM_HPP

class Gym : public Space
{
	private:
		bool s3 = false;
		bool s5 = false;
		bool keyB = false;
		bool keyMake = false;

	public:
		Gym();
		bool winCondition() override;
		void printSpace() override;	
		string Scenario1(vector <int>&);
		void Scenario2(vector <int>&) override;
		void Scenario3(vector <int>&) override;
		void Scenario4(vector <int>&) override;
		void Scenario5(vector <int>&) override;

};
#endif
