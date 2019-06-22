/*******************************************************************************
** Program Name: Final Project - Text-based Game: kitchen.cpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the implementation file for class Kitchen, which is
**		an inherited class from Space.
*******************************************************************************/

#include <iostream>
#include <string>

#include "space.hpp"
#include "kitchen.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*******************************************************************************
**				Kitchen::Kitchen()
** Description:	This is the default constructor of class Kitchen.
*******************************************************************************/
Kitchen::Kitchen()
{
	door = false;
	win = false;
	roomID = 2;
	spaceTemp = -1;
}


/*******************************************************************************
**				Kitchen::winCondition()
** Description:	This contains the gameflow required to complete the room.
*******************************************************************************/

bool Kitchen::winCondition()
{
	if(s2 && s3)
	{
		win = true;
	}
	else
	{
		win = false;
	}

	return win;

}


/*******************************************************************************
**				Kitchen::printSpace()
** Description:	This funciton prints the map with Kitchen as current location.
*******************************************************************************/
void Kitchen::printSpace()
{
	cout <<
"+-----------------------------------------------------------------------------+\n"
"|                                                                             |\n"
"|                                                                             |\n"
"|       ROOM MAP                                                              |\n"
"|                             +----------------+                              |\n"
"|                             |                |                              |\n"
"|                             |     Study      |                              |\n"
"|                             |                |                              |\n"
"|                             +--------+-------+                              |\n"
"|                                      |                                      |\n"
"|                                      |                                      |\n"
"|    +----------------+        +-------+--------+       +----------------+    |\n"
"|    |                |        |                |       |                |    |\n"
"|    |     Kitchen    +---+    |     Pond       |    +--+      Gym       |    |\n"
"|    |        *       |   |    |                |    |  |                |    |\n"
"|    +----------------+   |    +-------+--------+    |  +----------------+    |\n"
"|                         |            |             |                        |\n"
"|                         |            |             |                        |\n"
"|                         |    +-------+--------+    |                        |\n"
"|                         |    |                |    |                        |\n"
"|                         +----+   Main Hall    +----+                        |\n"
"|                              |                |                             |\n"
"|                              +----------------+                             |\n"
"|                                                                             |\n"
"|   * = You Are Here                                                          |\n"
"|                                                                             |\n"
"+-----------------------------------------------------------------------------+\n";

	cout << endl;
	cout << endl;
	cout << endl;
}


/*******************************************************************************
**				Kitchen::Scenario1()
** Description:	This details the first scenario in space Kitchen.
*******************************************************************************/
string Kitchen::Scenario1(vector <int>& bag)
{
	const char MENU1MAX = '4';
	char ch = '9';

	do{

	int k1;

	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*   Kitchen   *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;

	cout << endl;
	cout << "The East hallway leads you to an unlocked door. You open it to"
		<< " discover a well-stocked kitchen." << endl;
	cout << "A sudden but gentle \"meow~\" catch your attention. A stray "
		<< "kitten poked its head from the pantry." << endl;
	cout << endl;
	cout << "You open the pantry and find a few jars of pickles." << endl;
	cout << "You offer the pickles to the kitten, but it looks "
		<< "uninterested." << endl;
	cout << endl;
	cout << "You are thirsty. You looked at the pickled juice for a moment "
		<< "and decide to explore other options." << endl;
	cout << endl;
	cout << "You try to turn on the faucet at the sink. It is broken."
		<< endl;
	cout << endl;

	cout << "You Can:" << endl;
	cout << endl;
	if(!keyCout)
	{
		cout << "1) Examine the sink" << endl;
	}
	if(!keyD)
	{
		cout << "2) Pet the kitten" << endl;
	}
	cout << "3) Check the Map" << endl;
	cout << "4) Return to the Main Hall" << endl;
	
	char kchoice = getChoice(MENU1MAX);

	switch(kchoice)
	{

		case '1':
		{
			Scenario2(bag);
			ch = '9';
			break;
		}
		case '2':
		{
			Scenario3(bag);
			ch = '9';
			break;
		}
		case '3':
		{
			printSpace();
		}
		case '4':
		{
			return "home";
		}		
	}		
	}while (ch == '0');
}


/*******************************************************************************
**				Kitchen::Scenario2()
** Description:	This is the gameplay for Scenario 2.
*******************************************************************************/
void Kitchen::Scenario2(vector<int> & bag)
{
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*     Sink    *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;

	cout << "The sink is lined with cracks. You open the cabinet "
		<< "underneath and find rusted pipes." << endl;
	cout << endl;
	cout << "Half a bottle of whiskey is hidden in a corner. You think "
		<< "about taking a swig." << endl;
	cout << endl;
	cout << "Beneath the bottle is a crumpled piece of paper." << endl;
	cout << "You receive Key Item [cout]!" << endl;
	keyCout = true;

	cout << endl;

	int k2;

	cout << "You can:" << endl;
	cout << endl;
	cout << "1) Take the whiskey" << endl;
	cout << "2) Examine something else" << endl;
	cin >> k2;

	if(k2 == 1)
	{
		cout << "You sipped the amber liquid. You feel a little"
			<< " warmer." << endl;
		spaceTemp = spaceTemp + 1;
		s2 = true;
		Scenario1(bag);
	}
	else if (k2 == 2)
	{
		Scenario1(bag);
	}

}

/*******************************************************************************
**				Kitchen::Scenario3()
** Description:	This branches off to choice 3.
*******************************************************************************/
void Kitchen::Scenario3(vector<int> &bag)
{

	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*    Kitten   *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;

	cout << "The baby cat meows and rubs its head on your legs. It is love"
		<< " at first sight!" << endl;
	cout << endl;
	cout << "You decide to name it Maggie. You playfully tickled its belly."
		<< endl;
	cout << "Maggie meows and heads to the pantry. After awhile, it returns "
		<< "to you with a gift." << endl;
	cout << endl;
	
	cout << "You receive Key Item [d]!" << endl;
	keyD = true;
	s3 = true;

	cout << endl;
	cout << endl;
	cout << endl;

	Scenario1(bag);
}

