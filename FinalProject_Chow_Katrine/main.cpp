/*******************************************************************************
** Program Name: FinalProject - Text-based Game: main.cpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the client code of text game Spectrum. This controls
**		the flow of menus and function calls.
*******************************************************************************/
#include <iostream>
#include <string>

#include "space.hpp"
#include "game.hpp"
#include "player.hpp"
#include "menu.hpp"

using namespace Menu;

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	const char MENU1MAX = '2';
	const char MENU2MAX = '2';
	char ch = '0';

	//Declares Game object
	Game spectrum;

	cout << endl;
	cout << endl;
	cout << endl;

	cout <<
	
                  " +-----------------------------------+\n"
                  " | +-------------------------------+ |\n"
                  " | |         *         *        *  | |\n"
                  " | |   *                     *     | |\n"
                  " | |       *        *              | |\n"
                  " | |           SPECTRUM         *  | |\n"
                  " | |  *                   *        | |\n"
                  " | |       *                      *| |\n"
                  " | |  Copyright Katrine Chow 2018  | |\n"
                  " | +-------------------------------+ |\n"
                  " +-----------------------------------+\n";
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Spectrum is a text-based journey that asks you to " << endl;
	cout << "solve a series of puzzles by examining your " << endl;
	cout << "environment and collecting tools and items." << endl;
	cout << endl;
	cout << "As you traverse through each space, be sure to " << endl;
	cout << "stop and look through all the nooks and crannies. " << endl;
	cout << "You may be rewarded with a nice surprise!" << endl;
	cout << endl;
	cout << "Unlock the secret of the house once you've collected" << endl;
	cout << " all the necessary items." << endl;
	cout << endl;
	cout << "Oh, and do it before your body temp drops to zero!" << endl;	


	do{
		//Display first menu
		Menu::displayMenu1();
		char choice = Menu::getChoice(MENU1MAX);

		//Redirecting various menu choices
		switch (choice)
		{
			case '1':
			{
				Menu::displayMenu3();
				int signal = spectrum.playGame();
				if (signal == 7)
				{
					break;
				}
				break;
			}
			case '2':
			{
				return 0;
			}
		}

		Menu::displayMenu2();
//		cin.ignore();

		char ch2 = Menu::getChoice(MENU2MAX);
		cout << endl;

		if(ch2 == '2')
		{
			return 0;
		}

	}while(ch == '0');

	return 0;
}
