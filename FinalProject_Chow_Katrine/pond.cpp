/*******************************************************************************
** Program Name: Final Project - Text-based Game: pond.cpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the implementation file for class Pond, which is
**		an inherited class from Space.
*******************************************************************************/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "space.hpp"
#include "pond.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*******************************************************************************
**				Pond::Pond()
** Description:	This is the default constructor of class Mainhall.
*******************************************************************************/
Pond::Pond()
{
	door = false;
	win = false;
	roomID = 4;
	spaceTemp = -2;
}


/*******************************************************************************
**				Pond::winCondition()
** Description:	This contains the gameflow required to complete the room.
*******************************************************************************/

bool Pond::winCondition()
{
	if(s4 && s5)
	{
		win = true;
	}

	return win;

}


/*******************************************************************************
**				Pond::printSpace()
** Description:	This funtion prints map with Pond as current location.
*******************************************************************************/
void Pond::printSpace()
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
"|    |                |   |    |       *        |    |  |                |    |\n"
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
**				Pond::Scenario1()
** Description:	This details the first scenario in space Pond.
*******************************************************************************/
string Pond::Scenario1(vector <int>& bag, bool axe, bool hammer, bool tape)
{
	const char MENU1MAX = '6';
	char ch = '9';

	do{

	int p1;

	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*     Pond    *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;

	cout << endl;
	cout << "The North hallway leads to an unlocked glass door. Beyond it "
		<< "is a frozen pond surrounded by dirt that was once a fairly "
		<< "manicured lawn. A few broken lounge chairs lined the pond. "
		<< "A small swing set sits in a corner, covered with thick "
		<< "layers of snow." << endl;
	cout << endl;
	cout << "By the pond is a [Fishing Rod] and a small ice chest. A "
		<< "broken [Do Not Feed Sign], and a [Twig] lie on the ground"
		<< endl;
	cout << endl;
	cout << "You shiver from the cold. Your body temperature drops by 2!"
		<< endl;
	spaceTemp = spaceTemp - 2;

	cout << "You Can:" << endl;
	cout << endl;
	if(!keyRod)
	{
		cout << "1) Examine the [Fishing Rod]." << endl;
	}
	if(!keyTwig)
	{
		cout << "2) Examine the [Twig]." << endl;
	}
	if(!keyA)
	{
		cout << "3) Try Fishing." << endl;
	}
	if(!keyStream)
	{
		cout << "4) Repair the [Do Not Feed Sign]." << endl;
	}

	cout << "5) Check the Map" << endl;
	cout << "6) Return to the Main Hall." << endl;
	
	char pchoice = getChoice(MENU1MAX);

	switch(pchoice)
	{
		case '1':
		{
			Scenario2(bag, axe, hammer, tape);
			ch = '9';
			break;
		}
		case '2':
		{
			Scenario3(bag, axe, hammer, tape);
			ch = '9';
			break;
		}
		case '3':
		{
			Scenario4(bag, axe, hammer, tape);
			ch = '9';
			break;
		}
		case '4':
		{
			Scenario5(bag, axe, hammer, tape);
			ch = '9';
			break;
		}
		case '5':
		{
			printSpace();
			ch = '0';
			break;
		}
		case '6':
		{
			return "home";
		}
	}
	}while(ch == '0');
				
}


/*******************************************************************************
**				Pond::Scenario2()
** Description:	This is the gameplay for Scenario 2 in Pond.
*******************************************************************************/
void Pond::Scenario2(vector <int> & bag, bool axe, bool hammer, bool tape)
{

	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*     Rod     *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;
	cout << "The fishing tod is shoddily made, and looks more like a "
		<< "child's toy than a functional tool." << endl;
	cout << endl;
	cout << "Perhaps you can try fishing." << endl;
	cout << endl;
	cout << "You pick up the [Fishing Rod]!" << endl;
	bag.push_back(208);
	cout << endl;
	keyRod = true;

	Scenario1(bag, axe, hammer, tape);	
}

/*******************************************************************************
**				Pond::Scenario3()
** Description:	This branches off to choice 3.
*******************************************************************************/
void Pond::Scenario3(vector <int>& bag, bool axe, bool hammer, bool tape)
{
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*     Twig    *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;
	cout << "The twig is covered by bite marks. No clue whether it is from"
		<< " a child or from a pet." << endl;
	cout << endl;
	cout << "You pick up the [Twig]!" << endl;
	bag.push_back(209);
	keyTwig = true;

	Scenario1(bag, axe, hammer, tape);
}


/*******************************************************************************
**				Pond::Scenario4()
** Description:	This branches off to choice 4
*******************************************************************************/
void Pond::Scenario4(vector <int>& bag, bool axe, bool hammer, bool tape)
{
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*   Fishing   *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;
	cout << "You examine the frozen pond." << endl;
	cout << endl;
	
	if(!axe || !keyRod)
	{
		cout << "You will need something to break the ice." << endl;
	}
	else
	{
		cout << "You lift the axe high above you and slashed at the "
			<< "ice, Samurai Style." << endl;
		cout << endl;
		cout << "The ice cracks!" << endl;
		cout << endl;
		std::chrono::seconds ptime(3);
		cout << "You threw the fishing rod in and waited..." << endl;
		cout << endl;
		cout << "Body Temp drops by 2!" << endl;
		spaceTemp = spaceTemp - 2;
		std::this_thread::sleep_for(ptime);

		cout << endl;
		cout << "Body Temp drops by 2!" << endl;
		spaceTemp = spaceTemp - 2;
		std::this_thread::sleep_for(ptime);
		
		cout << endl;
		cout << "Body Temp drops by 2!" << endl;
		spaceTemp = spaceTemp - 2;
		std::this_thread::sleep_for(ptime);
		cout << endl;
		cout << "The line caught something!" << endl;
		cout << endl;
		cout << "You reeled it up and scoffed that it is only a "
			<< "crumpled piece of paper." << endl;
		cout << endl;
		cout << "You receive Key Item [a]!" << endl;
		bag.push_back(101);
		keyA = true;
		s4 = true;
	}

	Scenario1(bag, axe, hammer, tape);
}


/*******************************************************************************
**				Pond::Scenario5()
** Description:	This branches off to choice 5
*******************************************************************************/
void Pond::Scenario5(vector<int> & bag, bool axe, bool hammer, bool tape)
{
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*     Sign    *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;

	cout << "The [Do Not Feed Sign] was blown over by the strong winds. "
		<< "Somehow you feel compelled to repair it." << endl;
	cout << endl;

	if(!hammer || !tape)
	{
		cout << "You may need something else to finish this task."
			<< endl;
	}
	else
	{
		cout << "You remember that you  have tape in your pack. Now "
			<< "you just need something to make the sign stand "
			<< "upright." << endl;
		cout << endl;
		cout << "You think you can make something with the tools and "
			<< "the twig you found on the ground." << endl;
		cout << endl;
		cout << "You pulled out a piece of [Duct Tape]. You stuck one "
			<< "end of the tape on the sign, and the other end on "
			<< "the twig." << endl;
		cout << endl;
		cout << "You repeat this 5 more times." << endl;
		cout << endl;
		cout << "Finally, you hammered the sign to the dirt." << endl;
		cout << endl;
		cout << "Your body temp drops by 2!" << endl;
		spaceTemp = spaceTemp - 2;
		cout << endl;
		cout << "You receive Key Item [<iostream>]!" << endl;
		keyStream = true;
		bag.push_back(109);
		s5 = true;
	}

	Scenario1(bag, axe, hammer, tape);
}

