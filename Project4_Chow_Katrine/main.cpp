/*******************************************************************************
** Program Name: Project 3 - Fantasy Combat Game: main.cpp
** Author: Katrine Chow
** Date: February 12, 2018
** Description:	This is the main function of the Fantasy Combat Game. It calls
**		the necessary menus and create class objects needed to run the
**		game.
*******************************************************************************/
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include "menu.hpp"
#include "die.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using namespace Menu;

int main()
{
	const char MENU1MAX = '2';
	const char MENU2MAX = '2';
	const char MENU3MAX = '5';
	const char MENU4MAX = '2';
	
	char ch = '0';

	//Seeding randomizer
	srand(time(0));

	do{
		cout << endl;

		//Display initial menu
		Menu::displayMenu1();
		char choice = Menu::getChoice(MENU1MAX);

	
		//Choice 2 to quit the program
		switch(choice)
		{
			case '1':
			{
				Menu::play();
				break;
			}
			case '2':
			{
				return 0;
			}
		}

		cout << "\n";

		Menu::displayMenu4();

		char ch2 = Menu::getChoice(MENU4MAX);
		if (ch2 == '2')
		{
			return 0;
		}
		cout << "\n";

	}while(ch == '0');

	return 0;

}
