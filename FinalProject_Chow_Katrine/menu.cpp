/*******************************************************************************
** Program Name: Final Project - Text-based Game: menu.cpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the implementation file for namespace menu, which builds
**		a menu interface for the circular program.
*******************************************************************************/

#include "menu.hpp"
#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

using namespace Menu;

/*******************************************************************************
**				Menu::displayMenu1()
** Description:	This function displays a user interface with choices.
*******************************************************************************/

void Menu::displayMenu1()
{
	cout << "Choose Wisely: " << endl;
	cout << endl;
	cout << "1) Start" << endl;
	cout << "2) Exit" << endl;
}


/*******************************************************************************
**				Menu::displayMenu2()
** Description:	This is menu 2 of program spectrum.
*******************************************************************************/
void Menu::displayMenu2()
{
	cout << "Your journey has come to an end." << endl;
	cout << endl;
	cout << "1) Play Again" << endl;
	cout << "2) Exit" << endl;

}


/*******************************************************************************
**				Menu::displayMenu3()
** Description:	This is the opening sequence of the game.
*******************************************************************************/
void Menu::displayMenu3()
{
	cout << "**********" << endl;
	cout << "20 years." << endl;
	cout << endl;
	cout << "It was 20 years ago when you celebrated with friends over "
		<< "your first corporate job." << endl;
	cout << endl;
	cout << "20 years ago when you dangled the \"New Homewoner\" keychain "
		<< "in front of your newborn child, whose little fists fought "
		<< "to grab the shiny piece." << endl;
	cout << endl;
	cout << "Your trusty computer, Mary, did not make the 20-year mark. "
		<< "She was abandoned in a corner of the basement, her power "
		<< "cord tangled with the old TV antenna and fax machine. "
		<< endl;
	cout << endl;
	cout << "**********" << endl;
	cout << endl;
	cout << "Kids are ever so curious." << endl;
	cout << endl;
	cout << "There is the good type of curious, where their heads are full "
		<< "of \"Why?\"s and their hands full of mud and bugs. " << endl;
	cout << endl;
	cout << "There is the other type, the adventurer, who wanders far and "
		<< "deep in search of treasures. " << endl;
	cout << endl;
	cout << "**********" << endl;
	cout << endl;
	cout << "The firemen later told you that the treasure had a faulty wire. "
		<< "The cops mentioned a baby gate recall. The EMTs shook their "
		<< "heads and packed up their supplies." << endl;
	cout << endl;
	cout << endl;
	cout << "**********" << endl;
	cout << endl;
	cout << "The pills barely sustain you. Your hands shook violently."<< endl;
	cout << "You gulped down the last of the whiskey. Your tongue numb to "
		<< "its taste." << endl;
	cout << "You sat on the bathroom floor sobbing, polished shoes from "
		<< "the next stall quickly stomped away." << endl;
	cout << "You stumbled over to the sink and washed your face. You "
		<< "headed back to Room 3A for your 2pm sales call." << endl;
	cout << endl;
	cout << endl;
	cout << "**********" << endl;
	cout << endl;
	cout << "\"It's not you, it's the metrics\", said your manager, who is "
		<< "8 years younger. She hands you a neatly stapled packet."
		<< endl;
	cout << "\"Oh before you go, here is your 20-year service award.\". "
		<< "She hands you a plastic pen, the type you can find in the "
		<< "dollar bin on a good day." << endl;
	cout << endl;
	cout << endl;
	cout << "**********" << endl;
	cout << endl;
	cout << "You sold the house and booked a one-way trip to the faraway "
		<< "mountains." << endl;
	cout << "You set up a base camp, and worked out a plan with Gusang, a "
		<< "local mountaineer." << endl;
	cout << "A snow storm hits. You cannot breathe." << endl;
	cout << "You see your guide tumbled out of sight." << endl;
	cout << endl;
	cout << endl;
	cout << "**********" << endl;
	cout << endl;
	cout << "You decide to trek east." << endl;
	cout << "An hour later, you come upon a seemingly abandoned house."
		<< endl;
	cout << "Knock, knock. No answer." << endl;
	cout << "You finally know the meaning of \"Chill to the bone\"."
		<< endl;
	cout << "You are tired, and hungry." << endl;
	cout << "You decide to enter the house." << endl;
	cout << endl;
	cout << endl;
	cout << endl;


}


/*******************************************************************************
**			Menu::displayMenuMH1()
** Description:	Menu for Mainhall's Scenario 1.
*******************************************************************************/
/*void Menu::displayMenuMH1()
{
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
        cout << "5) Examine the Toolbox" << endl;
        cout << "6) Examine the Fireplace" << endl;
        cout << "7) Check the Map" << endl;
        cout << "8) Exit the Main Hall" << endl;
}

*/
/*******************************************************************************
**			char Menu:getChoice(char)
** Description:	This function collects user's choice.
*******************************************************************************/

char Menu::getChoice(char max)
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
**			int Menu::intValidation(string)
** Description:	This function serves as input validation for integers. I
**		references SkyeShatter's YouTube video at:
**		https://youtube.com/watch?v=S3_jCTb3fm0  , as well as @86 on
**		Piazza.
*******************************************************************************/

int Menu::intValidation(string s)
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
