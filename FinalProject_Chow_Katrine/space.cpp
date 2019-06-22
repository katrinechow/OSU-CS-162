/*******************************************************************************
** Program Name: Final Project - Text-based Game: space.cpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the implementation file for class Space. It
**		defines the various functions that control the flow of the game
*******************************************************************************/
#include "space.hpp"

#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

/*******************************************************************************
**				Space::Space
** Description:	This is the default constructor, which initializes the pointers
**		and values of class Space
*******************************************************************************/
Space::Space()
{
	door = false;
	roomID = 0;
	spaceTemp = 0;
}


/*******************************************************************************
**				Space::~Space
** Description:	This is the destructor of class Space. 
*******************************************************************************/
Space::~Space()
{
	delete top;
	top = nullptr;
	delete bottom;
	bottom = nullptr;
	delete left;
	left = nullptr;
	delete right;
	right = nullptr;
	delete up;
	up = nullptr;
	delete down;
	down = nullptr;
}

/*******************************************************************************
**				Space::updateTemp()
** Description: This function returns the spaceTemp variable to be subtracted
**		from the player's body temp.
*******************************************************************************/
int Space::updateTemp()
{
	return spaceTemp;
}

/*******************************************************************************
**				Space::setDoor(bool)
** Description:	This function updates a room door's status (opened or closed).
*******************************************************************************/
void Space::setDoor(bool d)
{
	door = d;
}


/*******************************************************************************
**				Space::getDoor()
** Description:	This function returns a room's door's status.
*******************************************************************************/
bool Space::getDoor()
{
	return door;
}


/*******************************************************************************
**				Space::getWinCondition()
** Description:	This function returns the current WinCondition status.
*******************************************************************************/
bool Space::getWinCondition()
{
	return win;
}


/*******************************************************************************
**				Space::getRoomID()
** Description:	This function returns the room ID for identifying the space
*******************************************************************************/
int Space::getRoomID()
{
	return roomID;
}

/*******************************************************************************
**				Space::setTop(Space*)
** Description:	This function sets the top pointer.
*******************************************************************************/
void Space::setTop(Space* sp)
{
	top = sp;
}


/*******************************************************************************
**				Space::setBottom(Space*)
** Description:	This function sets the bottom pointer.
*******************************************************************************/
void Space::setBottom(Space* sp)
{
	bottom = sp;
}


/*******************************************************************************
**				Space::setLeft(Space*)
** Description:	This function sets the left pointer.
*******************************************************************************/
void Space::setLeft(Space* sp)
{
	left = sp;
}


/*******************************************************************************
**				Space::setRight(Space*)
** Description:	This function sets the right pointer.
*******************************************************************************/
void Space::setRight(Space* sp)
{
	right = sp;
}


/*******************************************************************************
**				Space::setUp(Space)
** Description:	This function sets the up pointer.
*******************************************************************************/
void Space::setUp(Space* sp)
{
	up = sp;
}


/*******************************************************************************
**				Space::setDown(Space)
** Description:	This function sets the down pointer.
*******************************************************************************/
void Space::setDown(Space* sp)
{
	down = sp;
}

/*******************************************************************************
**				Space::getTop()
** Description:	This function returns top pointer.
*******************************************************************************/
Space* Space::getTop()
{
	return top;
}


/*******************************************************************************
**				Space::getBottom()
** Description:	This function returns bottom pointer.
*******************************************************************************/
Space* Space::getBottom()
{
	return bottom;
}


/*******************************************************************************
**				Space::getLeft()
** Description:	This function returns left pointer;
*******************************************************************************/
Space* Space::getLeft()
{
	return left;
}


/*******************************************************************************
**				Space::getRight()
** Description:	This function returns right pointer.
*******************************************************************************/
Space* Space::getRight()
{
	return right;
}


/*******************************************************************************
**				Space::getUp()
** Description:	This function returns up pointer.
*******************************************************************************/
Space* Space::getUp()
{
	return up;
}


/*******************************************************************************
**				Space::getDown()
** Description:	This function returns down pointer.
*******************************************************************************/
Space* Space::getDown()
{
	return down;
}

/*******************************************************************************
 * **                      char Space::getChoice(char)
 * ** Description: This function collects user's choice.
 * *******************************************************************************/

char Space::getChoice(char max)
{
        char choice = cin.get();
        cin.ignore();

        while (choice < '0' || choice > max)
        {
                cout << "Please enter a valid number from 1 to " << max << endl;
                choice = cin.get();
                cin.ignore();
        }

        return choice;
}


/*******************************************************************************
 * **                      int Space::intValidation(string)
 * ** Description: This function serves as input validation for integers. I
 * **              references SkyeShatter's YouTube video at:
 * **              https://youtube.com/watch?v=S3_jCTb3fm0  , as well as @86 on
 * **              Piazza.
 * *******************************************************************************/

int Space::intValidation(string s)
{
        string str;
        int valid;
        bool flag = false;

        while(flag == false)
        {
                cout << s << endl;
                getline(cin, str);
                stringstream ss(str);

                if (ss >> valid && !(ss >> str)) //Referenced Piazza @86
                {
                        flag = true;
                }

                else
                {
                        cout << ">>> Please enter an integer only <<< " << endl;
                        cout << endl;
                }

        }


        return valid;
}


/*******************************************************************************
**				Space::Misc
** Description: Holder of virtual function definitions.
*******************************************************************************/
string Space::Scenario1() {};
string Space::Scenario1(vector<int> & b){};
string Space::Scenario1(vector<int> &b , bool h, bool t, bool a){};
void Space::Scenario2() {};
void Space::Scenario2(vector<int>& b) {};
string Space::Scenario2a(vector<int>& b) {};
void Space::Scenario2(vector<int>& b, bool h, bool t, bool a) {};
string Space::Scenario3() {};
void Space::Scenario3(vector<int>& b) {};
void Space::Scenario3(vector<int>& b, bool h, bool t, bool a) {};
void Space::Scenario4() {};
void Space::Scenario4(vector<int>& b){};
void Space::Scenario4(vector<int>& b, bool h, bool t, bool a){};
void Space::Scenario5(){};
void Space::Scenario5(vector<int>& b){};
void Space::Scenario5(vector<int>& b, bool h, bool t, bool a){};
void Space::Scenario6(){};
void Space::Scenario6(vector<int>& b){};
void Space::Scenario7(){};
void Space::Scenario7(vector<int>& b){};
