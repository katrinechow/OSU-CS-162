/*******************************************************************************
** Program Name: Final Project - Text-based Game: mainhall.cpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the implementation file for class Mainhall, which is
**		an inherited class from Space.
*******************************************************************************/
#include "space.hpp"
#include "mainhall.hpp"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/*******************************************************************************
**				Mainhall::Mainhall()
** Description:	This is the default constructor of class Mainhall.
*******************************************************************************/
Mainhall::Mainhall()
{
	door = false;
	win = true; //Mainhall does not have mandatory tasks
	roomID = 1;
	spaceTemp = -1;
}


/*******************************************************************************
**				Mainhall::winCondition()
** Description:	This contains the gameflow required to complete the room.
*******************************************************************************/

bool Mainhall::winCondition()
{
	return win;

}


/*******************************************************************************
**				Mainhall::printSpace()
** Description:	This prints map with Mainhall as current location.
*******************************************************************************/
void Mainhall::printSpace()
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
"|    |                |   |    |                |    |  |                |    |\n"
"|    +----------------+   |    +-------+--------+    |  +----------------+    |\n"
"|                         |            |             |                        |\n"
"|                         |            |             |                        |\n"
"|                         |    +-------+--------+    |                        |\n"
"|                         |    |                |    |                        |\n"
"|                         +----+   Main Hall    +----+                        |\n"
"|                              |       *        |                             |\n"
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
**				Mainhall::Scenario1()
** Description:	This details the first scenario in space Mainhall.
*******************************************************************************/
string Mainhall::Scenario1(vector<int> &bag)
{
	
	const char MENU1MAX = '9';

	char ch = '9';

	do{

	int m1;

	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*  Main Hall  *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;

	cout << endl;

	cout << "The Main Hall is lighted by two windows and has a high ceiling"
	<< endl;
	cout << "Occasionally the roar of the wind adds to the mysteriousness"
		<< " of the space. The entryway looks well-trodden." << endl;
	cout << endl;
	cout << "You take a step forward and almost tripped over a low cabinet."
		<< " Several pairs of house slippers strewn out, along with "
		<< "a few baby rats that sought shelter from the cold. "
		<< "You say a silent thank you to your unknown host, and hope"
		<< " that you are not intruding." << endl;
	cout << "You decide to look around the room." << endl;
	cout << endl;
	cout << "A wooden staircare leads upward, possibly to a second floor."
		<< endl;
	cout << endl;
	cout << "A small [Toolbox] sits by the main double door. A [Fireplace] "
		<< "invites you to light it up." << endl;
	cout << endl;
	
	cout << "Rest easy, traveler." << endl;
	cout << endl;

	cout << "You Can:" << endl;
	cout << endl;
	cout << "1) Shut the main double door" << endl;
	cout << "2) Go down the East hallway" << endl;
	cout << "3) Go down the North hallway" << endl;
	cout << "4) Go down the West hallway" << endl;
	cout << "5) Go up the stairs" << endl;
	cout << "6) Examine the Toolbox" << endl;
	cout << "7) Examine the Fireplace" << endl;
	cout << "8) Check the Map" << endl;
	cout << "9) Exit the Main Hall" << endl;

	char mhchoice = getChoice(MENU1MAX);

	switch (mhchoice)
	{
		case '1':
		{
			cout << "You decide to shut the double door." << endl;
			cout << "You feel a little warmer. Body temp +1" << endl;
			spaceTemp = spaceTemp + 1;
			ch = '9';
			break;
		}

		case '2':
		{
			return "east";
			ch = '9';
			break;
		}

		case '3':
		{
			return "north";
			ch = '9';
			break;
		}

		case '4':
		{
			return "west";
			ch = '9';
			break;
		}
	
		case '5':
		{
			return "up";
			ch = '9';
			break;
		}
		case '6':
		{
	
			string choice =  Scenario2a(bag);
			if(choice == "home")
			{
				ch = '0';
			}
			break;
		}
	
		case '7':
		{
			Scenario3();
			ch = '9';
			break;

		}
		
		case '8':
		{
			printSpace();
			ch = '0';
			break;
		}

		case '9':
		{
			ch = '9';
			return "exit";
		}
		
	}

	}while (ch == '0');		
}



/*******************************************************************************
**				Mainhall::Scenario2()
** Description:	This branches off to choice 6
*******************************************************************************/
string Mainhall::Scenario2a(vector<int>& bag)
{
	int m2;

	cout << "*************" << endl;
	cout << "*           *" << endl;
	cout << "*  Toolbox  *" << endl;
	cout << "*           *" << endl;
	cout << "*************" << endl;
	cout << endl;
	cout << "A small toolbox lies opened by the door. In it are a "
		<< "[Hammer], a roll of [Duct Tape], and an [Axe]." << endl;
	cout << endl;
	cout << "You can:" << endl;
	cout << endl;
	if(!hammer)
	{
		cout << "1) Pick up the [Hammer]" << endl;
	}
	if (!tape)
	{
		cout << "2) Pick up the [Duct Tape]" << endl;
	}
	if (!axe)
	{
		cout << "3) Pick up the [Axe]" << endl;
	}
	cout << "4) Examine something else" << endl;
	cin >> m2;

	if(m2 == 1)
	{
		//Add Asset #205 Hammer to inventory
		bag.push_back(205);
		hammer = true;
		Scenario2(bag);
	}
	else if (m2 == 2) 
	{
		//Add Asset #206 Tape to inventory
		bag.push_back(206);
		tape = true;
		Scenario2(bag);
	}
	else if (m2 == 3)
	{
		//Add Asset #207 Axe to inventory
		bag.push_back(207);
		axe = true;
		Scenario2(bag);
	}
	else
	{
		return "home";
	}

}


/*******************************************************************************
**				Mainhall::Scenario3()
** Description:	This branches off to Scenario 7.
*******************************************************************************/
string Mainhall::Scenario3()
{	
	int m3;

	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*  Fireplace  *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;
	
	cout << "A few dried logs piled next to the fireplace. You have a "
		<< "lighter in your pack." << endl;
	cout << endl;
	
	cout << "You can:" << endl;
	cout << endl;
	cout << "1) Light the Fireplace (+1 to body temp)." << endl;
	cout << "2) Examine something else." << endl;
	cout << endl;
	
	if(m3 == 1)
	{
		cout << "You feel a little warmer!" << endl;
		spaceTemp = spaceTemp + 1;
		return "home";
	}
	else if (m3 == 1)
	{
		return "home";
	}
}

