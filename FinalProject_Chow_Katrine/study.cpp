/*******************************************************************************
** Program Name: Final Project - Text-based Game: study.cpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the implementation file for class Study, which is
**		an inherited class from Space.
*******************************************************************************/

#include <iostream>
#include <string>

#include "space.hpp"
#include "study.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*******************************************************************************
**				Study::Study()
** Description:	This is the default constructor of class Study.
*******************************************************************************/
Study::Study()
{
	door = false;
	win = false;
	roomID = 5;
	spaceTemp = 0;
}



/*******************************************************************************
**				Study::winCondition()
** Description:	This contains the gameflow required to complete the room.
*******************************************************************************/

bool Study::winCondition()
{
	if(s2 && s4 && s5 && s6)
	{
		win = true;
	}

	return win;

}


/*******************************************************************************
**				Study::printSpace()
** Description:	This function prints map with Study as current location.
*******************************************************************************/
void Study::printSpace()
{
	cout <<
"+-----------------------------------------------------------------------------+\n"
"|                                                                             |\n"
"|                                                                             |\n"
"|       ROOM MAP                                                              |\n"
"|                             +----------------+                              |\n"
"|                             |                |                              |\n"
"|                             |     Study      |                              |\n"
"|                             |       *        |                              |\n"
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
**				Study::Scenario1()
** Description:	This details the first scenario in space Study.
*******************************************************************************/
string Study::Scenario1(vector <int>& bag)
{
	const char MENU1MAX = '6';
	char ch = '9';

	do{

	int st1;

	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*    Study    *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;

	cout << "The wooden steps creak as you put your weight on them. The "
		<< "paint on the railing chips away as soon as you lay your "
		<< "hands on it." << endl;
	cout << endl;
	cout << "At the top of the stairs is another room. The door is wide "
		<< "open." << endl;
	cout << endl;
	cout << "You step into what looks like a study. A dusty [Desk] sits to "
		<< "your left. Massive cherry-wood [Bookcases] line the wall to"
		<< " your right. A grand [Piano] is installed in the back of "
		<< "room, standing majestic on a plush royal red rug." << endl;
	cout << endl;
	cout << "There are surprisingly no windows at all. No wonder the door "
		<< "is kept open." << endl;
	cout << endl;
	cout << "At the center of the ceiling, where a skylight would've made "
		<< "sense, is a wooden panel with a metal ring luring you to "
		<< "pull it. You moved a chair underneath and tugged at the "
		<< "ring until the panel loosens. A ladder gently lowers until"
		<< " its base reaches the floor. A few more baby rats scurried "
		<< "down the ladder. One might've hit your head before "
		<< "tumbling down the steps." << endl;
	cout << endl;

	cout << "You can:" << endl;
	cout << endl;
	if(!keyLight)
	{
		cout << "1) Examine the [Desk]" << endl;
	}
	if(!keyC || !keyPass || !keySheets || !keyDir)
	{
		cout << "2) Examine the [Bookcases]" << endl;
	}
	cout << "3) Examine the [Piano]" << endl;
	if(winCondition())
	{
		cout << "4) Examine the [Ladder]" << endl;
	}
	cout << "5) Check the Map" << endl;
	cout << "6) Return to the Main Hall" << endl;

	char schoice = getChoice(MENU1MAX);

	switch(schoice)
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
			Scenario6(bag);
			ch = '9';
			break;
		}
		case '4':
		{
			return "attic";
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
**				Study::Scenario2()
** Description:	This is the gameplay for Scenario 2 in Study.
*******************************************************************************/
void Study::Scenario2(vector <int>& bag)
{
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*    Desk     *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;

	cout << "A normal work desk with a small pile of books on one end, and"
		<< " a few photo frames on the other." << endl;
	cout << endl;
	cout << "A [Flashlight] lies on the surface.  You turned it on. Seems "
		<< "like the battery is still charged. You turned it off to "
		<< "conserve the battery." << endl;
	cout << endl;
	cout << "You receive Key Item [Flashlight]!" << endl;
	keyLight = true;
	bag.push_back(212);
	s2 = true;

	Scenario1(bag);
}

/*******************************************************************************
**				Study::Scenario3()
** Description:	This branches off to choice 3.
*******************************************************************************/
void Study::Scenario3(vector <int>& bag)
{
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*  Bookcases  *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;

	cout << "The bookcases are almost as tall as the ceiling. Books of "
		<< "various colors, sizes, and thickness are organized by "
		<< "the authors' name." << endl;
	cout << endl;
	cout << "A large [Hardcover] on a top shelf catches your attention, so "
		<< "do a few sheets that peek out from an otherwise neatly "
		<< "organized lower shelf. A [Diary] is tucked into a crevice "
		<< "in between the bookcases." << endl;
	cout << endl;
	int st3;
	cout << "You can: " << endl;
	cout << endl;

	if(!keyC || !keyPass)
	{
		cout << "1) Examine the [Hardcover]" << endl;
	}
	if(!keySheets)
	{
		cout << "2) Examine the [Sheets]" << endl;
	}
	if(!keySym)
	{
		cout << "3) Examine the [Diary]" << endl;
	}
	cout << "4) Examine something else" << endl;
	cin >> st3;

	if(st3 == 1)
	{
		Scenario4(bag);
	}
	else if (st3 == 2)
	{
		Scenario5(bag);
	}
	else if (st3 == 3)
	{
		Scenario7(bag);
	}
	else
	{
		Scenario1(bag);
	}
}


/*******************************************************************************
**				Study::Scenario4()
** Description:	This branches off to choice 4
*******************************************************************************/
void Study::Scenario4(vector <int>& bag)
{
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*  Hardcover  *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;

	cout << "You propped yourself up with a chair and picked out the large "
		<< "[Hardcover]. \"A Brief History of TIme\" by Stephen "
		<< "Hawking." << endl;
	cout << endl;
	cout << "You receive Key Item [c]!" << endl;
	keyC = true;
	bag.push_back(103);
	cout << "You receive Key Item [Password]]!" << endl;
	keyPass = true;
	bag.push_back(110);

	s4 = true;
	
	Scenario1(bag);
}


/*******************************************************************************
**				Study::Scenario5()
** Description:	This branches off to choice 5
*******************************************************************************/
void Study::Scenario5(vector <int>& bag)
{
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*    Sheets   *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;
	cout << "You carefully pulled out the loose sheets to discover that "
		<< "they are handwritten music pieces." << endl;
	cout << endl;
	cout << "It's been awhile since you've played an instrument, but "
		<< "perhaps it's worth a try? After all, you are trapped in "
		<< "the snow with nowhere else to go." << endl;
	cout << endl;
	cout << "You received [Sheets]!" << endl;
	keySheets = true;
	bag.push_back(210);
	int st5;
	cout << "You can:" << endl;
	cout << endl;
	cout << "1) Examine the [Piano]" << endl;
	cout << "2) Examine something else" << endl;
	cin >> st5;

	if (st5 == 1)
	{
		Scenario6(bag);
	}
	else if (st5 == 2)
	{
		Scenario1(bag);
	}

}


/*******************************************************************************
**				Study::Scenario6()
** Description:	This branches off to choice 6
*******************************************************************************/
void Study::Scenario6(vector<int>& bag)
{
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*    Piano    *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;
	cout << "The grand piano needs a bit of polish, but otherwise looks "
		<< "brand new. It doesn't seem like anyone has played it "
		<< "recently." << endl;
	cout << endl;

	if (!keySheets)
	{
		cout << "You need something else to complete this task." << endl;
	}
	else
	{
		cout << "It is a rough start. The symbols are just mumble-"
			<< "jumble in your brain, and your eyes start to blur."
			<< " You shake your head to refocus your attention." 
			<< endl;
		cout << endl;
		cout << "After awhile, muscle memory takes over and you are "
			<< "playing a happy little tune. You smile at the "
			<< "dexterity of your fingers." << endl;
		cout << endl;
		cout << "You receive Key Item [<<]!" << endl;
		keyDir = true;
		bag.push_back(106);
		s5 = true;
	}

	Scenario1(bag);
}


/*******************************************************************************
**				Study::Scenario7()
** Description:	This branches off to choice 7.
*******************************************************************************/
void Study::Scenario7(vector<int>& bag)
{

	cout << "*************" << endl;
	cout << "*           *" << endl;
	cout << "*   Diary   *" << endl;
	cout << "*           *" << endl;
	cout << "*************" << endl;
	cout << endl;
	cout << "An old diary is hastily stuffed in between two bookcases. "
		<< "There are ineligible scribbles on the first few pages." 
		<< endl;
	cout << endl;
	cout << "You curiously turned the book over, and discover a symbol "
		<< "you've learned to both love and hate." << endl;
	cout << endl;
	cout << "You receive Key Item [;]!" << endl;
	keySym = true;
	bag.push_back(108);
	s6 = true;
	cout << endl;

	Scenario1(bag);
}
