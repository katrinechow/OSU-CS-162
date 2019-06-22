/*******************************************************************************
** Program Name: Final Project - Text-based Game: attic.cpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the implementation file for class Attic, which is
**		an inherited class from Space.
*******************************************************************************/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "space.hpp"
#include "attic.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*******************************************************************************
**				Attic::Mainhall()
** Description:	This is the default constructor of class Attic.
*******************************************************************************/
Attic::Attic()
{
	door = false;
	win = false;
	roomID = 6;
	spaceTemp = 0;
}


/*******************************************************************************
**				Attic::winCondition()
** Description:	This contains the gameflow required to complete the room.
*******************************************************************************/

bool Attic::winCondition()
{
	return win;

}


/*******************************************************************************
**				Attic:printSpace()
** Description:	This function prints map with Attic as current location.
*******************************************************************************/
void Attic::printSpace()
{
	cout <<
"+-----------------------------------------------------------------------------+\n"
"|                                                      +----------------+     |\n"
"|                                                      |                |     |\n"
"|       ROOM MAP                                   +---+     Attic      |     |\n"
"|                             +----------------+   |   |       *        |     |\n"
"|                             |                |   |   +----------------+     |\n"
"|                             |     Study      +---+                          |\n"
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
**				Attic::Scenario1()
** Description:	This details the first scenario in space Mainhall.
*******************************************************************************/
string Attic::Scenario1()
{
	const char MENU1MAX = '3';
	char ch = '9';

	int a1;

	do{

	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*    Attic    *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;
	
	cout << "The ladder leads up to an attic space. A faint "
		<< "artificial glow emanates from a machine humming "
		<< "somewhere." << endl;
	cout << endl;
	cout << "You turned on the flash light to better see what is in "
		<< "the attic. An old [Coomputer] spews audio "
		<< "nonsense into the dusty, musky air. The dome-"
		<< "shaped ceiling calls out to you." << endl;
	cout << endl;
	cout << "You can: " << endl;
	cout << endl;
	cout << "1) Examine the computer" << endl;
	cout << "2) Check the Map" << endl;
	cout << "3) Return to the Main Hall" << endl;
	
	char achoice = getChoice(MENU1MAX);

	switch(achoice)
	{
		case '1':
		{
			Scenario2();
			ch = '9';
			break;
		}
		case '2':
		{
			printSpace();
			ch = '0';
			break;
		}
		case '3':
		{
			return "home";
		}
	}
	}while(ch == '0');

				
}


/*******************************************************************************
**				Attic::Scenario2()
** Description:	This is the gameplay for Scenario 2 in Attic.
*******************************************************************************/
void Attic::Scenario2()
{
	cout << "***************" << endl;
	cout << "*             *" << endl;
	cout << "*   Computer  *" << endl;
	cout << "*             *" << endl;
	cout << "***************" << endl;
	cout << endl;
	cout << "An old desktop and CRT monitor combo. This is a treasure from "
		<< "the old days. This would belong in a museum." << endl;
	cout << endl;
	cout << "The power cord is plugged in, and a steady hum emits from the "
		<< "tower. A blinking prompt on the screen prompts for a "
		<< "password." << endl;
	cout << endl;

	cout << "You remember the password you copied from the book "
		<< "downstairs. You punched it in and hit Enter."
		<< endl;
	cout << endl;
	cout << "A file directory appears before you, and it contains "
		<< "only 1 file called \"main.cpp\"." << endl;
	cout << "As a programmer of 20 years, you have an itch to open "
		<< "up the files and explore." << endl;
	cout << "You pulled up a chair and typed... \"vim main.cpp \"."
		<< endl;
	cout << endl;
	cout << endl;
	cout << "You see:" << endl;
	cout << endl;
	cout << "//Print the message" << endl;
	cout << endl;
	cout << "There is a snippet of code here: a + b + c + d" << endl;
	cout << endl;
	cout << "\"Print the message?\", you think to yourself. "
		<< "\"That's quite easy, as long as I remember the "
		<< "syntax...\"" << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	cout << "You barely remember your C++, but you are able"
		<< " to piece together a line to print the "
		<< "message." << endl;
	cout << endl;
	cout << "You type, \"#include <iostream>\"" << endl;
	cout << endl;
	cout << "\"That is the first step,\" you mumble."
		<< endl;
	cout << endl;
	cout << "cout << a + b + c + d;" << endl;
	cout << endl;
	cout << "\"and here we go...\". You press Enter.";
	std::chrono::seconds ptime(5);
	std::this_thread::sleep_for(ptime);	

	cout << endl;
	cout << "The project grumbles and starts up on its "
		<< "own, shooting up a beam of light into the "
		<< "dome." << endl;
	cout << endl;
	cout << "You follow the light to see the message "
		<< "displayed: " << endl;
	cout << endl;
	cout << "\"The past, like the future, is indefinite "
		<< "and exists only as a spectrum of "
		<< "possibilities.\""<< endl;
	cout << endl;
	cout << "You sigh at the Stephen Hawking quote, "
		<< "remembering everything that has happened up"
		<< " to this point. You used to wish that there"
		<< " are parallel universes for you to escape "
		<< "to. Somewhere with less pain and suffering."
		<< "A time that speaks without finality." << endl;
	cout << endl;
	cout << "When you first began your journey, you believed"
		<< " that you were looking for your Resting "
		<< "Place." << endl;
	cout << endl;
	cout << "This house, hidden somewhere within the storm, "
		<< "is a perfect place for a long sleep. Yet, "
		<< "lying supine staring at the projection, you"
		<< " feel a surge of curiosity about life, about"
		<< " what may lie ahead." << endl;
	cout << endl;
	cout << "\"Meow~\" the kitten gently licks your face. "
		<< "You feel content here, where the past, the "
		<< "present, and future collide." << endl;
	cout << endl;
	cout << "You drift off to the sweetest dreams you've "
		<< "had in years." << endl;
	cout << endl;
	cout << endl;
}


/*******************************************************************************
**				Attic::Misc
** Misc functions
*/

//void Attic::Scenario2(vector<int>& b){};
//string Attic::Scenario2a(vector<int>& b){};
//void Attic::Scenario2(vector<int>& b, bool h, bool x, bool y){};
//string Attic::Scenario3(){};
//void Attic::Secnario3(vector<int>& b){};
