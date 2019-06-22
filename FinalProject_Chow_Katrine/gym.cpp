/*******************************************************************************
** Program Name: Final Project - Text-based Game: gym.cpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the implementation file for class Gym, which is
**		an inherited class from Space.
*******************************************************************************/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "space.hpp"
#include "gym.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
//using std::chrono;
//using std::this_thread;

/*******************************************************************************
**				Gym::Gym()
** Description:	This is the default constructor of class Gym.
*******************************************************************************/
Gym::Gym()
{
	door = false;
	win = false;
	roomID = 3;
	spaceTemp = -1;
}


/*******************************************************************************
**				Gym::winCondition()
** Description:	This contains the gameflow required to complete the room.
*******************************************************************************/

bool Gym::winCondition()
{
	if(s3 && s5)
	{
		win = true;
	}

	return win;

}


/*******************************************************************************
**				Gym::printSpace()
** Description:	This function prints map with Gym as current location.
*******************************************************************************/
void Gym::printSpace()
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
"|    |                |   |    |                |    |  |       *        |    |\n"
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
**				Gym::Scenario1()
** Description:	This details the first scenario in space Gym.
*******************************************************************************/
string Gym::Scenario1(vector <int>& bag)
{
	const char MENU1MAX = '5';
	char ch = '9';

	do{

	int g1;

	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*     Gym     *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;

	cout << endl;
	cout << "The West Hallway takes you to a spacious home gym. You welcome"
		<< " the natural light coming in from the window, and marvel at"
		<< " the old ceiling fan that seems to still be in working "
		<< "order." << endl;
	cout << endl;
	cout << "There is a [Treadmill], a rack of [Hand Weights] in need of "
		<< "cleanup, and a [Mirror]." << endl;
	cout << endl;

	cout << "You Can:" << endl;
	cout << endl;
	cout << "1) Run on the [Treadmill]." << endl;
	cout << "2) Rearrange [Hand Weights]." << endl;
	cout << "3) Squat in front of the [Mirror]." << endl;
	cout << "4) Check the Map" << endl;
	cout << "5) Return to the Main Hall." << endl;

	char gchoice = getChoice(MENU1MAX);

	switch(gchoice)
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
			Scenario4(bag);
			ch = '9';
			break;
		}
		case '4':
		{
			printSpace();
			ch = '0';
			break;
		}
		case '5':
		{
			return "home";
		}
	}

	}while (ch == '0');		
}


/*******************************************************************************
**				Gym::Scenario2()
** Description:	This is the gameplay for Scenario 2 in Gym.
*******************************************************************************/
void Gym::Scenario2(vector <int>& bag)
{
	
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*  Treadmill  *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;
	cout << "The elevation makes it difficult to breathe, but you began a "
		<< "slow job on the [Treadmill]." << endl;
	cout << endl;
	cout << "You feel a little warmer!" << endl;
	spaceTemp = spaceTemp + 1;
	cout << endl;
	int g2;
	cout << "You can:" << endl;
	cout << "1) Jog again" << endl;
	cout << "2) Examine something else" << endl;
	cin >> g2;

	if(g2 == 1)
	{
		Scenario2(bag);
	}
	else if (g2 == 2)
	{
		Scenario1(bag);
	}

}

/*******************************************************************************
**				Gym::Scenario3()
** Description:	This branches off to choice 3.
*******************************************************************************/
void Gym::Scenario3(vector <int>& bag)
{
	
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*   Weights   *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;

	cout << "You haven't weight-trained in years. The 50lb dumbbell seems "
		<< "daunting. You carefully rearranged the weights from "
		<< "lightest to heaviest." << endl;
	cout << endl;
	cout << "You receive Key Item [b]!" << endl;
	cout << endl;
	keyB = true;
	bag.push_back(102);
	s3 = true;
	
	int g3;
	cout << "You can:" << endl;
	cout << "1) Examine something else." << endl;
	cin >> g3;

	if(g3 == 1)
	{
		Scenario1(bag);
	}
}


/*******************************************************************************
**				Gym::Scenario4()
** Description:	This branches off to choice 4
*******************************************************************************/
void Gym::Scenario4(vector <int>& bag)
{
	
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*    Mirror   *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;

	cout << "Your ex-wife, Mary, was a gym rat. She would've loved to take "
		<< "a photo in front of this large mirror." << endl;
	cout << endl;
	cout << "She is probably working out at some rich man's mansion right "
		<< "now." << endl;
	cout << endl;
	cout << "You are not bitter." << endl;
	cout << endl;
	
	cout << "You wonder if you can still do a perfect squat." << endl;
	cout << endl;
	cout << "You can:" << endl;

	int g4;

	cout << "1) Perform squats" << endl;
	cout << "2) Examine something else" << endl;
	cin >> g4;

	if(g4 == 1)
	{
		Scenario5(bag);
	}
	else if (g4 == 2)
	{
		Scenario1(bag);
	}

}


/*******************************************************************************
**				Gym::Scenario5()
** Description:	This branches off to choice 5. Using <chrono> and <thread> for
**		cout delays references the following StackOverflow thread:
**		https://stackoverflow.com/questions/23609507/pause-program-
**		execution-for-5-seconds-in-c"
*******************************************************************************/
void Gym::Scenario5(vector <int>& bag)
{
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*    Squats   *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;
	cout << "You drop your rear end as if sitting in a chair." << endl;
	cout << "You make sure your knees are at 90 degrees." << endl;
	cout << endl;
	std::chrono::seconds ptime(3);
	cout << "Huff..." << endl;
	std::this_thread::sleep_for(ptime);
	cout << "Puff..." << endl;
	std::this_thread::sleep_for(ptime);
	cout << "Huff..." << endl;
	std::this_thread::sleep_for(ptime);
	cout << "Huff..." << endl;
	std::this_thread::sleep_for(ptime);
	cout << "Huff..." << endl;
	std::this_thread::sleep_for(ptime);
	cout << "Huff..." << endl;
	std::this_thread::sleep_for(ptime);
	cout << "Puff..." << endl;
	std::this_thread::sleep_for(ptime);
	cout << "Puff..." << endl;
	std::this_thread::sleep_for(ptime);
	cout << "Puff..." << endl;
	std::this_thread::sleep_for(ptime);
	cout << "Puff..." << endl;
	std::this_thread::sleep_for(ptime);
	cout << endl;
	cout << "You feel a little warmer!" << endl;
	spaceTemp = spaceTemp + 1;
	cout << endl;
	if (!keyMake)
	{
		cout << "You received Key Item [makefile]!" << endl;
		keyMake = true;
		bag.push_back(107);
		s5 = true;
		cout << endl;
	}

	int g5;
	cout << "You can:" << endl;
	cout << endl;
	cout << "1) Do More Squats" << endl;
	cout << "2) Examine something else" << endl;
	cin >> g5;
	
	if(g5 == 1)
	{
		Scenario5(bag);
	}
	else if (g5 == 2)
	{
		Scenario1(bag);
	}

}
