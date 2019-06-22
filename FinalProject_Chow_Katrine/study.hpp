/*******************************************************************************
** Program Name: Final Project - Text-based Game: study.hpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the header file for class Study, which contains data
**		members and Space pointers that will help traverse through
**		this Space. This class inherits from class Space
*******************************************************************************/
#include <string>
#include <vector>

#include "space.hpp"

using std::string;
using std::vector;

#ifndef STUDY_HPP
#define STUDY_HPP

class Study : public Space
{
	private:
		bool keyLight = false;
		bool keyC = false;
		bool keyPass = false;
		bool keySheets = false;
		bool keyDir = false;
		bool keySym = false;
		bool s2 = false;
		bool s4 = false;
		bool s5 = false;
		bool s6 = false;
		
	public:
		Study();
		bool winCondition() override;	
		void printSpace() override;
		string Scenario1(vector<int>&);
		void Scenario2(vector<int>&) override;
		void Scenario3(vector<int>&) override;
		void Scenario4(vector<int>&) override;
		void Scenario5(vector<int>&) override;
		void Scenario6(vector<int>&) override;
		void Scenario7(vector<int>&) override;

};
#endif
