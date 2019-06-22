/*******************************************************************************
** Program Name: Final Project - Text-based Game: space.hpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the header file for class Space, which contains data
**		members and Space pointers that will help traverse through
**		each Space (Room in the game)
*******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <vector>

using std::vector;
using std::string;

class Space
{
	protected:
		Space* top = nullptr;
		Space* bottom = nullptr;
		Space* left = nullptr;
		Space* right = nullptr;
		Space* up = nullptr;
		Space* down = nullptr;
		bool door;
		bool win;
		int roomID;
		int spaceTemp;

	public:
		Space();
		~Space();
		void setDoor(bool);
		bool getDoor();
		bool getWinCondition();
		int getRoomID();
		int updateTemp();
		virtual bool winCondition() = 0;	
		virtual void printSpace() = 0;
		virtual string Scenario1();
		virtual void Scenario2();
		virtual void Scenario2(vector<int>&);
		virtual string Scenario2a(vector<int>&);
		virtual void Scenario2(vector<int>&, bool, bool, bool);
		virtual string Scenario3();
		virtual void Scenario3(vector<int>&);
		virtual void Scenario3(vector<int>&, bool, bool, bool);
		virtual void Scenario4();
		virtual void Scenario4(vector<int>&);
		virtual void Scenario4(vector<int>&, bool, bool, bool);
		virtual void Scenario5();
		virtual void Scenario5(vector<int>&);
		virtual void Scenario5(vector<int>&, bool, bool, bool);
		virtual void Scenario6();
		virtual void Scenario6(vector<int>&);
		virtual void Scenario7();
		virtual void Scenario7(vector<int>&);
		virtual string Scenario1(vector<int> &);
		virtual string Scenario1(vector<int> &, bool, bool, bool);
		char getChoice(char);
		int intValidation(string);		

		void setTop(Space*);
		void setBottom(Space*);
		void setLeft(Space*);
		void setRight(Space*);
		void setUp(Space*);
		void setDown(Space*);
		Space* getTop();
		Space* getBottom();
		Space* getLeft();
		Space* getRight();
		Space* getUp();
		Space* getDown();


};
#endif
